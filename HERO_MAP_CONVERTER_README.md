# 地图对齐工具集 (Map Alignment Tools)

本目录包含三个互相配合的工具,用于把一台机器人扫出来的 2D 占用栅格地图 + 3D 点云,对齐到另一个坐标系(比如仿真世界、另一台机器人的地图)。

> **设计前提**:你的 SLAM 系统使用**重力对齐**(point_lio / FAST-LIO 等会自动用 IMU 把 map 坐标系 z 轴对齐到世界垂直方向)。在这种前提下,两套地图之间的差异**只可能是水平面上的刚体变换**(yaw 旋转 + xy 平移)。这些工具就专门解决这个问题。

---

## 目录

- [文件清单](#文件清单)
- [快速开始](#快速开始)
- [auto_align_map.py 详细用法](#auto_align_mappy-详细用法)
- [hero_to_sentry_map_converter.py 详细用法](#hero_to_sentry_map_converterpy-详细用法)
- [sentry_to_hero_map_converter.py 详细用法](#sentry_to_hero_map_converterpy-详细用法)
- [输出文件结构](#输出文件结构)
- [工作原理](#工作原理)
- [启动导航测试](#启动导航测试)
- [常见问题](#常见问题)
- [故障排查](#故障排查)

---

## 文件清单

| 文件 | 作用 |
|------|------|
| `auto_align_map.py` | **自动配准**:输入两张地图,自动算出 dyaw/dx/dy |
| `hero_to_sentry_map_converter.py` | **手动转换**:已知 dyaw/dx/dy,把 map+pcd 应用变换 |
| `sentry_to_hero_map_converter.py` | **反向转换**:输入已知的英雄->哨兵 dyaw/dx/dy,自动求逆后把哨兵 map+pcd 转到英雄坐标系 |

通常你只需要用 `auto_align_map.py`,加 `--apply` 参数它会自动调用 `hero_to_sentry_map_converter.py`。如果已经有一组英雄到哨兵的变换参数,想反过来把哨兵图转到英雄坐标系,用 `sentry_to_hero_map_converter.py`。

---

### 输出格式

控制台打印示例:
```
============================================================
[1/4] Loading source map ...
    /path/to/source/map.yaml
    9276 obstacle pixels, shape (304, 563), res 0.05 m
[2/4] Loading reference map ...
    ...
[3/4] Searching for best (dyaw, dx, dy) ...
  [coarse search] yaw range -180..180 step 5.0°...
  [coarse best] yaw=-180.00° frac=66.1% mean_d=0.139m  T=(20.439, -3.077)
  [fine search] yaw range -185.00..-175.00° step 0.5°...
  [fine best] yaw=-179.50° frac=67.5% mean_d=0.152m  T=(20.453, -2.985)
  [ICP refine] yaw=-179.57° frac=73.7% mean_d=0.138m  T=(20.420, -2.939)

============================================================
[结果] Auto-alignment finished
  dyaw         = -179.5737°  (-3.134153 rad)
  dx           = 20.4200 m
  dy           = -2.9391 m
  inlier ratio = 73.65%
  inlier mean  = 0.1380 m
  ✅ Good inlier fraction. Result should be reliable.
```

### 内点率(健康度指标)

| 内点率 | 评估 | 建议 |
|--------|------|------|
| **> 60%** | ✅ 可信 | 直接用 |
| **30~60%** | ⚠️ 凑合 | RViz 里再目测,可能要微调 |
| **< 30%** | ❌ 异常 | 检查两张图是不是同一个场景 |

---

## `hero_to_sentry_map_converter.py` 详细用法

### 用途

已经知道 `dyaw / dx / dy`,直接应用变换。auto_align_map.py 的 `--apply` 在内部调用的就是它。

### 交互模式(适合人工调参)

```bash
python3 hero_to_sentry_map_converter.py
```

会一步步问:
```
请输入【源】2D 地图 yaml 路径 [...]:
请输入【源】3D 点云 pcd 路径 [...]:
请输入 dyaw (绕世界 Z 轴旋转,单位默认弧度) [0]:
请输入 dx (米) [0]:
请输入 dy (米) [0]:
输出目录名 [...]:
```

### 命令行模式(适合脚本/重复运行)

```bash
python3 hero_to_sentry_map_converter.py --no-interactive \
    --hero-map-yaml <map.yaml> \
    --hero-pcd <scans.pcd> \
    --dyaw '90 deg' \
    --dx 1.5 --dy -0.8 \
    --output-folder-name my_map \
    --force
```

### 参数表

| 参数 | 含义 |
|------|------|
| `--hero-map-yaml PATH` | 源 2D 地图 yaml |
| `--hero-pcd PATH` | 源 3D 点云 pcd |
| `--dyaw EXPR` | yaw 旋转(弧度,或加 `deg`/`°` 用度。支持 `pi/2`、`90 deg` 等) |
| `--dx METERS` | x 平移(米) |
| `--dy METERS` | y 平移(米) |
| `--output-folder-name NAME` | 输出目录名(默认带时间戳) |
| `--force` | 同名输出目录已存在则覆盖 |
| `--no-interactive` | 关闭交互(命令行模式必加) |

### `dyaw` 写法举例

```
0           ← 0 弧度
pi/2        ← 90°
-pi/2       ← -90°
pi          ← 180°
'90 deg'    ← 90°(注意要加引号)
'45°'       ← 45°
1.5708      ← 直接给数值(弧度)
```

---

## `sentry_to_hero_map_converter.py` 详细用法

### 用途

把哨兵侧的 `map.yaml/.pgm/scans.pcd` 转到英雄坐标系。你不需要手算反向的 `dx/dy`;只要输入已知的**英雄 -> 哨兵** `dyaw / dx / dy`,脚本会自动求逆,然后调用 `hero_to_sentry_map_converter.py` 执行真正的地图转换。

原始英雄到哨兵变换是:

```text
p_sentry = Rz(dyaw) * p_hero + (dx, dy)
```

脚本内部会自动换成:

```text
p_hero = Rz(-dyaw) * p_sentry + (dx_inv, dy_inv)
```

其中:

```text
dx_inv = -cos(dyaw) * dx - sin(dyaw) * dy
dy_inv =  sin(dyaw) * dx - cos(dyaw) * dy
```

### 交互模式(适合人工调参)

```bash
python3 sentry_to_hero_map_converter.py
```

会一步步问:

```text
请输入【哨兵源】2D 地图 yaml 路径 [...]:
请输入【哨兵源】3D 点云 pcd 路径 [...]:
请输入已知【英雄 -> 哨兵】dyaw [0]:
请输入已知【英雄 -> 哨兵】dx (米) [0]:
请输入已知【英雄 -> 哨兵】dy (米) [0]:
输出目录名 [...]:
```

### 命令行模式(适合脚本/重复运行)

```bash
python3 sentry_to_hero_map_converter.py --no-interactive \
    --sentry-map-yaml <哨兵_map.yaml> \
    --sentry-pcd <哨兵_scans.pcd> \
    --hero-to-sentry-dyaw '90 deg' \
    --hero-to-sentry-dx 1.5 \
    --hero-to-sentry-dy -0.8 \
    --output-folder-name sentry_to_hero \
    --force
```

上面这个例子里,脚本会自动算出真正应用到哨兵源地图上的参数:

```text
SENTRY->HERO dyaw = -90 deg
SENTRY->HERO dx   = 0.8
SENTRY->HERO dy   = 1.5
```

### 只查看反向命令,不执行转换

调参时可以先用 `--print-command-only` 看看脚本算出来的反向参数和最终调用命令:

```bash
python3 sentry_to_hero_map_converter.py --no-interactive \
    --sentry-map-yaml <哨兵_map.yaml> \
    --sentry-pcd <哨兵_scans.pcd> \
    --hero-to-sentry-dyaw '90 deg' \
    --hero-to-sentry-dx 1.5 \
    --hero-to-sentry-dy -0.8 \
    --print-command-only
```

### 参数表

| 参数 | 含义 |
|------|------|
| `--sentry-map-yaml PATH` | 哨兵侧源 2D 地图 yaml |
| `--sentry-pcd PATH` | 哨兵侧源 3D 点云 pcd |
| `--hero-to-sentry-dyaw EXPR` | 已知的英雄 -> 哨兵 yaw 旋转,支持 `pi/2`、`90 deg` 等写法 |
| `--hero-to-sentry-dx METERS` | 已知的英雄 -> 哨兵 x 平移(米) |
| `--hero-to-sentry-dy METERS` | 已知的英雄 -> 哨兵 y 平移(米) |
| `--source-lidar-mount X Y Z ROLL PITCH YAW` | 可选,当前源数据对应机器人的雷达安装位姿;原样传给底层 converter |
| `--source-pcd-yaw-bias EXPR` | 可选,当前源 PCD 的额外 yaw 偏置;原样传给底层 converter |
| `--output-folder-name NAME` | 输出目录名(默认 `sentry_to_hero_时间戳`) |
| `--converter-script PATH` | 可选,指定底层 `hero_to_sentry_map_converter.py` 路径 |
| `--print-command-only` | 只打印反向参数和底层调用命令,不真正转换 |
| `--force` | 同名输出目录已存在则覆盖 |
| `--no-interactive` | 关闭交互(命令行模式必加) |

### 注意事项

- `--hero-to-sentry-*` 填的是你已知的**英雄 -> 哨兵**参数,不是手算后的反向参数。
- 不要简单把 `dx/dy` 互换或取反;反向平移必须结合 `dyaw` 一起算,脚本会自动处理。
- 输出目录结构和 `hero_to_sentry_map_converter.py` 完全一样,导航使用 `converted_assets/map.yaml` 和 `converted_assets/scans.pcd`。
- 如果使用 `--source-lidar-mount` 或 `--source-pcd-yaw-bias`,它们描述的是**当前哨兵源数据**的附加修正,不是英雄侧旧数据的修正。

---

## 输出文件结构

每次跑完 converter(无论是 auto_align 调用还是手动跑)都会生成:

```
<output_folder>/
├── source_assets/                ← 原始资源备份(留底,不会修改)
│   ├── source_map.yaml
│   ├── source_map.pgm
│   └── source_scans.pcd
├── converted_assets/              ★ 这里才是给导航用的成果
│   ├── map.yaml                  ← image 指向转换后的 map.pgm,origin yaw 固定为 0
│   ├── map.pgm                   ← .pgm 像素已被旋转/平移到目标坐标系
│   └── scans.pcd                 ← 每个点都做了刚体变换
└── metadata.json                  ← 记录这次用了什么 dyaw/dx/dy
```

**为什么要旋转 .pgm?** 当前 converter 会把 2D 占用栅格像素实际旋转/平移,再把输出 `map.yaml` 的 `origin` yaw 固定为 0。这样可以避开不同 nav2 map_server / RViz 版本对 yaml `origin` yaw 支持不一致的问题,保证 2D 栅格地图和 3D PCD 在同一个目标坐标系里对齐。

`auto_align_report.json` 会保存在你执行 `auto_align_map.py` 的当前目录,内容包括:
- 源/参考地图的元数据
- 搜索参数
- 各阶段(粗搜→细搜→ICP)的得分
- 拷贝即用的 converter 命令字符串

---

## 工作原理

### auto_align_map.py 的算法

1. **加载两张地图**:用各自 yaml 里的 `resolution`、`origin`、`occupied_thresh`、`negate` 解析 .pgm,提取每个障碍物像素在**世界坐标系**下的 (x, y)。

2. **体素降采样**:每个 0.2m 的体素只保留一个代表点,大幅减少计算量,同时抑制单像素噪声。

3. **粗搜 yaw**:在 -180° 到 180° 范围内,每 5° 试一次。每次:
   - 把源点云绕**自身质心**旋转 dyaw
   - 平移到参考点云质心(质心对齐自动给出 dx/dy)
   - 用 KD-tree 算"源点云中有多少比例的点距离参考点云 < match_distance"
   - 取得分最高的角度

4. **细搜 yaw**:在粗搜最佳值 ±5° 范围内,每 0.5° 再细搜一次。

5. **ICP 精化**:用当前最佳 (dyaw, dx, dy) 找内点配对,SVD 解出最优 2D 刚体变换,作为最终结果。

6. **质量评估**:输出内点率和平均误差,提示可信度。

### hero_to_sentry_map_converter.py 的变换

对每个点 `p = (x, y, z)`,应用刚体变换:
```
p' = Rz(dyaw) * p + (dx, dy, 0)
```
其中 `Rz(θ)` 是绕世界 Z 轴旋转 θ 的矩阵。

对 2D 地图,converter 会把 .pgm 像素实际旋转/平移到目标坐标系,再写出新的 `origin = [new_ox, new_oy, 0]`。如果只看原始刚体变换,它对应的 2D 投影是:
```
nx   = cos(dyaw) * ox - sin(dyaw) * oy + dx
ny   = sin(dyaw) * ox + cos(dyaw) * oy + dy
nyaw = oyaw + dyaw
```

**关键性质**:2D 地图和 3D 点云用**完全相同**的变换,保证两者始终对齐。

---

## 启动导航测试

转换完成后,把 yaml 和 pcd 路径填进 launch 命令:

```bash
ros2 launch pb2025_nav_bringup rm_navigation_simulation_launch.py \
    world:=rmuc_2026 \
    slam:=False \
    map:=/home/tompig/pfa-nav-main/<output_folder>/converted_assets/map.yaml \
    prior_pcd_file:=/home/tompig/pfa-nav-main/<output_folder>/converted_assets/scans.pcd
```

启动后步骤:
1. 等 Gazebo 完全加载,机器人模型出现
2. RViz 中应能看到栅格地图(灰白色)和先验点云
3. 点 `2D Pose Estimate`,在地图上**机器人在 Gazebo 里实际所在的位置**点一下并拖出朝向
4. 等几秒,GICP 应该收敛(日志中应看到 `[small_gicp_relocalization]` 的 converged 提示)
5. 点 `2D Goal Pose` 测试导航能否规划路径

---

## 常见问题

### Q1: 我没有 reference 地图怎么办?

`src/pb2025_sentry_nav/pb2025_nav_bringup/map/simulation/` 下有官方提供的赛场地图:
- `rmuc_2024.yaml`、`rmuc_2025.yaml`、`rmuc_2026.yaml`
- `rmul_2024.yaml`、`rmul_2025.yaml`
- `game.yaml`

选一个对应你想跑的仿真世界即可。

### Q2: 自动配准给的结果在 RViz 里看着还是有点偏

拿 RViz 里目测的偏差,**在已对齐的地图基础上**再跑一次 converter 微调:

```bash
# 假设 RViz 看着还差 5° 旋转和 0.3m 向北
python3 hero_to_sentry_map_converter.py --no-interactive \
    --hero-map-yaml <已对齐的 map.yaml> \
    --hero-pcd <已对齐的 scans.pcd> \
    --dyaw '5 deg' --dx 0 --dy 0.3 \
    --output-folder-name fine_tuned --force
```

### Q3: 哨兵和英雄两台机器人,雷达姿态完全不一样,真的不用做 RPY 转换?

**真的不用**。原因:

- 两台机器人都跑 point_lio
- point_lio 启动时通过 IMU 重力把 map 坐标系 z 轴对齐到世界垂直方向
- 雷达的 roll/pitch 安装姿态在 SLAM 内部就被消化了,**保存出来的 map/PCD 都是世界对齐的**
- 两台机器人的地图唯一可能的差别只剩"启动位置 + 朝向",也就是 yaw + xy

所以不管你雷达是平躺、竖立、斜装,这两个工具都适用。

### Q4: 如何知道两台机器人(哨兵/英雄)谁扫的图、谁用?

不重要。只要 `--source` 是扫图机产生的、`--reference` 是目标坐标系下的图,脚本就能算对。

### Q5: 转换后的 PCD 文件很大(几十 MB)是正常的吗?

正常。脚本不会丢点,只对每个点应用变换。如果你需要降采样以加速重定位,用 PCL 工具单独压一下:

```bash
# 用 pcl_voxel_grid_filter(需要 sudo apt install pcl-tools)
pcl_voxel_grid_filter <input.pcd> <output.pcd> -leaf 0.1,0.1,0.1
```

### Q6: `auto_align_map.py` 跑得很慢,怎么办?

降低精度换速度:

```bash
python3 auto_align_map.py ... \
    --voxel-size 0.5 \
    --coarse-step-deg 10 \
    --fine-step-deg 1.0
```

或者跳过 yaw 搜索(如果你确定不需要旋转):

```bash
python3 auto_align_map.py ... --yaw-only-zero
```

---

## 故障排查

### `ValueError: map has no obstacle pixels`

地图全部被识别为非障碍物。检查:
- yaml 里的 `negate` 字段是不是写反了(0 vs 1)
- `occupied_thresh` 是不是太高(默认 0.65)
- .pgm 文件本身是不是空的或纯白

### `inlier ratio < 30%`,自动配准不可信

可能原因:
1. **两张图不是同一个场景** —— 检查 reference 选对没
2. **resolution 差太多** —— 一张 0.05m,一张 0.1m,先统一一下
3. **障碍物形态差异大** —— 一张是 SLAM 建的、一张是手画的,几何特征对不上

应对:
- 增大 `--match-distance`(比如 0.5)
- 减小 `--voxel-size`(比如 0.1)
- 改用 `--yaw-only-zero` 然后手动估 dyaw

### `[small_gicp_relocalization]: GICP did not converge` 一直刷

先验地图和实时雷达对不上。可能:
1. 机器人在 Gazebo 里的位置和 RViz 里点的初始位姿差太远
2. 转换后的 PCD 完全不在仿真世界范围内(检查 metadata.json 里的 dx/dy 是不是离谱)
3. 你用错了 reference 地图(比如 world 是 rmuc_2026 但你对齐到 rmuc_2024)

### `Robot is out of bounds of the costmap!`

机器人位置不在 map.yaml 的范围内。要么:
- 初始位姿没给,在 RViz 用 `2D Pose Estimate`
- 仿真生成的机器人不在你地图覆盖的区域

### 转换完成后 RViz 里地图是黑的

可能 yaml 里的 `image:` 字段路径不对。打开 converted_assets/map.yaml 检查 `image:` 应该是 `map.pgm`(相对路径,跟 yaml 在同一目录)。

---

## 设计权衡说明

### 为什么去掉了 RPY / forward_gravity / gravity_yaw 模式?

旧脚本里这三个模式假设 SLAM 直接用雷达初始姿态当作 map 坐标系(不做重力对齐)。这个假设对**老版本 SLAM** 成立,但对 point_lio / FAST-LIO 等现代重力对齐 SLAM **不成立**。

在重力对齐 SLAM 上用这些模式,会出现 2D 地图旋转和 3D 点云旋转不一致的现象(因为 RPY 变化中的 roll/pitch 分量没有合理的 2D 对应),最终导致 RViz 中静态地图和 costmap 错位。

`yaw_xy` 模式只做绕世界 Z 轴的旋转 + 水平平移,2D 和 3D 完全一致,数学上等价。这是重力对齐 SLAM 场景下唯一物理意义清晰的变换。

### 为什么自动配准用 2D 而不是 3D ICP?

- **更快**:3D ICP 在百万点云上要十几秒到几分钟,2D 在万级像素上几秒钟搞定
- **更准**:对于水平 yaw + xy 这个具体问题,2D 配准的搜索空间是 3 维,3D 配准是 6 维,后者容易陷入局部最优
- **足够用**:只要 SLAM 是重力对齐的,所需变换确实就是 2D 刚体,3D 信息纯粹冗余
