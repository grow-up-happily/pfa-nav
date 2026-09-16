# 在线建图导航点

- `simulation/`：仿真录制和使用的目标点。
- `reality/`：实车录制和使用的目标点。
- `simulation/routes/`：由仿真单点编排出的顺序路线。
- `reality/routes/`：由实车单点编排出的顺序路线。

目标文件使用 JSON 格式，坐标默认记录在 `odom` 坐标系中。两个环境的文件不要混用。

顺序路线统一使用 `pfa_online_slam_route/v1` 格式：

```json
{
  "format": "pfa_online_slam_route/v1",
  "name": "outbound_route",
  "frame": "odom",
  "waypoints": [
    {"name": "near", "x": 2.0, "y": 0.0, "yaw": 0.0},
    {"name": "middle", "x": 6.0, "y": 0.0, "yaw": 0.0},
    {"name": "target", "x": 9.0, "y": 0.0, "yaw": 0.0}
  ]
}
```

路线按照 `waypoints` 数组顺序执行。第一个点必须位于启动后能够规划的地图范围内，否则机器人没有移动，地图也无法继续扩展。
