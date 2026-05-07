#!/usr/bin/env python3
"""Auto-align a source 2D occupancy-grid map to a reference map.

Computes the (dyaw, dx, dy) rigid transformation that best aligns the
source map's obstacle pixels to the reference map's obstacle pixels.

Pipeline:
1. Load both maps (yaml + .pgm/.png) and extract obstacle pixel world
   coordinates (using each map's own resolution + origin).
2. Coarse search over yaw (-180° to 180° in 5° steps), aligning by
   centroid for translation, scoring by % of source obstacles within
   `match_distance` of any reference obstacle.
3. Fine search around the best yaw (±5° in 0.5° steps).
4. Refine translation with one ICP-like step using nearest-neighbor
   correspondences from the best (dyaw, dx, dy).
5. Output the result. Optionally invoke
   `hero_to_sentry_map_converter.py` directly to apply the transform.

Dependencies: numpy, scipy, PIL (all available with ROS Humble).

Usage examples
--------------
    # Just compute and print the transform:
    python3 auto_align_map.py \\
        --source <your map.yaml> \\
        --reference <rmuc_2026.yaml>

    # Compute and immediately apply it (calls the converter for you):
    python3 auto_align_map.py \\
        --source <your map.yaml> \\
        --source-pcd <your scans.pcd> \\
        --reference <rmuc_2026.yaml> \\
        --apply
"""

from __future__ import annotations

import argparse
import json
import math
import subprocess
import sys
from datetime import datetime
from pathlib import Path
from typing import Tuple

import numpy as np
import yaml
from PIL import Image
from scipy.spatial import cKDTree


# ---------- Map loading ----------

def load_obstacle_points_world(yaml_path: Path) -> Tuple[np.ndarray, dict]:
    """Read map.yaml + image, return Nx2 array of obstacle world (x, y).

    Convention (nav2 standard):
    - .pgm pixel value low = occupied, high = free.
    - origin = [ox, oy, oyaw]: world pose of the **lower-left** pixel.
    - Pixel (col, row=H-1) maps to world origin (with yaw rotation).
    """
    yaml_path = Path(yaml_path).expanduser().resolve()
    with yaml_path.open("r", encoding="utf-8") as f:
        meta = yaml.safe_load(f)

    image_field = meta.get("image")
    if not image_field:
        raise ValueError(f"map yaml missing 'image': {yaml_path}")
    image_path = (yaml_path.parent / str(image_field)).resolve()
    if not image_path.exists():
        raise FileNotFoundError(f"map image not found: {image_path}")

    img = np.array(Image.open(image_path).convert("L"))  # uint8 H x W
    h, w = img.shape

    resolution = float(meta.get("resolution", 0.05))
    origin = list(meta.get("origin", [0.0, 0.0, 0.0]))
    while len(origin) < 3:
        origin.append(0.0)
    ox, oy, oyaw = float(origin[0]), float(origin[1]), float(origin[2])

    occupied_thresh = float(meta.get("occupied_thresh", 0.65))
    negate = int(meta.get("negate", 0))

    # In nav2: occupancy = (255 - pixel_value) / 255 if not negated
    if negate:
        occupancy = img.astype(np.float32) / 255.0
    else:
        occupancy = 1.0 - img.astype(np.float32) / 255.0
    obstacle_mask = occupancy > occupied_thresh

    ys, xs = np.where(obstacle_mask)
    if len(xs) == 0:
        raise ValueError(f"map has no obstacle pixels: {yaml_path}")

    # Pixel -> local map coords (lower-left = origin):
    local_x = xs.astype(np.float64) * resolution
    local_y = (h - 1 - ys).astype(np.float64) * resolution

    # Apply origin yaw + translation -> world coords
    c, s = math.cos(oyaw), math.sin(oyaw)
    world_x = c * local_x - s * local_y + ox
    world_y = s * local_x + c * local_y + oy

    pts = np.stack([world_x, world_y], axis=1)
    return pts, {
        "yaml_path": str(yaml_path),
        "image_path": str(image_path),
        "resolution": resolution,
        "origin": [ox, oy, oyaw],
        "shape": (h, w),
        "n_obstacles": int(len(xs)),
    }


# ---------- Alignment ----------

def apply_yaw_xy(pts: np.ndarray, dyaw: float, dx: float, dy: float) -> np.ndarray:
    c, s = math.cos(dyaw), math.sin(dyaw)
    rx = c * pts[:, 0] - s * pts[:, 1] + dx
    ry = s * pts[:, 0] + c * pts[:, 1] + dy
    return np.stack([rx, ry], axis=1)


def overlap_score(
    src_pts: np.ndarray, ref_tree: cKDTree, match_distance: float,
) -> Tuple[float, float]:
    """Return (fraction_within_match_distance, mean_distance_for_inliers)."""
    distances, _ = ref_tree.query(src_pts, k=1)
    inlier = distances < match_distance
    frac = float(np.mean(inlier))
    if inlier.any():
        mean_d = float(np.mean(distances[inlier]))
    else:
        mean_d = float("inf")
    return frac, mean_d


def bidirectional_score(
    transformed_src_pts: np.ndarray,
    ref_pts: np.ndarray,
    match_distance: float,
) -> dict:
    """Compute forward + reverse inlier fractions.

    forward: fraction of transformed_src points that find a ref neighbor
             within match_distance. (Original `overlap_score`.)
    reverse: fraction of ref points that find a transformed_src neighbor
             within match_distance.

    A high forward + low reverse means src is a small subset of ref —
    your alignment is unconstrained on the parts of ref that src doesn't
    cover, and the result may be a spurious local optimum.

    The min(forward, reverse) is the honest quality score.
    """
    ref_tree = cKDTree(ref_pts)
    fwd_dist, _ = ref_tree.query(transformed_src_pts, k=1)
    fwd_inlier = fwd_dist < match_distance
    fwd_frac = float(np.mean(fwd_inlier))
    fwd_mean = float(np.mean(fwd_dist[fwd_inlier])) if fwd_inlier.any() else float("inf")

    src_tree = cKDTree(transformed_src_pts)
    rev_dist, _ = src_tree.query(ref_pts, k=1)
    rev_inlier = rev_dist < match_distance
    rev_frac = float(np.mean(rev_inlier))
    rev_mean = float(np.mean(rev_dist[rev_inlier])) if rev_inlier.any() else float("inf")

    return {
        "forward_inlier_fraction": fwd_frac,
        "forward_mean_distance_m": fwd_mean,
        "reverse_inlier_fraction": rev_frac,
        "reverse_mean_distance_m": rev_mean,
        "bidirectional_score": min(fwd_frac, rev_frac),
    }


def downsample_voxel_2d(pts: np.ndarray, voxel: float) -> np.ndarray:
    """Keep one representative point per voxel of size `voxel`.

    Uses the **centroid** of points in each voxel as the representative.
    This makes the result invariant to point ordering, and unbiased under
    rotation/translation: src and ref voxelizations agree on the same
    sub-voxel position regardless of which actual pixels happened to fall
    in that voxel.
    """
    if len(pts) == 0:
        return pts
    keys = np.floor(pts / voxel).astype(np.int64)
    _, inverse = np.unique(keys, axis=0, return_inverse=True)
    n_groups = inverse.max() + 1
    sums = np.zeros((n_groups, 2), dtype=np.float64)
    counts = np.zeros(n_groups, dtype=np.int64)
    np.add.at(sums, inverse, pts)
    np.add.at(counts, inverse, 1)
    return sums / counts[:, None]


def search_alignment(
    src_pts: np.ndarray,
    ref_pts: np.ndarray,
    coarse_step_deg: float = 5.0,
    fine_step_deg: float = 0.5,
    fine_window_deg: float = 5.0,
    match_distance: float = 0.30,
    voxel_size: float = 0.20,
    yaw_only: bool = False,
    initial_guess: Tuple[float, float, float] | None = None,
) -> dict:
    """Coarse-to-fine search over (dyaw, dx, dy).

    If `initial_guess = (dx0, dy0, dyaw0)` is provided, it is used as the
    starting point: coarse search becomes a tight ±fine_window_deg sweep
    around dyaw0 with translation pinned to (dx0, dy0). ICP refinement
    then takes over from there. This is dramatically more robust than
    centroid alignment when the source map covers only a small part of
    the reference (e.g. SLAM only saw a corner of the field).
    """
    # Downsample for speed
    src_ds = downsample_voxel_2d(src_pts, voxel_size)
    ref_ds = downsample_voxel_2d(ref_pts, voxel_size)
    ref_tree = cKDTree(ref_ds)

    src_centroid = src_ds.mean(axis=0)
    ref_centroid = ref_ds.mean(axis=0)

    def evaluate_centroid(dyaw: float) -> Tuple[float, float, float, float, float]:
        # Rotate source around its own centroid, then translate so its
        # centroid lands on ref_centroid. Used when no initial guess is given.
        c, s = math.cos(dyaw), math.sin(dyaw)
        rotated_centroid = np.array([
            c * src_centroid[0] - s * src_centroid[1],
            s * src_centroid[0] + c * src_centroid[1],
        ])
        T = ref_centroid - rotated_centroid
        translated = apply_yaw_xy(src_ds, dyaw, float(T[0]), float(T[1]))
        frac, mean_d = overlap_score(translated, ref_tree, match_distance)
        return frac, mean_d, float(T[0]), float(T[1]), dyaw

    def evaluate_fixed_xy(dyaw: float, dx0: float, dy0: float) -> Tuple[float, float, float, float, float]:
        # Use the user-supplied translation directly.
        translated = apply_yaw_xy(src_ds, dyaw, dx0, dy0)
        frac, mean_d = overlap_score(translated, ref_tree, match_distance)
        return frac, mean_d, dx0, dy0, dyaw

    if initial_guess is not None:
        dx0, dy0, dyaw0 = initial_guess
        print(f"  [seeded] initial guess: dx={dx0:.3f} dy={dy0:.3f} "
              f"dyaw={math.degrees(dyaw0):.2f}° "
              f"(skipping global coarse search)")
        # Sweep yaw in a window around the supplied dyaw0, translation pinned.
        win = max(fine_window_deg, 10.0)
        sweep_yaws = np.deg2rad(
            np.arange(
                math.degrees(dyaw0) - win,
                math.degrees(dyaw0) + win + 1e-9,
                fine_step_deg,
            )
        ).tolist()
        coarse_results = [evaluate_fixed_xy(y, dx0, dy0) for y in sweep_yaws]
        coarse_results.sort(key=lambda r: (-r[0], r[1]))
        best = coarse_results[0]
        print(f"  [seeded best] yaw={math.degrees(best[4]):.4f}° "
              f"frac={best[0]*100:.1f}% "
              f"mean_d={best[1]:.3f}m  T=({best[2]:.3f}, {best[3]:.3f})")
    else:
        print("  [coarse search] yaw range -180..180 step",
              f"{coarse_step_deg}°...")

        if yaw_only:
            # Force dyaw = 0 only — useful when you're sure no rotation needed.
            coarse_yaws = [0.0]
        else:
            coarse_yaws = np.deg2rad(
                np.arange(-180.0, 180.0, coarse_step_deg)
            ).tolist()

        coarse_results = [evaluate_centroid(y) for y in coarse_yaws]
        coarse_results.sort(key=lambda r: (-r[0], r[1]))
        best = coarse_results[0]
        print(f"  [coarse best] yaw={math.degrees(best[4]):.2f}° "
              f"frac={best[0]*100:.1f}% "
              f"mean_d={best[1]:.3f}m  T=({best[2]:.3f}, {best[3]:.3f})")

        # Fine search around best
        if not yaw_only:
            center_deg = math.degrees(best[4])
            fine_yaws = np.deg2rad(
                np.arange(
                    center_deg - fine_window_deg,
                    center_deg + fine_window_deg + 1e-9,
                    fine_step_deg,
                )
            ).tolist()
            print(f"  [fine search] yaw range "
                  f"{center_deg - fine_window_deg:.2f}..{center_deg + fine_window_deg:.2f}° "
                  f"step {fine_step_deg}°...")
            fine_results = [evaluate_centroid(y) for y in fine_yaws]
            fine_results.sort(key=lambda r: (-r[0], r[1]))
            fbest = fine_results[0]
            if (fbest[0], -fbest[1]) > (best[0], -best[1]):
                best = fbest
                print(f"  [fine best] yaw={math.degrees(best[4]):.2f}° "
                      f"frac={best[0]*100:.1f}% "
                      f"mean_d={best[1]:.3f}m  T=({best[2]:.3f}, {best[3]:.3f})")

    # Iterative ICP refinement: find nearest neighbors and recompute the
    # best rigid transform from inlier pairs. Repeat until the update is
    # smaller than the convergence threshold or the result stops improving.
    # This pushes precision well below the fine_step_deg granularity.
    dyaw, T0, T1 = best[4], best[2], best[3]
    icp_max_iter = 30
    icp_tol_yaw = math.radians(0.001)  # 0.001°
    icp_tol_t = 1e-4                   # 0.1 mm

    for it in range(icp_max_iter):
        transformed = apply_yaw_xy(src_ds, dyaw, T0, T1)
        distances, indices = ref_tree.query(transformed, k=1)
        inlier_mask = distances < match_distance
        if inlier_mask.sum() < 10:
            break
        src_inl = src_ds[inlier_mask]
        ref_inl = ref_ds[indices[inlier_mask]]
        sc = src_inl.mean(axis=0)
        rc = ref_inl.mean(axis=0)
        sc_pts = src_inl - sc
        rc_pts = ref_inl - rc
        H = sc_pts.T @ rc_pts
        U, _, Vt = np.linalg.svd(H)
        R = Vt.T @ U.T
        if np.linalg.det(R) < 0:
            Vt[1, :] *= -1
            R = Vt.T @ U.T
        new_dyaw = math.atan2(R[1, 0], R[0, 0])
        new_T = rc - R @ sc
        new_T0, new_T1 = float(new_T[0]), float(new_T[1])

        # Convergence test
        d_yaw = abs(new_dyaw - dyaw)
        # wrap to [0, pi]
        while d_yaw > math.pi:
            d_yaw = abs(d_yaw - 2 * math.pi)
        d_t = math.hypot(new_T0 - T0, new_T1 - T1)

        new_frac, new_mean_d = overlap_score(
            apply_yaw_xy(src_ds, new_dyaw, new_T0, new_T1),
            ref_tree, match_distance,
        )
        # Accept if it improves; otherwise stop
        if (new_frac, -new_mean_d) >= (best[0], -best[1]):
            best = (new_frac, new_mean_d, new_T0, new_T1, new_dyaw)
            dyaw, T0, T1 = new_dyaw, new_T0, new_T1
        else:
            break
        if d_yaw < icp_tol_yaw and d_t < icp_tol_t:
            break

    print(f"  [ICP refined] yaw={math.degrees(best[4]):.4f}° "
          f"frac={best[0]*100:.1f}% "
          f"mean_d={best[1]:.4f}m  T=({best[2]:.4f}, {best[3]:.4f})  "
          f"iters={it+1}")

    # Final polish: one ICP pass at FULL resolution (no voxel downsampling).
    # The voxel grid limits precision to ~voxel_size; the full-resolution
    # pass squeezes accuracy down to the pixel resolution of the input maps.
    full_ref_tree = cKDTree(ref_pts)
    dyaw, T0, T1 = best[4], best[2], best[3]
    for it_full in range(10):
        transformed = apply_yaw_xy(src_pts, dyaw, T0, T1)
        distances, indices = full_ref_tree.query(transformed, k=1)
        inlier_mask = distances < match_distance
        if inlier_mask.sum() < 10:
            break
        src_inl = src_pts[inlier_mask]
        ref_inl = ref_pts[indices[inlier_mask]]
        sc = src_inl.mean(axis=0)
        rc = ref_inl.mean(axis=0)
        H = (src_inl - sc).T @ (ref_inl - rc)
        U, _, Vt = np.linalg.svd(H)
        R = Vt.T @ U.T
        if np.linalg.det(R) < 0:
            Vt[1, :] *= -1
            R = Vt.T @ U.T
        new_dyaw = math.atan2(R[1, 0], R[0, 0])
        new_T = rc - R @ sc
        new_T0, new_T1 = float(new_T[0]), float(new_T[1])
        d_yaw = abs(new_dyaw - dyaw)
        while d_yaw > math.pi:
            d_yaw = abs(d_yaw - 2 * math.pi)
        d_t = math.hypot(new_T0 - T0, new_T1 - T1)
        new_frac, new_mean_d = overlap_score(
            apply_yaw_xy(src_pts, new_dyaw, new_T0, new_T1),
            full_ref_tree, match_distance,
        )
        if (new_frac, -new_mean_d) >= (best[0], -best[1]):
            best = (new_frac, new_mean_d, new_T0, new_T1, new_dyaw)
            dyaw, T0, T1 = new_dyaw, new_T0, new_T1
        else:
            break
        if d_yaw < icp_tol_yaw and d_t < icp_tol_t:
            break

    print(f"  [full-res polish] yaw={math.degrees(best[4]):.4f}° "
          f"frac={best[0]*100:.1f}% "
          f"mean_d={best[1]:.4f}m  T=({best[2]:.4f}, {best[3]:.4f})  "
          f"iters={it_full+1}")

    return {
        "dyaw_rad": best[4],
        "dyaw_deg": math.degrees(best[4]),
        "dx": best[2],
        "dy": best[3],
        "inlier_fraction": best[0],
        "mean_inlier_distance_m": best[1],
        "match_distance_m": match_distance,
        "voxel_size_m": voxel_size,
    }


# ---------- Main ----------

def parse_args() -> argparse.Namespace:
    p = argparse.ArgumentParser(
        description=(
            "Auto-align a source 2D map to a reference 2D map. Outputs "
            "(dyaw, dx, dy) for use with hero_to_sentry_map_converter.py."
        )
    )
    p.add_argument("--source", required=True,
                   help="path to source map.yaml (the one to be aligned)")
    p.add_argument("--reference", required=True,
                   help="path to reference map.yaml (the one to align to)")
    p.add_argument("--source-pcd", default="",
                   help="(optional) source scans.pcd; only needed if --apply is set")
    p.add_argument("--match-distance", type=float, default=0.30,
                   help="match distance threshold in meters (default 0.30 m)")
    p.add_argument("--voxel-size", type=float, default=0.20,
                   help="voxel downsample size in meters (default 0.20 m)")
    p.add_argument("--coarse-step-deg", type=float, default=5.0,
                   help="coarse yaw search step in degrees (default 5)")
    p.add_argument("--fine-step-deg", type=float, default=0.5,
                   help="fine yaw search step in degrees (default 0.5)")
    p.add_argument("--fine-window-deg", type=float, default=5.0,
                   help="fine yaw search window (±) in degrees around coarse best (default 5)")
    p.add_argument("--yaw-only-zero", action="store_true",
                   help="skip yaw search; only solve for translation with dyaw=0")
    p.add_argument("--slam-origin-in-target",
                   nargs=3, metavar=("X", "Y", "YAW_DEG"), default=None,
                   help=(
                       "Initial guess for the SLAM origin's pose in the "
                       "reference (target) frame. Three numbers: X (m), Y (m), "
                       "YAW (degrees). When provided, the search skips the "
                       "global coarse stage and is seeded with this guess "
                       "(massively more robust when the source map covers "
                       "only a small part of the reference). Example: in sim, "
                       "if the robot spawns at world (4.4, 9.5, 0°) and SLAM "
                       "starts there, pass `--slam-origin-in-target 4.4 9.5 0`."
                   ))
    p.add_argument("--save-report",
                   default="auto_align_report.json",
                   help="path to write a JSON report (default: ./auto_align_report.json)")
    p.add_argument("--apply", action="store_true",
                   help="after computing, immediately invoke "
                        "hero_to_sentry_map_converter.py with the result")
    p.add_argument("--apply-output-folder", default="",
                   help="(with --apply) output folder name passed to the converter")
    p.add_argument("--converter-script", default="",
                   help="path to converter script (default: same dir as this script)")
    return p.parse_args()


def main() -> int:
    args = parse_args()

    print("=" * 60)
    print("[1/4] Loading source map …")
    src_pts, src_meta = load_obstacle_points_world(Path(args.source))
    print(f"    {src_meta['yaml_path']}")
    print(f"    {src_meta['n_obstacles']} obstacle pixels, "
          f"shape {src_meta['shape']}, res {src_meta['resolution']} m")

    print("[2/4] Loading reference map …")
    ref_pts, ref_meta = load_obstacle_points_world(Path(args.reference))
    print(f"    {ref_meta['yaml_path']}")
    print(f"    {ref_meta['n_obstacles']} obstacle pixels, "
          f"shape {ref_meta['shape']}, res {ref_meta['resolution']} m")

    print("[3/4] Searching for best (dyaw, dx, dy) …")
    initial_guess = None
    if args.slam_origin_in_target is not None:
        gx, gy, gyaw_deg = args.slam_origin_in_target
        initial_guess = (float(gx), float(gy), math.radians(float(gyaw_deg)))

    result = search_alignment(
        src_pts, ref_pts,
        coarse_step_deg=args.coarse_step_deg,
        fine_step_deg=args.fine_step_deg,
        fine_window_deg=args.fine_window_deg,
        match_distance=args.match_distance,
        voxel_size=args.voxel_size,
        yaw_only=args.yaw_only_zero,
        initial_guess=initial_guess,
    )

    # Bidirectional sanity check: forward score (used during search) only
    # asks "did src find a neighbor in ref?". If src is a small subset of
    # ref, that's trivially yes everywhere — including spurious local
    # optima. Reverse score asks "did ref find a neighbor in src?" and
    # exposes the imbalance.
    transformed_src = apply_yaw_xy(src_pts, result["dyaw_rad"], result["dx"], result["dy"])
    bi = bidirectional_score(transformed_src, ref_pts, args.match_distance)
    result.update(bi)

    print()
    print("=" * 60)
    print("[结果] Auto-alignment finished")
    print(f"  dyaw         = {result['dyaw_deg']:.4f}°  "
          f"({result['dyaw_rad']:.6f} rad)")
    print(f"  dx           = {result['dx']:.4f} m")
    print(f"  dy           = {result['dy']:.4f} m")
    print(f"  forward inl  = {bi['forward_inlier_fraction']*100:.2f}%  "
          f"(src→ref)")
    print(f"  reverse inl  = {bi['reverse_inlier_fraction']*100:.2f}%  "
          f"(ref→src)")
    print(f"  bidirectional= {bi['bidirectional_score']*100:.2f}%  "
          f"(min of the two — the honest score)")
    print(f"  inlier mean  = {result['mean_inlier_distance_m']:.4f} m")
    print()

    # Quality hint — now based on bidirectional score, not just forward.
    bid = bi["bidirectional_score"]
    fwd = bi["forward_inlier_fraction"]
    rev = bi["reverse_inlier_fraction"]
    if bid < 0.30:
        print("  ⚠️  Low bidirectional score. The two maps may not actually share")
        print("      the same scene, or you're stuck in a local optimum.")
        print("      Check the output before applying.")
    elif bid < 0.60:
        print("  ⚠️  Modest bidirectional score. Result is plausible but verify in RViz.")
    else:
        print("  ✅ Good bidirectional score. Result should be reliable.")

    if fwd - rev > 0.30:
        print()
        print("  ⚠️  Forward >> Reverse: your source map covers only a small part")
        print("      of the reference. The alignment is unconstrained on the parts")
        print("      of the reference your SLAM didn't cover — the result may be")
        print("      a spurious local optimum even if the forward score looks good.")
        print("      Tip: pass --slam-origin-in-target X Y YAW to seed the search")
        print("      with a known initial guess (e.g. your robot's spawn point).")

    # Suspicious-pattern warning: yaw very close to ±90° / ±180° AND large
    # translation often means we landed on a centroid-aligned local optimum.
    yaw_deg = abs(((result["dyaw_deg"] + 180) % 360) - 180)
    near_int = min(abs(yaw_deg - k) for k in (0, 90, 180))
    big_trans = math.hypot(result["dx"], result["dy"]) > 5.0
    if near_int < 0.5 and big_trans:
        print()
        print("  ⚠️  yaw is suspiciously close to an integer multiple of 90° and the")
        print("      translation is large (>5 m). This pattern often indicates a")
        print("      centroid-driven local optimum. Sanity-check by overlaying the")
        print("      converted map on the reference in RViz before trusting it.")
    print()

    # Save report
    # Same logic as the converter: a robot starting at SLAM origin (0,0,0)
    # ends up at (dx, dy, dyaw) in the converted/reference frame.
    new_init_yaw = result["dyaw_rad"]
    # wrap to (-pi, pi]
    while new_init_yaw > math.pi:
        new_init_yaw -= 2 * math.pi
    while new_init_yaw <= -math.pi:
        new_init_yaw += 2 * math.pi
    init_pose_snippet = (
        f"init_pose: [{result['dx']:.6f}, {result['dy']:.6f}, "
        f"0.0, 0.0, 0.0, {new_init_yaw:.6f}]"
    )

    report = {
        "created_at": datetime.now().isoformat(),
        "source": src_meta,
        "reference": ref_meta,
        "search_params": {
            "coarse_step_deg": args.coarse_step_deg,
            "fine_step_deg": args.fine_step_deg,
            "fine_window_deg": args.fine_window_deg,
            "match_distance_m": args.match_distance,
            "voxel_size_m": args.voxel_size,
            "yaw_only_zero": args.yaw_only_zero,
            "slam_origin_in_target": (
                list(args.slam_origin_in_target)
                if args.slam_origin_in_target is not None else None
            ),
        },
        "result": result,
        "new_init_pose": {
            "x": result["dx"],
            "y": result["dy"],
            "z": 0.0,
            "roll": 0.0,
            "pitch": 0.0,
            "yaw_rad": new_init_yaw,
            "yaw_deg": math.degrees(new_init_yaw),
            "yaml_snippet": init_pose_snippet,
            "comment": (
                "Robot's pose in the converted (reference) frame, assuming "
                "it starts at the same physical spot where the source SLAM "
                "session began. Paste yaml_snippet into nav2_params.yaml."
            ),
        },
        "to_apply_with_converter": (
            f"python3 hero_to_sentry_map_converter.py --no-interactive "
            f"--hero-map-yaml {args.source} "
            f"--hero-pcd <YOUR_PCD_PATH> "
            f"--dyaw {result['dyaw_rad']} "
            f"--dx {result['dx']} --dy {result['dy']} "
            f"--output-folder-name aligned --force"
        ),
    }

    report_path = Path(args.save_report).expanduser().resolve()
    report_path.parent.mkdir(parents=True, exist_ok=True)
    with report_path.open("w", encoding="utf-8") as f:
        json.dump(report, f, indent=2, ensure_ascii=False)
    print(f"[4/4] Report saved to: {report_path}")

    print()
    print("=" * 60)
    print("[init_pose] If you launch nav2 with the converted map, set:")
    print(f"    {init_pose_snippet}")
    print("(Assumes the robot now starts at the same physical spot where")
    print(" you began the SLAM recording. If not, adjust accordingly or")
    print(" use RViz '2D Pose Estimate' at runtime.)")
    print("=" * 60)

    if args.apply:
        if not args.source_pcd:
            print("\n[ERROR] --apply requires --source-pcd")
            return 2
        converter = (
            Path(args.converter_script).expanduser().resolve()
            if args.converter_script
            else Path(__file__).resolve().parent / "hero_to_sentry_map_converter.py"
        )
        if not converter.exists():
            print(f"\n[ERROR] converter script not found: {converter}")
            return 3
        out_name = args.apply_output_folder or \
            f"auto_aligned_{datetime.now().strftime('%Y%m%d_%H%M%S')}"
        cmd = [
            sys.executable, str(converter), "--no-interactive",
            "--hero-map-yaml", args.source,
            "--hero-pcd", args.source_pcd,
            "--dyaw", str(result["dyaw_rad"]),
            "--dx", str(result["dx"]),
            "--dy", str(result["dy"]),
            "--output-folder-name", out_name,
            "--force",
        ]
        print("\n[apply] Invoking converter:")
        print("  " + " ".join(cmd))
        rc = subprocess.call(cmd)
        if rc != 0:
            print(f"\n[ERROR] converter exited with code {rc}")
            return rc

    return 0


if __name__ == "__main__":
    raise SystemExit(main())
