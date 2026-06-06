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

一键仿真建图并覆盖仿真先验导航的 `game` 地图：

```bash
./sim_slam_install_map.sh rmuc_2026
```

脚本会先用 `rmuc_2026` 启动 Gazebo 仿真世界，再启动仿真 SLAM；跑完需要建图的区域后按 `Ctrl+C`，它会保存最终 `.pgm/.yaml`，关闭建图让 point_lio 写出最新 `.pcd`，然后统一改名并覆盖安装到：

```text
src/pb2025_sentry_nav/pb2025_nav_bringup/map/simulation/game.yaml
src/pb2025_sentry_nav/pb2025_nav_bringup/map/simulation/game.pgm
src/pb2025_sentry_nav/pb2025_nav_bringup/pcd/simulation/scans.pcd
src/pb2025_sentry_nav/pb2025_nav_bringup/pcd/simulation/game.pcd
```

安装前会把已有同名文件备份为 `.bak_<时间戳>`。

建图归位后，一键启动 Gazebo + 仿真先验导航模式：

```bash
./sim_prior_nav_game.sh rmuc_2026
```

这里 `rmuc_2026` 是 Gazebo 世界，导航默认读取 `world:=game`，即刚才覆盖安装的 `game.yaml` 和 `pcd/simulation/scans.pcd`。

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

开机后旁路录制 MID360 建图输入的脚本、systemd 安装脚本和用法说明都集中在 `autostart_mid360_record/`，详见 `autostart_mid360_record/README.md`。

离线重跑录制包来建图时，不要再启动真实 Livox driver：

```bash
ros2 launch pb2025_nav_bringup rm_navigation_reality_launch.py slam:=True use_robot_state_pub:=True use_livox_driver:=False use_sim_time:=True
ros2 bag play <BAG_DIR> --clock
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

## 代码改动记录

### 2026-06-03 Nav2 IntensityVoxelLayer 孤立噪声过滤器

改动文件：

- `src/pb2025_sentry_nav/pb_nav2_plugins/pb_nav2_plugins-d70977132936da4d758bd6e8c0771a8cf4861ad9/include/pb_nav2_plugins/layers/intensity_voxel_layer.hpp`
- `src/pb2025_sentry_nav/pb_nav2_plugins/pb_nav2_plugins-d70977132936da4d758bd6e8c0771a8cf4861ad9/src/layers/intensity_voxel_layer.cpp`

大致改动：

- 改动状态：未经过仿真或实车测试。
- 此次添加代码主要是为了把 `docs/superpowers/specs/2026-04-26-nav2-isolated-noise-filter-design.md` 中记录的计划收束到现有代码中，避免该计划文件长期只是悬空记录。
- 在 `IntensityVoxelLayer` 中加入孤立点和小簇障碍噪声过滤逻辑。
- 新增参数 `noise_filter_enabled`，默认值为 `false`，因此当前 Nav2 配置不写该参数时不会启用新逻辑，也不会影响现有功能。
- 新增参数 `noise_filter_min_cluster_cells`，默认值为 `5`，用于控制保留障碍连通块所需的最小栅格数量。
- 启用过滤后，点云候选障碍格会先按二维 8 连通域分组，小于阈值的连通块不会写入 costmap。
- 未改动 `simulation/nav2_params.yaml` 和 `reality/nav2_params.yaml`，所以该功能目前只是代码可用，默认不生效。
