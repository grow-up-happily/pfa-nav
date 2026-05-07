#!/usr/bin/env python3
"""Map converter: apply a 2D rigid transformation (yaw + xy) to a 2D
occupancy-grid map.yaml/.pgm and a 3D point cloud .pcd.

Why only yaw + xy?
------------------
This is the only transformation that is meaningful for both 2D occupancy
grids (horizontal slices of the world) and 3D PCDs (assuming a shared
gravity-aligned z-up convention, which point_lio / FAST-LIO etc. produce).

For SLAM systems that gravity-align the map frame, lidar mount
roll/pitch differences are absorbed inside SLAM and never appear in the
saved map/PCD. The only between-robot/between-session difference that
remains is yaw + xy of the starting pose.

Inputs
------
- A source map.yaml (with associated .pgm/.png in the same directory)
- A source scans.pcd (binary or ascii, with float x/y/z fields)
- dyaw (radians or degrees), dx (meters), dy (meters)

Output
------
A folder containing:
- source_assets/   (untouched copies for reference)
- converted_assets/  (rotated+translated map.yaml, map.pgm, scans.pcd)
- metadata.json   (records exactly what transform was applied)

Modes
-----
Interactive (default): runs a Q&A.
Non-interactive (--no-interactive): pass everything as CLI args.

If you don't know dyaw/dx/dy, run `auto_align_map.py` first to compute
them from a reference map, then plug those numbers in here.
"""

from __future__ import annotations

import argparse
import json
import math
import shutil
import struct
from datetime import datetime
from pathlib import Path
from typing import Dict, List, Sequence, Tuple

import yaml


# ---------- Math helpers ----------

def normalize_angle(a: float) -> float:
    while a > math.pi:
        a -= 2.0 * math.pi
    while a <= -math.pi:
        a += 2.0 * math.pi
    return a


# ---------- Angle expression parsing ----------

ANGLE_EVAL_NAMES = {
    "pi": math.pi,
    "PI": math.pi,
    "Pi": math.pi,
    "tau": 2 * math.pi,
    "e": math.e,
}


def parse_angle_expr(s: str) -> float:
    """Evaluate angle expression: 'pi', 'pi/2', '-pi/2', '0.5', '2*pi'."""
    s = s.strip()
    if not s:
        raise ValueError("empty angle")
    try:
        return float(eval(s, {"__builtins__": {}}, ANGLE_EVAL_NAMES))  # noqa: S307
    except Exception as exc:
        raise ValueError(f"cannot parse angle expression: {s!r} ({exc})") from exc


def parse_angle_or_deg(s: str) -> float:
    """Parse angle. Trailing 'deg'/'°' triggers degree-to-radian conversion.

    'pi/2' -> 1.5708, '90 deg' -> 1.5708, '90°' -> 1.5708, '1.5708' -> 1.5708
    """
    t = s.strip()
    is_deg = False
    for suffix in ("deg", "Deg", "DEG", "°"):
        if t.endswith(suffix):
            t = t[: -len(suffix)].strip()
            is_deg = True
            break
    val = parse_angle_expr(t)
    return math.radians(val) if is_deg else val


def parse_float(s: str, default: float = 0.0) -> float:
    """Parse a number that may also be an expression like 'pi/2'."""
    if not s:
        return default
    try:
        return float(parse_angle_expr(s))
    except Exception:
        return float(s)


# ---------- Prompt helpers ----------

def prompt_text(prompt: str, default: str = "") -> str:
    if default:
        raw = input(f"{prompt} [{default}]: ").strip()
        return raw if raw else default
    return input(f"{prompt}: ").strip()


def prompt_angle_or_deg(prompt: str, default: str = "") -> float:
    while True:
        raw = prompt_text(prompt, default)
        try:
            return parse_angle_or_deg(raw)
        except Exception as exc:  # noqa: BLE001
            print(f"[输入错误] {exc}")


def prompt_number(prompt: str, default: str = "0") -> float:
    while True:
        raw = prompt_text(prompt, default)
        try:
            return parse_float(raw)
        except Exception as exc:  # noqa: BLE001
            print(f"[输入错误] {exc}")


# ---------- 2D map yaml + image ----------

def resolve_map_image(map_yaml_path: Path, map_yaml: Dict) -> Path:
    image_field = map_yaml.get("image")
    if not image_field:
        raise ValueError(f"map yaml missing 'image': {map_yaml_path}")
    image_path = (map_yaml_path.parent / str(image_field)).resolve()
    if not image_path.exists():
        raise FileNotFoundError(f"map image not found: {image_path}")
    return image_path


def transform_pgm_image(
    src_image_path: Path,
    dst_image_path: Path,
    dyaw: float,
    tx: float,
    ty: float,
    resolution: float,
    src_origin_xy: Tuple[float, float],
    unknown_value: int = 205,
) -> Tuple[int, int, float, float]:
    """Bake an Rz(dyaw)+(tx,ty) rigid motion into the .pgm pixels themselves.

    nav2 map_server's behavior with a non-zero `origin` yaw is unreliable
    across versions / RViz combos. So instead of writing a rotated yaw into
    the yaml and hoping the consumer rotates the image, we pre-rotate the
    image bytes here and emit a yaml whose origin yaw is 0. The PCD gets
    the same rigid motion baked in elsewhere, keeping them mutually
    consistent.

    Implementation: inverse warp. For each pixel of the destination image,
    compute its world position, invert (Rz, translate) to find the source
    world position, find the source pixel by nearest neighbor (no
    interpolation -- occupancy values are categorical, not continuous).

    Returns (new_W, new_H, new_origin_x, new_origin_y). new_origin yaw is
    always 0 by construction; the caller should write that into the yaml.
    """
    from PIL import Image
    import numpy as np

    src = np.array(Image.open(src_image_path).convert("L"))
    H, W = src.shape
    ox, oy = src_origin_xy
    r = float(resolution)

    cs = math.cos(dyaw)
    sn = math.sin(dyaw)

    # World-frame corners of the original image (BL, BR, TL, TR).
    corners = np.array([
        [ox,         oy        ],
        [ox + W * r, oy        ],
        [ox,         oy + H * r],
        [ox + W * r, oy + H * r],
    ], dtype=np.float64)
    # Apply Rz(dyaw) + (tx, ty)
    R = np.array([[cs, -sn], [sn, cs]])
    new_corners = corners @ R.T + np.array([tx, ty])

    new_x_min = float(new_corners[:, 0].min())
    new_y_min = float(new_corners[:, 1].min())
    new_x_max = float(new_corners[:, 0].max())
    new_y_max = float(new_corners[:, 1].max())

    new_W = int(round((new_x_max - new_x_min) / r))
    new_H = int(round((new_y_max - new_y_min) / r))
    if new_W <= 0 or new_H <= 0:
        raise ValueError(
            f"transformed pgm has non-positive dimensions: {new_W}x{new_H}"
        )

    new_ox = new_x_min
    new_oy = new_y_min

    # Build (col, row) grids for the destination image.
    cols = np.arange(new_W)
    rows = np.arange(new_H)
    cc, rr = np.meshgrid(cols, rows)
    # World position of destination pixel (col, row) under yaml conventions:
    #   x = origin_x + col * r
    #   y = origin_y + (H - 1 - row) * r       (image rows grow downward)
    wx = new_ox + cc * r
    wy = new_oy + (new_H - 1 - rr) * r

    # Inverse transform: source_world = R^T @ (target_world - t)
    sx = cs * (wx - tx) + sn * (wy - ty)
    sy = -sn * (wx - tx) + cs * (wy - ty)

    src_col = np.round((sx - ox) / r).astype(np.int64)
    src_row = np.round((H - 1) - (sy - oy) / r).astype(np.int64)

    out = np.full((new_H, new_W), unknown_value, dtype=src.dtype)
    valid = (
        (src_col >= 0) & (src_col < W) &
        (src_row >= 0) & (src_row < H)
    )
    out[valid] = src[src_row[valid], src_col[valid]]

    Image.fromarray(out, mode="L").save(dst_image_path)
    return new_W, new_H, new_ox, new_oy


def transform_origin_yaw_xy(
    origin: Sequence[float], dyaw: float, tx: float, ty: float,
) -> List[float]:
    """Rotate origin around world origin by dyaw, then translate by (tx, ty).

    map.yaml `origin = [x, y, yaw]` is the world-frame pose of the lower-left
    pixel of the .pgm. Rotating the map frame by dyaw rotates this pose
    around (0,0); then we shift by (tx, ty); finally yaw is incremented.
    """
    if len(origin) < 3:
        raise ValueError("map origin must have at least [x, y, yaw]")
    ox = float(origin[0])
    oy = float(origin[1])
    oyaw = float(origin[2])
    c = math.cos(dyaw)
    s = math.sin(dyaw)
    nx = c * ox - s * oy + tx
    ny = s * ox + c * oy + ty
    nyaw = normalize_angle(oyaw + dyaw)
    return [nx, ny, nyaw]


# ---------- PCD parsing ----------

def pcd_struct_code(type_char: str, size: int) -> str:
    if type_char == "F":
        return {4: "f", 8: "d"}[size]
    if type_char == "I":
        return {1: "b", 2: "h", 4: "i", 8: "q"}[size]
    if type_char == "U":
        return {1: "B", 2: "H", 4: "I", 8: "Q"}[size]
    raise KeyError(f"unsupported PCD TYPE '{type_char}'")


def parse_pcd(path: Path):
    with path.open("rb") as f:
        raw_header: List[bytes] = []
        data_kind = None
        while True:
            line = f.readline()
            if not line:
                raise ValueError(f"invalid PCD header: {path}")
            raw_header.append(line)
            line_stripped = line.strip().decode("ascii", errors="ignore")
            if line_stripped.upper().startswith("DATA"):
                items = line_stripped.split()
                if len(items) != 2:
                    raise ValueError(f"invalid DATA line in PCD: {line_stripped}")
                data_kind = items[1].lower()
                break
        body = f.read()

    header: Dict[str, str] = {}
    for bline in raw_header:
        line = bline.decode("ascii", errors="ignore").strip()
        if not line or line.startswith("#"):
            continue
        k = line.split()[0].upper()
        header[k] = line[len(k):].strip()

    if "FIELDS" in header:
        fields = header["FIELDS"].split()
    elif "FIELD" in header:
        fields = header["FIELD"].split()
    else:
        raise ValueError("PCD header missing FIELDS/FIELD")

    sizes = [int(v) for v in header["SIZE"].split()]
    types = header["TYPE"].split()
    counts = [int(v) for v in header.get("COUNT", " ".join(["1"] * len(fields))).split()]

    if not (len(fields) == len(sizes) == len(types) == len(counts)):
        raise ValueError("PCD FIELDS/SIZE/TYPE/COUNT length mismatch")

    points = int(header.get("POINTS", "0") or "0")
    if points == 0:
        width = int(header.get("WIDTH", "0") or "0")
        height = int(header.get("HEIGHT", "1") or "1")
        points = width * height

    def field_byte_offset(field_name: str) -> int:
        off = 0
        for i, name in enumerate(fields):
            if name == field_name:
                return off
            off += sizes[i] * counts[i]
        raise KeyError(field_name)

    point_step = sum(sizes[i] * counts[i] for i in range(len(fields)))

    return {
        "raw_header": raw_header,
        "fields": fields,
        "sizes": sizes,
        "types": types,
        "points": points,
        "point_step": point_step,
        "data_kind": data_kind,
        "body": body,
        "field_byte_offset": field_byte_offset,
    }


def transform_pcd_yaw_xy(
    input_pcd: Path,
    output_pcd: Path,
    dyaw: float,
    tx: float,
    ty: float,
    tz: float = 0.0,
) -> None:
    """Apply p' = Rz(dyaw) * p + (tx, ty, tz) to every point.

    Also rotates `normal_x` / `normal_y` (no translation) if the PCD has
    those fields — otherwise downstream tools that consume normals (GICP,
    feature-based registration, etc.) would see normals pointing the wrong
    way after rotation. `normal_z` is left untouched (z-axis is the rotation
    axis, so it's invariant). `intensity`, `curvature`, and other scalar
    fields are also left untouched (they don't depend on orientation).
    """
    parsed = parse_pcd(input_pcd)

    data_kind = parsed["data_kind"]
    fields = parsed["fields"]
    sizes = parsed["sizes"]
    types = parsed["types"]
    points = parsed["points"]

    if "x" not in fields or "y" not in fields or "z" not in fields:
        raise ValueError("PCD must contain x/y/z fields")

    ix = fields.index("x")
    iy = fields.index("y")
    iz = fields.index("z")

    if not (types[ix] == types[iy] == types[iz] == "F"):
        raise ValueError("This converter currently requires float x/y/z fields")

    ox = parsed["field_byte_offset"]("x")
    oy = parsed["field_byte_offset"]("y")
    oz = parsed["field_byte_offset"]("z")

    code_x = pcd_struct_code(types[ix], sizes[ix])
    code_y = pcd_struct_code(types[iy], sizes[iy])
    code_z = pcd_struct_code(types[iz], sizes[iz])

    # Detect optional normal fields and rotate them too (no translation).
    has_normals = ("normal_x" in fields and "normal_y" in fields)
    if has_normals:
        if not (types[fields.index("normal_x")] == "F"
                and types[fields.index("normal_y")] == "F"):
            raise ValueError("normal_x/y must be float type")
        onx = parsed["field_byte_offset"]("normal_x")
        ony = parsed["field_byte_offset"]("normal_y")
        code_nx = pcd_struct_code(types[fields.index("normal_x")], sizes[fields.index("normal_x")])
        code_ny = pcd_struct_code(types[fields.index("normal_y")], sizes[fields.index("normal_y")])
        print(f"  [pcd] detected normal_x/normal_y, rotating them too "
              f"(normal_z preserved as z-axis is rotation axis)")

    c = math.cos(dyaw)
    s = math.sin(dyaw)

    if data_kind == "binary_compressed":
        raise ValueError("PCD DATA binary_compressed is not supported by this script")

    if data_kind == "ascii":
        text = parsed["body"].decode("utf-8", errors="ignore").splitlines()

        scalar_indices: Dict[str, int] = {}
        scalar_cursor = 0
        for i, fname in enumerate(fields):
            scalar_indices[fname] = scalar_cursor
            scalar_cursor += 1  # assume COUNT=1 for ascii

        x_idx = scalar_indices["x"]
        y_idx = scalar_indices["y"]
        z_idx = scalar_indices["z"]
        nx_idx = scalar_indices.get("normal_x")
        ny_idx = scalar_indices.get("normal_y")

        out_lines: List[str] = []
        for line in text:
            stripped = line.strip()
            if not stripped:
                continue
            vals = stripped.split()
            if max(x_idx, y_idx, z_idx) >= len(vals):
                out_lines.append(stripped)
                continue
            x = float(vals[x_idx])
            y = float(vals[y_idx])
            z = float(vals[z_idx])
            new_x = c * x - s * y + tx
            new_y = s * x + c * y + ty
            new_z = z + tz
            vals[x_idx] = f"{new_x:.6f}"
            vals[y_idx] = f"{new_y:.6f}"
            vals[z_idx] = f"{new_z:.6f}"
            if has_normals and nx_idx is not None and ny_idx is not None \
                    and max(nx_idx, ny_idx) < len(vals):
                nx = float(vals[nx_idx])
                ny = float(vals[ny_idx])
                vals[nx_idx] = f"{c * nx - s * ny:.6f}"
                vals[ny_idx] = f"{s * nx + c * ny:.6f}"
            out_lines.append(" ".join(vals))

        with output_pcd.open("wb") as f:
            for line in parsed["raw_header"]:
                f.write(line)
            f.write(("\n".join(out_lines) + "\n").encode("utf-8"))
        return

    if data_kind != "binary":
        raise ValueError(f"Unsupported PCD DATA kind: {data_kind}")

    point_step = parsed["point_step"]
    body = bytearray(parsed["body"])
    available = len(body) // point_step
    n = min(points, available)

    # Vectorized binary path. Equivalence to the per-point struct loop:
    # both promote each float32/float64 field to Python float (= C double)
    # before computing c*x - s*y + tx etc., then cast back to the field's
    # original size on write. Numpy's element-wise *, -, + on float64
    # arrays do NOT use FMA (separate kernels), so per-element rounding
    # matches Python's left-to-right evaluation. Result is bit-identical
    # to the old loop on x86_64 / IEEE 754 platforms — verified by
    # comparing md5sums of the converted PCD before and after this change.
    import numpy as np

    def _np_format(type_char: str, sz: int) -> str:
        if type_char == "F":
            return "<f4" if sz == 4 else "<f8"
        raise ValueError(f"unsupported field type for vectorized path: {type_char}/{sz}")

    dtype_names = ["x", "y", "z"]
    dtype_formats = [
        _np_format(types[ix], sizes[ix]),
        _np_format(types[iy], sizes[iy]),
        _np_format(types[iz], sizes[iz]),
    ]
    dtype_offsets = [ox, oy, oz]

    if has_normals:
        nx_idx = fields.index("normal_x")
        ny_idx = fields.index("normal_y")
        dtype_names += ["nx", "ny"]
        dtype_formats += [_np_format(types[nx_idx], sizes[nx_idx]),
                          _np_format(types[ny_idx], sizes[ny_idx])]
        dtype_offsets += [onx, ony]

    pts_view = np.frombuffer(body, dtype=np.dtype({
        "names": dtype_names,
        "formats": dtype_formats,
        "offsets": dtype_offsets,
        "itemsize": point_step,
    }), count=n)
    pts_view.flags.writeable = True

    x_d = pts_view["x"].astype(np.float64)
    y_d = pts_view["y"].astype(np.float64)
    z_d = pts_view["z"].astype(np.float64)

    new_x = c * x_d - s * y_d + tx
    new_y = s * x_d + c * y_d + ty
    new_z = z_d + tz

    pts_view["x"] = new_x.astype(pts_view["x"].dtype)
    pts_view["y"] = new_y.astype(pts_view["y"].dtype)
    pts_view["z"] = new_z.astype(pts_view["z"].dtype)

    if has_normals:
        nx_d = pts_view["nx"].astype(np.float64)
        ny_d = pts_view["ny"].astype(np.float64)
        new_nx = c * nx_d - s * ny_d
        new_ny = s * nx_d + c * ny_d
        pts_view["nx"] = new_nx.astype(pts_view["nx"].dtype)
        pts_view["ny"] = new_ny.astype(pts_view["ny"].dtype)

    with output_pcd.open("wb") as f:
        for line in parsed["raw_header"]:
            f.write(line)
        f.write(body)



def _check_pgm_pcd_alignment(
    pgm_yaml_path: Path,
    pcd_path: Path,
    pcd_yaw_bias_used: float,
) -> str:
    """Compare the xy bounding boxes of the converted pgm and pcd.

    They should describe the same world. Big disagreement (in either offset
    or sign) almost always means the recording pipeline used two SLAM nodes
    with different internal frames (slam_toolbox /map vs point_lio
    pcd_save world) and the user forgot to set --source-pcd-yaw-bias.

    Returns a string warning to print, or empty string if all is well.
    """
    try:
        from PIL import Image
        import numpy as np
    except ImportError:
        return ""  # silently skip if Pillow/numpy not available
    import struct

    # PGM bounds
    with pgm_yaml_path.open("r", encoding="utf-8") as f:
        pgm_yaml = yaml.safe_load(f)
    pgm_img_path = (pgm_yaml_path.parent / pgm_yaml["image"]).resolve()
    img = np.array(Image.open(pgm_img_path).convert("L"))
    H, W = img.shape
    r = float(pgm_yaml["resolution"])
    ox, oy = float(pgm_yaml["origin"][0]), float(pgm_yaml["origin"][1])
    pgm_xmin, pgm_xmax = ox, ox + W * r
    pgm_ymin, pgm_ymax = oy, oy + H * r

    # PCD bounds (sample points to keep this fast on huge clouds)
    try:
        with pcd_path.open("rb") as f:
            data = f.read()
        idx = data.find(b"DATA binary\n")
        if idx < 0:
            # ASCII pcd or unusual format -- skip the check rather than crash
            return ""
        header = data[:idx].decode("ascii", errors="replace")
        fields = sizes = None
        for line in header.splitlines():
            if line.startswith("FIELDS"):
                fields = line.split()[1:]
            elif line.startswith("SIZE"):
                sizes = [int(x) for x in line.split()[1:]]
        if fields is None or sizes is None:
            return ""
        ps = sum(sizes)
        body = data[idx + len(b"DATA binary\n"):]
        N = len(body) // ps
        if N == 0 or "x" not in fields or "y" not in fields:
            return ""
        xi, yi = fields.index("x"), fields.index("y")
        ox_b, oy_b = sum(sizes[:xi]), sum(sizes[:yi])
        # Sample at most 100k points uniformly.
        N_sample = min(N, 100_000)
        step = max(1, N // N_sample)
        xs = []
        ys = []
        for i in range(0, N, step):
            base = i * ps
            xs.append(struct.unpack_from("<f", body, base + ox_b)[0])
            ys.append(struct.unpack_from("<f", body, base + oy_b)[0])
        xs = np.asarray(xs, dtype=np.float32)
        ys = np.asarray(ys, dtype=np.float32)
        # Filter NaN/inf and clip to reasonable bounds
        finite = np.isfinite(xs) & np.isfinite(ys)
        xs, ys = xs[finite], ys[finite]
        if xs.size == 0:
            return ""
        pcd_xmin, pcd_xmax = float(xs.min()), float(xs.max())
        pcd_ymin, pcd_ymax = float(ys.min()), float(ys.max())
    except Exception:
        return ""

    # Overlap fraction in each axis.
    def overlap(a_min, a_max, b_min, b_max):
        lo = max(a_min, b_min)
        hi = min(a_max, b_max)
        inter = max(0.0, hi - lo)
        union = max(a_max, b_max) - min(a_min, b_min)
        return inter / union if union > 1e-6 else 0.0

    ox_ratio = overlap(pgm_xmin, pgm_xmax, pcd_xmin, pcd_xmax)
    oy_ratio = overlap(pgm_ymin, pgm_ymax, pcd_ymin, pcd_ymax)

    # Suggest a likely yaw bias by comparing centroids: if pgm and pcd
    # centers are approximately mirrored (pcd_center ≈ -pgm_center), the
    # missing bias is ~pi.
    pgm_cx = 0.5 * (pgm_xmin + pgm_xmax)
    pgm_cy = 0.5 * (pgm_ymin + pgm_ymax)
    pcd_cx = 0.5 * (pcd_xmin + pcd_xmax)
    pcd_cy = 0.5 * (pcd_ymin + pcd_ymax)

    msgs = []
    if ox_ratio > 0.5 and oy_ratio > 0.5:
        return (
            f"[sanity] pgm 与 pcd xy 包围盒重合度: "
            f"x={ox_ratio*100:.0f}%  y={oy_ratio*100:.0f}%  ✓ 看起来对齐了"
        )

    msgs.append("=" * 60)
    msgs.append("[警告] 转换后 pgm 和 pcd 的 xy 包围盒几乎不重合!")
    msgs.append(f"  pgm xy: [{pgm_xmin:.2f}, {pgm_xmax:.2f}] × [{pgm_ymin:.2f}, {pgm_ymax:.2f}]")
    msgs.append(f"  pcd xy: [{pcd_xmin:.2f}, {pcd_xmax:.2f}] × [{pcd_ymin:.2f}, {pcd_ymax:.2f}]")
    msgs.append(f"  重合度: x={ox_ratio*100:.0f}%   y={oy_ratio*100:.0f}%")
    msgs.append("")
    msgs.append("可能原因:")
    msgs.append("  这套代码同时跑 slam_toolbox(出 pgm) + point_lio(出 pcd),")
    msgs.append("  两者世界帧不一定一致, 通常差 ~180°.")
    msgs.append("")

    # Test: does flipping pcd center match pgm center?
    flip_dx = abs(pcd_cx + pgm_cx)
    flip_dy = abs(pcd_cy + pgm_cy)
    direct_dx = abs(pcd_cx - pgm_cx)
    direct_dy = abs(pcd_cy - pgm_cy)
    if (flip_dx + flip_dy) < (direct_dx + direct_dy) * 0.5:
        if abs(pcd_yaw_bias_used) < 1e-6:
            msgs.append("提示: pgm 与 pcd 中心点近似镜像, 强烈建议加上:")
            msgs.append("        --source-pcd-yaw-bias pi")
            msgs.append("      (即 3.14159265, 180°), 然后重跑 converter.")
        else:
            msgs.append(
                f"提示: 你已经填了 --source-pcd-yaw-bias "
                f"{math.degrees(pcd_yaw_bias_used):.2f}°, 但仍然对不齐."
            )
            msgs.append("      可能 bias 应该是相反符号, 或者 mount 数值不对.")
    else:
        msgs.append("提示: 也可能 mount 的 yaw 数值填错了, 或源数据本身错乱.")
    msgs.append("=" * 60)
    return "\n".join(msgs)


# ---------- Main ----------

def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description=(
            "Apply a 2D rigid transformation (yaw + xy) to a map.yaml/.pgm "
            "and its scans.pcd. If you don't know the right values, run "
            "auto_align_map.py first."
        )
    )

    parser.add_argument("--hero-map-yaml", default="", help="source 2D map yaml path")
    parser.add_argument("--hero-pcd", default="", help="source 3D pointcloud pcd path")

    parser.add_argument("--dyaw", default="",
                        help="yaw rotation around world z (e.g., 'pi/2', '90 deg', '1.5708')")
    parser.add_argument("--dx", default="0",
                        help="x translation in meters (default 0). Applied AFTER rotation around world origin.")
    parser.add_argument("--dy", default="0",
                        help="y translation in meters (default 0). Applied AFTER rotation around world origin.")

    parser.add_argument(
        "--source-lidar-mount",
        nargs=6, type=float, default=None,
        metavar=("X", "Y", "Z", "ROLL", "PITCH", "YAW"),
        help=(
            "Lidar mount pose on the recording robot's base "
            "(x y z roll pitch yaw, meters/radians). "
            "If given, BOTH the PCD and the 2D map yaml are first 'lifted' "
            "from the lidar's startup frame to the base_footprint frame, "
            "then the cross-robot dyaw/dx/dy is applied on top. "
            "ROLL/PITCH must be 0 (SLAM gravity-align is expected to absorb "
            "lidar tilt); a non-zero value raises an error."
        ),
    )

    parser.add_argument(
        "--source-pcd-yaw-bias",
        type=str, default="0",
        help=(
            "Extra Rz rotation applied to the PCD ONLY (not the 2D pgm) "
            "BEFORE the lidar-mount lift. Useful when the 2D pgm and the "
            "3D pcd come from different SLAM nodes that disagree on the "
            "world frame (e.g. slam_toolbox publishes /map in one frame "
            "while point_lio's pcd_save dumps in its IMU-anchored world "
            "frame -- they can differ by 180 degrees on this codebase). "
            "Accepts the same syntax as --dyaw: e.g. 'pi', '180 deg', "
            "'3.14159', or '0' (default). If you re-record a map and the "
            "post-conversion sanity check warns about large pgm/pcd "
            "bbox mismatch, plug the warned-about angle in here."
        ),
    )

    parser.add_argument("--output-folder-name", default="",
                        help="output root folder name under script directory")
    parser.add_argument("--force", action="store_true",
                        help="overwrite existing output folder")
    parser.add_argument("--no-interactive", action="store_true",
                        help="disable interactive prompts")

    return parser.parse_args()


def infer_default_paths(script_dir: Path) -> Tuple[str, str]:
    """Default to point_lio's PCD save directory: scans.yaml + scans.pcd live
    there as a paired output of one SLAM session, so they're guaranteed to
    share the same world frame and timestamp."""
    pcd_dir = script_dir / "src" / "pb2025_sentry_nav" / "point_lio" / "PCD"
    return (
        str(pcd_dir / "scans.yaml"),
        str(pcd_dir / "scans.pcd"),
    )


def main() -> int:
    args = parse_args()
    script_dir = Path(__file__).resolve().parent
    interactive = not args.no_interactive

    default_yaml, default_pcd = infer_default_paths(script_dir)

    if interactive:
        print("===== 地图转换器 (yaw + xy 模式) =====")
        print("用途:把 map.yaml/.pgm/scans.pcd 整体绕世界 Z 轴旋转 dyaw,再平移 (dx, dy)。")
        print("如果你不知道这 3 个数,先跑 `auto_align_map.py` 自动算出来。\n")

        yaml_text = prompt_text("请输入【源】2D 地图 yaml 路径", args.hero_map_yaml or default_yaml)
        pcd_text = prompt_text("请输入【源】3D 点云 pcd 路径", args.hero_pcd or default_pcd)

        print("\n[提示] dyaw 支持 pi/-pi/2 等表达式,角度可加 'deg'(如 '90 deg')。")
        dyaw = prompt_angle_or_deg("请输入 dyaw (绕世界 Z 轴旋转,单位默认弧度)", args.dyaw or "0")
        dx = prompt_number("请输入 dx (米)", args.dx or "0")
        dy = prompt_number("请输入 dy (米)", args.dy or "0")

        output_folder_name = prompt_text(
            "输出目录名(将在脚本目录下创建)",
            args.output_folder_name or f"map_conversion_{datetime.now().strftime('%Y%m%d_%H%M%S')}",
        )
    else:
        if not args.hero_map_yaml or not args.hero_pcd:
            raise ValueError("--hero-map-yaml and --hero-pcd are required in --no-interactive mode")
        yaml_text = args.hero_map_yaml
        pcd_text = args.hero_pcd
        dyaw = parse_angle_or_deg(args.dyaw) if args.dyaw else 0.0
        dx = parse_float(args.dx, 0.0)
        dy = parse_float(args.dy, 0.0)
        output_folder_name = args.output_folder_name or \
            f"map_conversion_{datetime.now().strftime('%Y%m%d_%H%M%S')}"

    source_yaml_path = Path(yaml_text).expanduser().resolve()
    source_pcd_path = Path(pcd_text).expanduser().resolve()

    if not source_yaml_path.exists():
        raise FileNotFoundError(f"source map yaml not found: {source_yaml_path}")
    if not source_pcd_path.exists():
        raise FileNotFoundError(f"source pcd not found: {source_pcd_path}")

    # ----- Compose lidar-mount lift + cross-robot transform -----
    # If the recording robot mounted the lidar at an offset on its base, the
    # PCD/2D-map points are anchored at the lidar's startup pose, not the
    # base_footprint at startup. To make small_gicp / map_server / nav2 all
    # see a consistent map frame anchored at base_footprint, we "lift" the
    # data first (apply T_base_lidar) before doing the user-supplied
    # cross-robot rigid (dyaw, dx, dy).
    #
    # After SLAM gravity-align, only translation + yaw of the mount remains
    # (roll/pitch are absorbed). We assert that here and otherwise raise.
    #
    # Composition: p' = R_cross @ (R_mount @ p + t_mount) + t_cross
    #            = R_total @ p + t_total
    # where:
    #   total_yaw = dyaw + mount_yaw
    #   total_dx  = cos(dyaw)*mx - sin(dyaw)*my + dx
    #   total_dy  = sin(dyaw)*mx + cos(dyaw)*my + dy
    #   total_dz  = mz   (z is independent of yaw)
    #
    # Additionally, --source-pcd-yaw-bias adds an extra Rz to the PCD ONLY
    # (applied BEFORE the mount lift). This is needed when the recording
    # pipeline used two different SLAM nodes for pgm vs pcd (slam_toolbox
    # for the 2D /map, point_lio's pcd_save for the 3D PCD) and their
    # internal frames disagree by some yaw offset.
    pcd_yaw_bias = parse_angle_or_deg(args.source_pcd_yaw_bias) if args.source_pcd_yaw_bias else 0.0
    if args.source_lidar_mount is not None:
        mx, my, mz, mroll, mpitch, mount_yaw = args.source_lidar_mount
        if abs(mroll) > 1e-6 or abs(mpitch) > 1e-6:
            raise ValueError(
                f"--source-lidar-mount roll={mroll}, pitch={mpitch} are non-zero. "
                "After SLAM gravity-align only translation + yaw should remain "
                "in the lidar mount. If your SLAM doesn't gravity-align the "
                "saved frame, fix that upstream rather than baking tilt here."
            )
        total_yaw = normalize_angle(dyaw + mount_yaw)
        total_dx = math.cos(dyaw) * mx - math.sin(dyaw) * my + dx
        total_dy = math.sin(dyaw) * mx + math.cos(dyaw) * my + dy
        total_dz = mz
        applied_mount = (mx, my, mz, mroll, mpitch, mount_yaw)
    else:
        total_yaw = dyaw
        total_dx = dx
        total_dy = dy
        total_dz = 0.0
        applied_mount = None
    # PCD-only yaw: extra bias rotates the PCD before the mount lift.
    # Translation is unchanged (the bias rotates around world origin
    # before we add t_mount/t_cross, which is the desired behavior).
    total_yaw_pcd = normalize_angle(total_yaw + pcd_yaw_bias)


    with source_yaml_path.open("r", encoding="utf-8") as f:
        source_map_yaml = yaml.safe_load(f)

    source_map_image = resolve_map_image(source_yaml_path, source_map_yaml)

    # Prepare output folders.
    root_dir = (script_dir / output_folder_name).resolve()
    if root_dir.exists():
        if not args.force:
            raise FileExistsError(f"output folder exists: {root_dir} (use --force)")
        shutil.rmtree(root_dir)

    source_dir = root_dir / "source_assets"
    converted_dir = root_dir / "converted_assets"
    source_dir.mkdir(parents=True, exist_ok=False)
    converted_dir.mkdir(parents=True, exist_ok=False)

    # Save source assets copy (untouched).
    src_yaml_copy = source_dir / "source_map.yaml"
    src_img_copy = source_dir / f"source_map{source_map_image.suffix}"
    src_pcd_copy = source_dir / "source_scans.pcd"
    shutil.copy2(source_yaml_path, src_yaml_copy)
    shutil.copy2(source_map_image, src_img_copy)
    shutil.copy2(source_pcd_path, src_pcd_copy)

    # Convert map yaml/image. We physically rotate the .pgm pixels by
    # total_yaw (around world origin) and translate by (total_dx, total_dy),
    # then write a yaml with origin yaw forced to 0. The rotation is
    # absorbed into the pixels themselves -- this side-steps the long-
    # standing flakiness around whether nav2 map_server / RViz actually
    # honor yaml `origin` yaw on different versions, and keeps PCD and 2D
    # map mutually consistent regardless.
    out_map_image = converted_dir / f"map{source_map_image.suffix}"
    out_map_yaml = converted_dir / "map.yaml"

    converted_yaml = dict(source_map_yaml)
    converted_yaml["image"] = out_map_image.name
    src_origin = source_map_yaml.get("origin", [0.0, 0.0, 0.0])
    if len(src_origin) < 2:
        raise ValueError(f"map yaml origin must have [x, y, ...]: {src_origin}")
    src_origin_yaw = float(src_origin[2]) if len(src_origin) >= 3 else 0.0
    if abs(src_origin_yaw) > 1e-6:
        # If the source map already had a non-zero yaw baked into its yaml,
        # we'd need to compose it. The point_lio pipeline always saves
        # yaw=0, so this is a forward-compat guard rather than expected.
        raise ValueError(
            f"source map yaml origin yaw = {src_origin_yaw} (non-zero); this "
            "converter currently assumes the source map has origin yaw = 0. "
            "Compose the yaws manually or extend transform_pgm_image."
        )
    src_resolution = float(source_map_yaml.get("resolution"))
    new_W, new_H, new_ox, new_oy = transform_pgm_image(
        source_map_image,
        out_map_image,
        dyaw=total_yaw,
        tx=total_dx,
        ty=total_dy,
        resolution=src_resolution,
        src_origin_xy=(float(src_origin[0]), float(src_origin[1])),
    )
    # Origin yaw is 0 by construction (rotation absorbed into pixels).
    converted_yaml["origin"] = [float(new_ox), float(new_oy), 0.0]

    with out_map_yaml.open("w", encoding="utf-8") as f:
        yaml.safe_dump(converted_yaml, f, sort_keys=False, allow_unicode=True)

    # Convert pcd by yaw + xyz (z translation is non-zero only when a
    # lidar mount was supplied — its mz lifts every PCD point off the
    # gravity-aligned ground plane to where the lidar physically sat).
    # Note: pcd uses total_yaw_pcd (= total_yaw + pcd_yaw_bias), pgm above
    # uses plain total_yaw. The bias compensates for the dual-SLAM frame
    # mismatch (slam_toolbox /map vs point_lio pcd_save world).
    out_pcd = converted_dir / "scans.pcd"
    transform_pcd_yaw_xy(
        source_pcd_path, out_pcd,
        dyaw=total_yaw_pcd, tx=total_dx, ty=total_dy, tz=total_dz,
    )

    # Compute the robot's init_pose in the *converted* map frame.
    # Reasoning: when SLAM saved the source map, it set its own map origin =
    # robot's starting pose. So the robot at session start is at (0, 0, 0) in
    # the source frame. Applying the same rigid motion that was applied to
    # the map/PCD, the robot's pose in the converted frame is just (dx, dy,
    # dyaw). Anyone using the converted map who launches with the robot at
    # the same physical spot must set this in nav2_params.yaml.
    new_init_yaw = normalize_angle(dyaw)
    new_init_pose = [float(dx), float(dy), 0.0, 0.0, 0.0, float(new_init_yaw)]
    init_pose_yaml_snippet = (
        f"init_pose: [{new_init_pose[0]:.6f}, {new_init_pose[1]:.6f}, "
        f"{new_init_pose[2]:.1f}, {new_init_pose[3]:.1f}, "
        f"{new_init_pose[4]:.1f}, {new_init_pose[5]:.6f}]"
    )

    metadata = {
        "created_at": datetime.now().isoformat(),
        "script_dir": str(script_dir),
        "transform": {
            "dyaw_rad": dyaw,
            "dyaw_deg": math.degrees(dyaw),
            "dx_m": dx,
            "dy_m": dy,
        },
        "source_lidar_mount": (
            None if applied_mount is None else {
                "x": applied_mount[0],
                "y": applied_mount[1],
                "z": applied_mount[2],
                "roll": applied_mount[3],
                "pitch": applied_mount[4],
                "yaw_rad": applied_mount[5],
                "yaw_deg": math.degrees(applied_mount[5]),
                "comment": (
                    "Lidar mount on the recording robot's base. PCD/2D-map "
                    "points were lifted from the lidar's startup frame to "
                    "base_footprint frame BEFORE the cross-robot dyaw/dx/dy "
                    "was applied."
                ),
            }
        ),
        "effective_total_transform": {
            "yaw_rad": total_yaw,
            "yaw_deg": math.degrees(total_yaw),
            "dx_m": total_dx,
            "dy_m": total_dy,
            "dz_m": total_dz,
            "comment": (
                "Combined transform actually applied to every PCD point: "
                "p' = Rz(yaw) * p + (dx, dy, dz). When source_lidar_mount is "
                "null, this equals the user-supplied (dyaw, dx, dy)."
            ),
        },
        "source": {
            "map_yaml": str(source_yaml_path),
            "map_image": str(source_map_image),
            "pcd": str(source_pcd_path),
        },
        "output": {
            "root_dir": str(root_dir),
            "source_assets": str(source_dir),
            "converted_assets": str(converted_dir),
        },
        "new_init_pose": {
            "x": new_init_pose[0],
            "y": new_init_pose[1],
            "z": 0.0,
            "roll": 0.0,
            "pitch": 0.0,
            "yaw_rad": new_init_pose[5],
            "yaw_deg": math.degrees(new_init_pose[5]),
            "yaml_snippet": init_pose_yaml_snippet,
            "comment": (
                "Robot's pose in the CONVERTED map frame, assuming it starts "
                "at the same physical spot where the source SLAM session began "
                "(i.e. SLAM origin = (0,0,0) in the source frame). Paste the "
                "yaml_snippet into nav2_params.yaml's init_pose field. "
                "When --source-lidar-mount is supplied, the lidar-mount lift "
                "is absorbed into the map/PCD itself, so init_pose is still "
                "just (dx, dy, dyaw)."
            ),
        },
        "notes": [
            "Both 2D map and 3D PCD are transformed by the same rigid motion.",
            "The .pgm pixels are physically rotated/translated to match; the saved yaml's origin yaw is always 0.",
            "Each PCD point becomes p' = Rz(total_yaw) * p + (total_dx, total_dy, total_dz).",
            "If --source-lidar-mount was supplied, total_* already absorbs the lidar->base lift.",
            "If the robot now starts somewhere else, recompute init_pose accordingly,",
            "or use RViz '2D Pose Estimate' to seed GICP at runtime.",
        ],
    }

    with (root_dir / "metadata.json").open("w", encoding="utf-8") as f:
        json.dump(metadata, f, indent=2, ensure_ascii=False)

    # ----- Post-conversion sanity check: pgm vs pcd xy bbox overlap -----
    # The 2D pgm and the 3D PCD should describe the same physical world.
    # If the converter's transform parameters are wrong (most commonly: a
    # missing --source-pcd-yaw-bias when the recording pipeline used two
    # different SLAM nodes), the two will end up in disjoint xy regions
    # after conversion. Detect that here and shout loud rather than silently
    # producing a broken bundle.
    sanity_warning = _check_pgm_pcd_alignment(
        out_map_yaml, out_pcd, pcd_yaw_bias_used=pcd_yaw_bias,
    )

    print("\n[完成] 地图转换完成")
    print(f"  应用的 dyaw : {math.degrees(dyaw):.4f}°  ({dyaw:.6f} rad)")
    print(f"  应用的平移  : dx={dx:.4f} m, dy={dy:.4f} m")
    if applied_mount is not None:
        print(
            f"  Lidar mount : "
            f"x={applied_mount[0]:.4f}, y={applied_mount[1]:.4f}, "
            f"z={applied_mount[2]:.4f} m, "
            f"yaw={math.degrees(applied_mount[5]):.4f}°"
        )
        print(
            f"  实际合成   : total_yaw={math.degrees(total_yaw):.4f}°, "
            f"total_dx={total_dx:.4f}, total_dy={total_dy:.4f}, "
            f"total_dz={total_dz:.4f} m"
        )
    if abs(pcd_yaw_bias) > 1e-6:
        print(
            f"  PCD 额外偏置: {math.degrees(pcd_yaw_bias):.4f}° "
            f"(total_yaw_pcd={math.degrees(total_yaw_pcd):.4f}°)"
        )
    print(f"  输出根目录  : {root_dir}")
    print(f"  原始资源    : {source_dir}")
    print(f"  转换结果    : {converted_dir}")
    if sanity_warning:
        print()
        print(sanity_warning)
    print(f"  元数据      : {root_dir / 'metadata.json'}")

    print("\n" + "=" * 60)
    print("[重要] 用对齐图启动 nav2 时,init_pose 必须改:")
    print("  机器人在原 SLAM 系下的起点 (0,0,0),")
    print("  在【对齐后】的地图系下变成了:")
    print(f"      ({new_init_pose[0]:.4f}, {new_init_pose[1]:.4f}, "
          f"yaw={math.degrees(new_init_pose[5]):.4f}°)")
    print()
    print("  把 nav2_params.yaml 里的 init_pose 改成下面这一行:")
    print(f"      {init_pose_yaml_snippet}")
    print()
    print("  (前提:机器人启动位置和录 SLAM 时的起点是同一个物理点。")
    print("   如果不是,自己算/RViz 手动 2D Pose Estimate。)")
    print("=" * 60)
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
