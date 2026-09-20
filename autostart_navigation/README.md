# PFA 实车导航开机自启

该服务从当前仓库启动实车静态地图导航，不依赖旧工作区路径。

- 地图：`map/reality/game.yaml`
- 点云：`point_lio/PCD/scans.pcd`
- 命名空间：默认为空
- RViz：开机服务中默认关闭
- 不会自动发送导航目标

安装并设为开机自启（不立即启动）：

```bash
./autostart_navigation/install_service.sh
```

需立即启动时：

```bash
START_NOW=1 ./autostart_navigation/install_service.sh
```

查看状态：

```bash
systemctl status pfa-navigation.service
journalctl -u pfa-navigation.service -f
```
