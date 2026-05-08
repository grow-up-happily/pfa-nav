#!/usr/bin/env python3
"""Convert a saved PCD between two LiDAR mount poses.

This is for the case where a prior PCD was recorded with one LiDAR pose on
the robot, but localization will run with another LiDAR pose. It applies the
relative transform:

    p_new_lidar = inv(T_base_new_lidar) * T_base_old_lidar * p_old_lidar

Only the PCD is changed. A 2D occupancy grid map normally does not need this
conversion if the map/world frame itself did not change.
"""

from __future__ import annotations

import argparse
import math
from pathlib import Path
from typing import Dict, List, Sequence, Tuple

import numpy as np


ANGLE_NAMES = {
    "pi": math.pi,
    "PI": math.pi,
    "Pi": math.pi,
    "tau": 2.0 * math.pi,
    "e": math.e,
}


def parse_expr(text: str) -> float:
    s = str(text).strip()
    if not s:
        raise ValueError("empty numeric expression")
    try:
        return float(eval(s, {"__builtins__": {}}, ANGLE_NAMES))  # noqa: S307
    except Exception as exc:
        raise ValueError(f"cannot parse numeric expression {text!r}: {exc}") from exc


def parse_pose(values: Sequence[str]) -> Tuple[float, float, float, float, float, float]:
    if len(values) != 6:
        raise ValueError("pose must be 6 values: x y z roll pitch yaw")
    return tuple(parse_expr(v) for v in values)  # type: ignore[return-value]


def rx(a: float) -> np.ndarray:
    c = math.cos(a)
    s = math.sin(a)
    return np.array([[1.0, 0.0, 0.0], [0.0, c, -s], [0.0, s, c]], dtype=np.float64)


def ry(a: float) -> np.ndarray:
    c = math.cos(a)
    s = math.sin(a)
    return np.array([[c, 0.0, s], [0.0, 1.0, 0.0], [-s, 0.0, c]], dtype=np.float64)


def rz(a: float) -> np.ndarray:
    c = math.cos(a)
    s = math.sin(a)
    return np.array([[c, -s, 0.0], [s, c, 0.0], [0.0, 0.0, 1.0]], dtype=np.float64)


def pose_to_matrix(pose: Tuple[float, float, float, float, float, float]) -> np.ndarray:
    x, y, z, roll, pitch, yaw = pose
    mat = np.eye(4, dtype=np.float64)
    # ROS fixed-axis RPY convention: R = Rz(yaw) * Ry(pitch) * Rx(roll).
    mat[:3, :3] = rz(yaw) @ ry(pitch) @ rx(roll)
    mat[:3, 3] = [x, y, z]
    return mat


def read_pcd(path: Path) -> Tuple[List[bytes], Dict[str, str], str, bytes]:
    raw_header: List[bytes] = []
    data_kind = ""
    with path.open("rb") as f:
        while True:
            line = f.readline()
            if not line:
                raise ValueError(f"invalid PCD header: {path}")
            raw_header.append(line)
            stripped = line.strip().decode("ascii", errors="ignore")
            if stripped.upper().startswith("DATA"):
                parts = stripped.split()
                if len(parts) != 2:
                    raise ValueError(f"invalid PCD DATA line: {stripped}")
                data_kind = parts[1].lower()
                break
        body = f.read()

    header: Dict[str, str] = {}
    for line_b in raw_header:
        line = line_b.decode("ascii", errors="ignore").strip()
        if not line or line.startswith("#"):
            continue
        key = line.split()[0].upper()
        header[key] = line[len(key):].strip()

    return raw_header, header, data_kind, body


def pcd_dtype(type_char: str, size: int) -> str:
    if type_char == "F":
        if size == 4:
            return "<f4"
        if size == 8:
            return "<f8"
    if type_char == "I":
        return {1: "<i1", 2: "<i2", 4: "<i4", 8: "<i8"}[size]
    if type_char == "U":
        return {1: "<u1", 2: "<u2", 4: "<u4", 8: "<u8"}[size]
    raise ValueError(f"unsupported PCD field type/size: {type_char}/{size}")


def field_offsets(fields: Sequence[str], sizes: Sequence[int], counts: Sequence[int]) -> Dict[str, int]:
    offsets: Dict[str, int] = {}
    offset = 0
    for field, size, count in zip(fields, sizes, counts):
        offsets[field] = offset
        offset += size * count
    return offsets


def transform_binary_pcd(
    raw_header: List[bytes],
    header: Dict[str, str],
    body: bytes,
    output_path: Path,
    transform: np.ndarray,
) -> None:
    fields = header["FIELDS"].split() if "FIELDS" in header else header["FIELD"].split()
    sizes = [int(v) for v in header["SIZE"].split()]
    types = header["TYPE"].split()
    counts = [int(v) for v in header.get("COUNT", " ".join("1" for _ in fields)).split()]

    if not (len(fields) == len(sizes) == len(types) == len(counts)):
        raise ValueError("PCD FIELDS/SIZE/TYPE/COUNT length mismatch")
    for name in ("x", "y", "z"):
        if name not in fields:
            raise ValueError(f"PCD missing required field: {name}")

    offsets = field_offsets(fields, sizes, counts)
    point_step = sum(size * count for size, count in zip(sizes, counts))
    points = int(header.get("POINTS", "0") or "0")
    if points == 0:
        points = int(header.get("WIDTH", "0") or "0") * int(header.get("HEIGHT", "1") or "1")
    available = len(body) // point_step
    n = min(points, available)

    names = ["x", "y", "z"]
    formats = []
    dtype_offsets = []
    for name in names:
        idx = fields.index(name)
        if types[idx] != "F" or counts[idx] != 1:
            raise ValueError(f"field {name} must be a single float")
        formats.append(pcd_dtype(types[idx], sizes[idx]))
        dtype_offsets.append(offsets[name])

    has_normals = all(name in fields for name in ("normal_x", "normal_y", "normal_z"))
    if has_normals:
        for name in ("normal_x", "normal_y", "normal_z"):
            idx = fields.index(name)
            if types[idx] != "F" or counts[idx] != 1:
                raise ValueError(f"field {name} must be a single float")
            names.append(name)
            formats.append(pcd_dtype(types[idx], sizes[idx]))
            dtype_offsets.append(offsets[name])

    data = bytearray(body)
    arr = np.frombuffer(data, dtype=np.dtype({
        "names": names,
        "formats": formats,
        "offsets": dtype_offsets,
        "itemsize": point_step,
    }), count=n)
    arr.flags.writeable = True

    rotation = transform[:3, :3]
    translation = transform[:3, 3]
    xyz = np.column_stack((arr["x"], arr["y"], arr["z"])).astype(np.float64)
    xyz_out = xyz @ rotation.T + translation
    arr["x"] = xyz_out[:, 0].astype(arr["x"].dtype)
    arr["y"] = xyz_out[:, 1].astype(arr["y"].dtype)
    arr["z"] = xyz_out[:, 2].astype(arr["z"].dtype)

    if has_normals:
        normals = np.column_stack((arr["normal_x"], arr["normal_y"], arr["normal_z"])).astype(np.float64)
        normals_out = normals @ rotation.T
        arr["normal_x"] = normals_out[:, 0].astype(arr["normal_x"].dtype)
        arr["normal_y"] = normals_out[:, 1].astype(arr["normal_y"].dtype)
        arr["normal_z"] = normals_out[:, 2].astype(arr["normal_z"].dtype)

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open("wb") as f:
        for line in raw_header:
            f.write(line)
        f.write(data)


def transform_ascii_pcd(
    raw_header: List[bytes],
    header: Dict[str, str],
    body: bytes,
    output_path: Path,
    transform: np.ndarray,
) -> None:
    fields = header["FIELDS"].split() if "FIELDS" in header else header["FIELD"].split()
    counts = [int(v) for v in header.get("COUNT", " ".join("1" for _ in fields)).split()]
    if any(count != 1 for count in counts):
        raise ValueError("ASCII PCD with COUNT != 1 is not supported")
    for name in ("x", "y", "z"):
        if name not in fields:
            raise ValueError(f"PCD missing required field: {name}")

    ix, iy, iz = fields.index("x"), fields.index("y"), fields.index("z")
    has_normals = all(name in fields for name in ("normal_x", "normal_y", "normal_z"))
    if has_normals:
        inx, iny, inz = fields.index("normal_x"), fields.index("normal_y"), fields.index("normal_z")

    rotation = transform[:3, :3]
    translation = transform[:3, 3]
    out_lines: List[str] = []
    for line in body.decode("utf-8", errors="ignore").splitlines():
        stripped = line.strip()
        if not stripped:
            continue
        values = stripped.split()
        xyz = np.array([float(values[ix]), float(values[iy]), float(values[iz])], dtype=np.float64)
        xyz_out = rotation @ xyz + translation
        values[ix] = f"{xyz_out[0]:.9g}"
        values[iy] = f"{xyz_out[1]:.9g}"
        values[iz] = f"{xyz_out[2]:.9g}"
        if has_normals:
            normal = np.array([float(values[inx]), float(values[iny]), float(values[inz])], dtype=np.float64)
            normal_out = rotation @ normal
            values[inx] = f"{normal_out[0]:.9g}"
            values[iny] = f"{normal_out[1]:.9g}"
            values[inz] = f"{normal_out[2]:.9g}"
        out_lines.append(" ".join(values))

    output_path.parent.mkdir(parents=True, exist_ok=True)
    with output_path.open("wb") as f:
        for line in raw_header:
            f.write(line)
        f.write(("\n".join(out_lines) + "\n").encode("utf-8"))


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(
        description="Convert a PCD from an old LiDAR mount pose to a new LiDAR mount pose."
    )
    parser.add_argument("--input", default="/home/lcy/convert/scans.pcd", help="source PCD path")
    parser.add_argument(
        "--output",
        default="/home/lcy/convert/new_lidar_pose/scans.pcd",
        help="converted PCD path",
    )
    parser.add_argument(
        "--old-pose",
        nargs=6,
        default=["0.16", "0.0", "0.18", "pi/6", "0.0", "pi/2"],
        metavar=("X", "Y", "Z", "ROLL", "PITCH", "YAW"),
        help="old lidar pose in base frame: x y z roll pitch yaw",
    )
    parser.add_argument(
        "--new-pose",
        nargs=6,
        default=["0.0", "-0.1", "0.35", "-pi/3", "0.0", "-pi/2"],
        metavar=("X", "Y", "Z", "ROLL", "PITCH", "YAW"),
        help="new lidar pose in base frame: x y z roll pitch yaw",
    )
    parser.add_argument("--force", action="store_true", help="overwrite output if it exists")
    parser.add_argument("--print-matrix", action="store_true", help="print the relative transform")
    return parser.parse_args()


def main() -> int:
    args = parse_args()
    input_path = Path(args.input).expanduser().resolve()
    output_path = Path(args.output).expanduser().resolve()
    if not input_path.exists():
        raise FileNotFoundError(input_path)
    if output_path.exists() and not args.force:
        raise FileExistsError(f"output exists: {output_path} (use --force)")

    old_pose = parse_pose(args.old_pose)
    new_pose = parse_pose(args.new_pose)
    transform = np.linalg.inv(pose_to_matrix(new_pose)) @ pose_to_matrix(old_pose)

    if args.print_matrix:
        np.set_printoptions(precision=12, suppress=False)
        print("relative transform = inv(T_new) * T_old:")
        print(transform)

    raw_header, header, data_kind, body = read_pcd(input_path)
    if data_kind == "binary_compressed":
        raise ValueError("PCD DATA binary_compressed is not supported")
    if data_kind == "binary":
        transform_binary_pcd(raw_header, header, body, output_path, transform)
    elif data_kind == "ascii":
        transform_ascii_pcd(raw_header, header, body, output_path, transform)
    else:
        raise ValueError(f"unsupported PCD DATA kind: {data_kind}")

    print(f"[done] wrote: {output_path}")
    print("[note] use the original 2D map yaml/pgm unless the map/world frame also changed")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
