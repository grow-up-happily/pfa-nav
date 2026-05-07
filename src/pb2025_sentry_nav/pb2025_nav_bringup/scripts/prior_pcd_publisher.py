#!/usr/bin/env python3
# Copyright 2025
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0

"""Publish a prior PCD map as sensor_msgs/PointCloud2 on `prior_map`."""

import sys
from threading import Thread

import numpy as np
import rclpy
from rclpy.duration import Duration
from rclpy.executors import ExternalShutdownException, SingleThreadedExecutor
from rclpy.node import Node
from rclpy.qos import DurabilityPolicy, QoSProfile, ReliabilityPolicy
from rclpy.time import Time
from sensor_msgs.msg import PointCloud2, PointField
from tf2_ros import Buffer, TransformException, TransformListener


_NP_TO_ROS = {
    ("F", 4): PointField.FLOAT32,
    ("F", 8): PointField.FLOAT64,
    ("U", 1): PointField.UINT8,
    ("U", 2): PointField.UINT16,
    ("U", 4): PointField.UINT32,
    ("I", 1): PointField.INT8,
    ("I", 2): PointField.INT16,
    ("I", 4): PointField.INT32,
}

_NP_DTYPE = {
    ("F", 4): "<f4",
    ("F", 8): "<f8",
    ("U", 1): "<u1",
    ("U", 2): "<u2",
    ("U", 4): "<u4",
    ("I", 1): "<i1",
    ("I", 2): "<i2",
    ("I", 4): "<i4",
}


def _parse_pcd_header(f):
    header = {}
    while True:
        line = f.readline()
        if not line:
            raise OSError("Unexpected EOF while reading PCD header")
        text = line.decode("ascii", errors="replace").strip()
        if not text or text.startswith("#"):
            continue
        if " " in text:
            key, value = text.split(None, 1)
        else:
            key, value = text, ""
        header[key] = value
        if key == "DATA":
            break
    return header


def load_binary_pcd(path):
    with open(path, "rb") as f:
        header = _parse_pcd_header(f)
        fmt = header.get("DATA", "ascii")
        if fmt != "binary":
            raise ValueError(f"Only DATA binary supported, got '{fmt}'. File: {path}")

        fields = header["FIELDS"].split()
        sizes = [int(s) for s in header["SIZE"].split()]
        types = header["TYPE"].split()
        counts = [int(c) for c in header["COUNT"].split()]
        n_points = int(header.get("POINTS", header.get("WIDTH", "0")))
        if not (len(fields) == len(sizes) == len(types) == len(counts)):
            raise ValueError("Inconsistent FIELDS/SIZE/TYPE/COUNT in PCD header")

        dtype_specs = []
        for i, name in enumerate(fields):
            key = (types[i], sizes[i])
            if key not in _NP_DTYPE:
                raise ValueError(f"Unsupported field type {types[i]}{sizes[i]} for '{name}'")
            if counts[i] == 1:
                dtype_specs.append((name, _NP_DTYPE[key]))
            else:
                dtype_specs.append((name, _NP_DTYPE[key], counts[i]))
        dtype = np.dtype(dtype_specs)

        raw = f.read()
        expected = dtype.itemsize * n_points
        if len(raw) < expected:
            raise OSError(f"PCD body truncated: expected {expected} bytes, got {len(raw)}")
        arr = np.frombuffer(raw[:expected], dtype=dtype)

    return arr, fields, sizes, types, counts


def build_pointcloud2_msg(arr, fields, sizes, types, counts, frame_id):
    msg = PointCloud2()
    msg.header.frame_id = frame_id
    msg.height = 1
    msg.width = int(arr.shape[0])
    msg.is_bigendian = False
    msg.is_dense = True

    offset = 0
    for i, name in enumerate(fields):
        pf = PointField()
        pf.name = name
        pf.offset = offset
        pf.datatype = _NP_TO_ROS[(types[i], sizes[i])]
        pf.count = counts[i]
        msg.fields.append(pf)
        offset += sizes[i] * counts[i]

    msg.point_step = offset
    msg.row_step = msg.point_step * msg.width
    msg.data = arr.tobytes()
    return msg


def quaternion_to_matrix(q):
    x = q.x
    y = q.y
    z = q.z
    w = q.w
    norm = x * x + y * y + z * z + w * w
    if norm == 0.0:
        return np.identity(3)

    scale = 2.0 / norm
    xx = x * x * scale
    xy = x * y * scale
    xz = x * z * scale
    xw = x * w * scale
    yy = y * y * scale
    yz = y * z * scale
    yw = y * w * scale
    zz = z * z * scale
    zw = z * w * scale

    return np.array(
        [
            [1.0 - yy - zz, xy - zw, xz + yw],
            [xy + zw, 1.0 - xx - zz, yz - xw],
            [xz - yw, yz + xw, 1.0 - xx - yy],
        ],
        dtype=np.float64,
    )


def transform_xyz(arr, transform):
    for name in ("x", "y", "z"):
        if name not in arr.dtype.names:
            raise ValueError(f"PCD field '{name}' is required for transform")

    out = arr.copy()
    rotation = quaternion_to_matrix(transform.rotation)
    translation = np.array(
        [transform.translation.x, transform.translation.y, transform.translation.z],
        dtype=np.float64,
    )
    xyz = np.column_stack((out["x"], out["y"], out["z"])).astype(np.float64, copy=False)
    xyz = xyz @ rotation.T + translation
    out["x"] = xyz[:, 0]
    out["y"] = xyz[:, 1]
    out["z"] = xyz[:, 2]
    return out


class PriorPCDPublisher(Node):
    def __init__(self):
        super().__init__("prior_pcd_publisher")

        self.declare_parameter("file_name", "")
        self.declare_parameter("frame_id", "map")
        self.declare_parameter("base_frame", "")
        self.declare_parameter("lidar_frame", "")
        self.declare_parameter("publish_period_sec", 1.0)
        self.declare_parameter("transform_timeout_sec", 1.0)

        file_name = self.get_parameter("file_name").get_parameter_value().string_value
        frame_id = self.get_parameter("frame_id").get_parameter_value().string_value
        base_frame = self.get_parameter("base_frame").get_parameter_value().string_value
        lidar_frame = self.get_parameter("lidar_frame").get_parameter_value().string_value
        period = self.get_parameter("publish_period_sec").get_parameter_value().double_value
        timeout_sec = (
            self.get_parameter("transform_timeout_sec").get_parameter_value().double_value
        )

        if not file_name:
            self.get_logger().error("Parameter 'file_name' is required")
            raise SystemExit(2)

        self.get_logger().info(f"Loading prior PCD: {file_name}")
        try:
            arr, fields, sizes, types, counts = load_binary_pcd(file_name)
        except Exception as exc:
            self.get_logger().error(f"Failed to load PCD: {exc}")
            raise SystemExit(3) from exc

        if base_frame and lidar_frame:
            tf_buffer = Buffer(node=self)
            TransformListener(tf_buffer, self)
            tf_executor = SingleThreadedExecutor()
            tf_executor.add_node(self)

            def spin_tf():
                try:
                    tf_executor.spin()
                except ExternalShutdownException:
                    pass

            tf_thread = Thread(target=spin_tf, daemon=True)
            tf_thread.start()
            self.get_logger().info(
                f"Waiting for transform {base_frame} <- {lidar_frame} before publishing prior map"
            )
            try:
                while rclpy.ok():
                    try:
                        tf_stamped = tf_buffer.lookup_transform(
                            base_frame, lidar_frame, Time(), timeout=Duration(seconds=timeout_sec)
                        )
                        arr = transform_xyz(arr, tf_stamped.transform)
                        t = tf_stamped.transform.translation
                        q = tf_stamped.transform.rotation
                        self.get_logger().info(
                            "Applied prior map transform "
                            f"{base_frame} <- {lidar_frame}: "
                            f"translation=({t.x:.6f}, {t.y:.6f}, {t.z:.6f}), "
                            f"quaternion=({q.x:.6f}, {q.y:.6f}, {q.z:.6f}, {q.w:.6f})"
                        )
                        break
                    except KeyboardInterrupt:
                        raise
                    except TransformException as exc:
                        self.get_logger().warn(f"TF lookup failed: {exc} Retrying...")
            finally:
                tf_executor.shutdown()
                tf_executor.remove_node(self)
                tf_thread.join(timeout=1.0)

        self.cloud_msg = build_pointcloud2_msg(arr, fields, sizes, types, counts, frame_id)
        self.get_logger().info(
            f"Loaded {self.cloud_msg.width} points, fields={fields}, "
            f"point_step={self.cloud_msg.point_step}, frame_id='{frame_id}'"
        )

        qos = QoSProfile(
            reliability=ReliabilityPolicy.RELIABLE,
            durability=DurabilityPolicy.VOLATILE,
            depth=1,
        )
        self.pub = self.create_publisher(PointCloud2, "prior_map", qos)
        self.timer = self.create_timer(max(period, 0.05), self._tick)
        self.get_logger().info(
            f"Publishing on '{self.get_namespace().rstrip('/')}/prior_map' "
            f"every {period:.2f}s (frame_id='{frame_id}')"
        )

    def _tick(self):
        self.cloud_msg.header.stamp = self.get_clock().now().to_msg()
        self.pub.publish(self.cloud_msg)


def main():
    rclpy.init(args=sys.argv)
    try:
        node = PriorPCDPublisher()
    except KeyboardInterrupt:
        if rclpy.ok():
            rclpy.shutdown()
        sys.exit(130)
    except SystemExit as exc:
        rclpy.shutdown()
        sys.exit(exc.code if exc.code is not None else 1)

    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        if rclpy.ok():
            rclpy.shutdown()


if __name__ == "__main__":
    main()
