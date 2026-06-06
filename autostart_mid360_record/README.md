# MID360 旁路录包开机自启

这个目录只负责实车 MID360 原始消息旁路录制，不启动 Livox driver，不启动建图/导航。

## 文件

- `mid360_mapping_record.sh`: 录包脚本，默认 `RECORD_MODE=debug`，等待 Livox topic 后录制点云、IMU、速度输出和 TF。
- `install_service.sh`: systemd 安装脚本，会按当前仓库实际路径生成 service。
- `mid360_mapping_record.service`: systemd 示例模板，不建议直接复制；不同车上的代码路径可能不同。

## 手动运行

```bash
cd <你的pfa-nav仓库路径>
./autostart_mid360_record/mid360_mapping_record.sh
```

录包默认输出到：

```text
<你的pfa-nav仓库路径>/ros2_bag/mid360_pointcloud/
```

## 安装开机自启

```bash
cd <你的pfa-nav仓库路径>
./autostart_mid360_record/install_service.sh
```

安装脚本会自动把当前仓库路径写入 `/etc/systemd/system/mid360_mapping_record.service`。如果要指定模式：

```bash
RECORD_MODE=debug ./autostart_mid360_record/install_service.sh
RECORD_MODE=minimal ./autostart_mid360_record/install_service.sh
RECORD_MODE=full ./autostart_mid360_record/install_service.sh
```

## 查看状态和日志

```bash
systemctl status mid360_mapping_record.service
journalctl -u mid360_mapping_record.service -f
```

## 停止或取消自启

```bash
sudo systemctl stop mid360_mapping_record.service
sudo systemctl disable mid360_mapping_record.service
```

## 到车上确认 topic

正常启动实车建图/导航后，新开终端执行：

```bash
cd <你的pfa-nav仓库路径>
source install/setup.bash
ros2 topic list | sort | grep -E 'livox|cmd_vel|tf'
```

重点确认这两个是否存在：

```bash
ros2 topic info /livox/lidar
ros2 topic info /livox/imu
ros2 topic hz /livox/lidar
```

如果以后实际 topic 带 namespace，临时手动运行时这样指定：

```bash
NAMESPACE=<你的namespace> ./autostart_mid360_record/mid360_mapping_record.sh
```

如果想完全手动指定 topic，不走自动识别：

```bash
RECORD_TOPICS="/你的namespace/livox/lidar /你的namespace/livox/imu" ./autostart_mid360_record/mid360_mapping_record.sh
```

## 录制模式

默认模式是普通调试包：

```bash
RECORD_MODE=debug ./autostart_mid360_record/mid360_mapping_record.sh
```

会录：

```text
/livox/lidar
/livox/imu
/cmd_vel
/cmd_vel_nav2_result
/cmd_vel_controller
/tf
/tf_static
```

严格最小包只录离线重新建图必须的 Livox 点云和 IMU：

```bash
RECORD_MODE=minimal ./autostart_mid360_record/mid360_mapping_record.sh
```

```text
/livox/lidar
/livox/imu
```

全量包录所有当前和后续发现的 topic，主要用于深度排查，不建议比赛默认使用：

```bash
RECORD_MODE=full ./autostart_mid360_record/mid360_mapping_record.sh
```

如果需要临时覆盖某项，也可以单独指定：

```bash
RECORD_CMD_VEL=0 RECORD_TF=0 ./autostart_mid360_record/mid360_mapping_record.sh
```
