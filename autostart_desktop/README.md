# 桌面会话自启

这是旧 GNOME 自启方案的备用迁移版。当 systemd 导航和录包服务已安装时，这两个桌面项默认保留但禁用，防止重复启动。

1. 备用 MID360 录包入口。
2. 备用实车导航和 RViz 入口。

安装：

```bash
./autostart_desktop/install_desktop_autostart.sh
```

安装器会禁用原来指向 `/home/pfa/sight/pfa-nav` 的两个旧自启项，但不删除它们。
