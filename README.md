## 编译

```bash
colcon build --symlink-install --parallel-workers 2 --cmake-args -DCMAKE_BUILD_TYPE=Release
```

## 仿真命令

仿真启动：

```bash
ros2 launch rmu_gazebo_simulator bringup_sim.launch.py
```

仿真导航（会从 src/pb2025_sentry_nav/pb2025_nav_bringup 下读取地图和点云）：

```bash
ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py world:=rmuc_2025 slam:=False
```

仿真建图：

```bash
ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py slam:=True
```

仿真车运动控制：

```bash
ros2 run rmoss_gz_base test_chassis_cmd.py --ros-args -r __ns:=/red_standard_robot1/robot_base -p v:=5.0 -p w:=0.3
```

地图保存（会报存到当前目录下）：

```bash
ros2 run nav2_map_server map_saver_cli -f <YOUR_MAP_NAME> --ros-args -r __ns:=/red_standard_robot1
```

## 实车建图

```bash
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py slam:=True use_robot_state_pub:=True
```

## 实车地图归位

建图完成后，先不要关闭建图程序，新开终端保存栅格地图：

```bash
ros2 run nav2_map_server map_saver_cli -f game
```

保存完成后再结束建图程序，让 point_lio 写出 `src/pb2025_sentry_nav/point_lio/PCD/scans.pcd`。随后在工作空间根目录运行脚本，把实车地图和点云放到导航默认读取的位置：

```bash
bash prepare_reality_map.sh game
```

脚本会执行这些操作：

- 将当前目录下的 `game.yaml` / `game.pgm` 放到 `src/pb2025_sentry_nav/pb2025_nav_bringup/map/reality/`
- 将 `src/pb2025_sentry_nav/point_lio/PCD/scans.pcd` 放到 `src/pb2025_sentry_nav/pb2025_nav_bringup/pcd/reality/game.pcd`
- 自动修改移动后的 `game.yaml` 文件，将其中的 `image` 字段改成 `game.pgm`

如果保存地图时使用了别的名字，例如 `my_map.yaml` / `my_map.pgm`，但导航时仍想用 `world:=game`：

```bash
bash prepare_reality_map.sh game --map-name my_map
```

如果目标目录已有同名文件，需要覆盖：

```bash
bash prepare_reality_map.sh game --force
```

移动完成后无需重新编译，可以直接启动实车导航：

```bash
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py world:=game slam:=False use_robot_state_pub:=True
```

## 在rviz可视化机器人模型

```bash
ros2 launch pb2025_robot_description robot_description_launch.py robot_name:=pfa_sentry_robot
```

> 如果因为libusb问题导致pointlio拉起失败，临时解决在命令前面加环境变量LD_PRELOAD=/lib/x86_64-linux-gnu/libusb-1.0.so.0

## 修改传感器位置

更改 src/pb2025_robot_description/resource/xmacro/simulation_robot.sdf.xmacro,如果是实车就是pfa_sentry_robot.sdf.xmacro中的雷达位置，然后根据/livox/imu话题输出更改nav2_params.yaml的gravity记得加上负号

## 设置航点，用于多点导航

进下面launch文件改目录

### 实车

改launch下的add_waypoint_reality.launch.py：

```bash
ros2 launch wp_map_tools add_waypoint_reality.launch.py yaml_name:=red.yaml
```

```bash
ros2 launch wp_map_tools add_waypoint_reality.launch.py yaml_name:=blue.yaml
```

也可以通过 map 参数指定地图（默认 pb2025_nav_bringup/map/reality/game.yaml）：

```bash
ros2 launch wp_map_tools add_waypoint_reality.launch.py map:=src/pb2025_sentry_nav/pb2025_nav_bringup/map/reality/your_map.yaml
```

### 仿真

```bash
ros2 launch wp_map_tools add_waypoint_simulation.launch.py
```

记得改game.py里的self.nav_ac = ActionClient(self, NavigateToPose, '/red_standard_robot1/navigate_to_pose')

## 保存航点

```bash
source install/setup.bash
```

(改目录 src/wp_saver.cpp)

```bash
ros2 run wp_map_tools wp_saver --red
```

```bash
ros2 run wp_map_tools wp_saver --blue
```

会保存为waypoints_red,waypoints_blue用于脚本读取

## LIO 调参指南（整理自各个 Issue）

- 室内可以把 filter_size_surf, filter_size_map 调小一点，一般分别为 0.05, 0.15. 对于 ouster 或者这种点特别多的，point_filter_num 可以调大，比如 5~10.
- 当点云较密集时，用较大的 lidar_meas_cov。结构较单一时，用较大的 lidar_meas_cov 。

## 补充

可使用gimp修剪栅格地图，CloudCompare修剪先验点云

src/pb2025_sentry_nav/pb2025_nav_bringup/config/reality/mid360_user_config.json  在这里配置雷达和本机ip可用LivoxViewer.sh查看

本项目引入 namespace 的设计，与 ROS 相关的 node, topic, action 等都加入了 namespace 前缀。如需查看 tf tree，请使用命令:

```bash
ros2 run rqt_tf_tree rqt_tf_tree --ros-args -r /tf:=tf -r /tf_static:=tf_static -r __ns:=/red_standard_robot1
```


