#!/usr/bin/env python3
"""Small GUI launcher for recording and replaying online-SLAM goals.

The ROS implementation remains in online_slam_goal.py. This launcher only
handles the human-facing workflow and keeps saved goals in one directory.
"""

import argparse
import json
import math
import os
import re
import signal
import shutil
import subprocess
import sys
import time
import tkinter as tk
from pathlib import Path
from tkinter import messagebox, simpledialog, ttk


PROJECT_ROOT = Path(__file__).resolve().parents[1]
SIMULATION_GOAL_DIR = PROJECT_ROOT / "online_slam_goals" / "simulation"
CORE_SCRIPT = Path(__file__).resolve().with_name("online_slam_goal.py")
ROUTE_FORMAT = "pfa_online_slam_route/v1"


def safe_name(value):
    value = re.sub(r"[^0-9A-Za-z_\-\u4e00-\u9fff]+", "_", value.strip())
    return value.strip("._") or f"goal_{time.strftime('%Y%m%d_%H%M%S')}"


def build_route_payload(name, point_files):
    """Build the versioned route document from ordered standalone goal files."""
    points = []
    route_frame = None
    for path in point_files:
        data = json.loads(path.read_text(encoding="utf-8"))
        frame = data.get("frame")
        if frame not in ("map", "odom") or not all(
            key in data for key in ("x", "y")
        ):
            raise ValueError(f"{path.name} 不是有效的单点文件")
        if route_frame is None:
            route_frame = frame
        elif frame != route_frame:
            raise ValueError("同一条路线不能混用 map 与 odom 坐标点")
        x = float(data["x"])
        y = float(data["y"])
        yaw = float(data.get("yaw", 0.0))
        if not all(math.isfinite(value) for value in (x, y, yaw)):
            raise ValueError(f"{path.name} 的坐标必须是有限数字")
        points.append(
            {
                "name": path.stem,
                "x": x,
                "y": y,
                "yaw": yaw,
            }
        )
    if not points:
        raise ValueError("路线至少需要一个导航点")
    return {
        "format": ROUTE_FORMAT,
        "name": name,
        "frame": route_frame,
        "waypoints": points,
    }


class GoalLauncher:
    def __init__(
        self,
        root,
        namespace,
        goal_dir,
        use_sim_time,
        start_mode,
        game_status_topic,
        confirm_before_start,
    ):
        self.root = root
        self.namespace = namespace.strip("/")
        self.goal_dir = Path(goal_dir).expanduser()
        self.use_sim_time = bool(use_sim_time)
        self.start_mode = start_mode
        self.game_status_topic = game_status_topic
        self.confirm_before_start = bool(confirm_before_start)
        self.goal_dir.mkdir(parents=True, exist_ok=True)
        self.route_dir = self.goal_dir / "routes"
        self.route_dir.mkdir(parents=True, exist_ok=True)
        self.child = None
        self.pending_file = None
        self.name_prompt_open = False
        self.closing = False

        root.title("在线建图导航目标")
        root.geometry("620x410")
        root.resizable(False, False)
        root.protocol("WM_DELETE_WINDOW", self.close)

        frame = ttk.Frame(root, padding=24)
        frame.pack(fill="both", expand=True)
        ttk.Label(
            frame,
            text="在线建图导航",
            font=("Sans", 18, "bold"),
        ).pack(pady=(0, 8))
        ttk.Label(
            frame,
            text="可录入单点，也可将已有单点可视化排序为顺序巡航路线。",
            wraplength=550,
            justify="center",
        ).pack(pady=(0, 18))

        buttons = ttk.Frame(frame)
        buttons.pack()
        ttk.Button(
            buttons,
            text="录入并导航",
            command=lambda: self.record_goal(record_only=False),
            width=22,
        ).grid(row=0, column=0, padx=8, pady=8)
        ttk.Button(
            buttons,
            text="使用已保存目标",
            command=self.choose_saved_goal,
            width=22,
        ).grid(row=0, column=1, padx=8, pady=8)
        ttk.Button(
            buttons,
            text="仅录入目标点（不导航）",
            command=lambda: self.record_goal(record_only=True),
            width=22,
        ).grid(row=1, column=0, padx=8, pady=8)
        ttk.Button(
            buttons,
            text="编排顺序巡航路线",
            command=self.open_route_editor,
            width=22,
        ).grid(row=1, column=1, padx=8, pady=8)
        ttk.Button(
            buttons,
            text="使用已保存路线",
            command=self.choose_saved_route,
            width=22,
        ).grid(row=2, column=0, columnspan=2, padx=8, pady=8)

        self.status = ttk.Label(frame, text=f"保存目录：{self.goal_dir}", wraplength=470)
        self.status.pack(pady=(24, 0))

    def ros_prefix(self):
        ros_args = ["--ros-args"]
        if self.namespace:
            ns = f"/{self.namespace}"
            ros_args.extend(
                [
                    "-r",
                    "__ns:=" + ns,
                    "-r",
                    "/tf:=" + ns + "/tf",
                    "-r",
                    "/tf_static:=" + ns + "/tf_static",
                ]
            )
        ros_args.extend(
            ["-p", f"use_sim_time:={'true' if self.use_sim_time else 'false'}"]
        )
        return ros_args

    def start_core(self, extra_args):
        command = [
            sys.executable,
            str(CORE_SCRIPT),
            *extra_args,
            "--start-mode",
            self.start_mode,
            "--game-status-topic",
            self.game_status_topic,
            *self.ros_prefix(),
        ]
        self.status.config(text="已启动 ROS 目标节点，请查看终端输出和 RViz。")
        self.child = subprocess.Popen(command, cwd=str(PROJECT_ROOT))

    def stop_child(self):
        child = self.child
        self.child = None
        if child is None or child.poll() is not None:
            return

        try:
            child.send_signal(signal.SIGINT)
        except ProcessLookupError:
            child.wait()
            return
        try:
            child.wait(timeout=3)
            return
        except subprocess.TimeoutExpired:
            child.terminate()
        try:
            child.wait(timeout=2)
        except subprocess.TimeoutExpired:
            child.kill()
            child.wait()

    def close(self):
        if self.closing:
            return
        self.closing = True
        self.stop_child()
        if self.pending_file is not None and self.pending_file.exists():
            self.pending_file.unlink()
        self.pending_file = None
        self.root.destroy()

    def confirm_test_start(self):
        if not self.confirm_before_start:
            return True
        return messagebox.askyesno(
            "实车测试放行确认",
            (
                "当前为实车测试模式，不会等待裁判系统比赛开始信号。\n\n"
                "请确认机器人已架起或位于安全空旷区域、急停和遥控接管可用，"
                "并且周围无人。确认后，导航系统一旦就绪就可能开始移动。\n\n"
                "是否允许本次测试移动？"
            ),
            parent=self.root,
        )

    def saved_goal_files(self):
        return sorted(
            path
            for path in self.goal_dir.glob("*.json")
            if not path.name.startswith(".")
        )

    def saved_route_files(self):
        return sorted(
            path
            for path in self.route_dir.glob("*.json")
            if not path.name.startswith(".")
        )

    def find_saved_goal(self, name):
        requested = name.strip()
        if requested.endswith(".json"):
            requested = requested[:-5]
        for path in self.saved_goal_files():
            if path.stem == requested:
                return path
        return None

    def find_saved_route(self, name):
        requested = name.strip()
        if requested.endswith(".json"):
            requested = requested[:-5]
        for path in self.saved_route_files():
            if path.stem == requested:
                return path
        return None

    def start_saved_goal(self, path):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return False
        if not self.confirm_test_start():
            self.status.config(text="已取消实车测试放行，未启动目标节点。")
            return False
        self.start_core(["--use-saved-goal", "--goal-file", str(path)])
        self.status.config(text=f"已使用目标：{path.name}，等待地图和 TF 后自动导航。")
        return True

    def start_saved_goal_by_name(self, name):
        path = self.find_saved_goal(name)
        if path is None:
            available = "、".join(item.stem for item in self.saved_goal_files())
            detail = f"\n当前可用目标：{available}" if available else "\n当前没有已保存目标。"
            self.status.config(text=f"未找到已保存目标：{name}")
            messagebox.showerror(
                "找不到目标点",
                f"保存目录中不存在目标“{name}”。{detail}",
                parent=self.root,
            )
            return False
        return self.start_saved_goal(path)

    def start_saved_route(self, path):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return False
        if not self.confirm_test_start():
            self.status.config(text="已取消实车测试放行，未启动路线节点。")
            return False
        self.start_core(["--use-saved-route", "--route-file", str(path)])
        self.status.config(text=f"已使用路线：{path.name}，将按顺序逐点导航。")
        return True

    def start_saved_route_by_name(self, name):
        path = self.find_saved_route(name)
        if path is None:
            available = "、".join(item.stem for item in self.saved_route_files())
            detail = f"\n当前可用路线：{available}" if available else "\n当前没有已保存路线。"
            self.status.config(text=f"未找到已保存路线：{name}")
            messagebox.showerror(
                "找不到巡航路线",
                f"路线目录中不存在“{name}”。{detail}",
                parent=self.root,
            )
            return False
        return self.start_saved_route(path)

    def record_goal(self, record_only=False):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return
        if not record_only and not self.confirm_test_start():
            self.status.config(text="已取消实车测试放行，未启动目标节点。")
            return
        pending = self.goal_dir / f".pending_{os.getpid()}.json"
        if pending.exists():
            pending.unlink()
        self.pending_file = pending
        self.pending_record_only = record_only
        self.name_prompt_open = False
        core_args = [
            "--wait-click",
            "--goal-frame",
            "odom",
            "--goal-file",
            str(pending),
        ]
        if record_only:
            core_args.append("--record-only")
        self.start_core(core_args)
        self.status.config(
            text=(
                "请在 RViz 使用 Publish Point 点击位置（可以位于灰色地图范围外），"
                "点击后会弹出命名窗口。"
            )
        )
        self.root.after(400, self.watch_pending_goal)

    def watch_pending_goal(self):
        if self.pending_file is None or self.name_prompt_open:
            return
        if self.pending_file.exists():
            self.name_prompt_open = True
            self.root.after(50, self.name_pending_goal)
            return
        if self.child is not None and self.child.poll() is not None:
            self.status.config(text="目标节点已退出，没有检测到点击目标。")
            return
        self.root.after(400, self.watch_pending_goal)

    def name_pending_goal(self):
        default = f"goal_{time.strftime('%Y%m%d_%H%M%S')}"
        name = simpledialog.askstring(
            "保存目标点",
            "请输入目标点名称：",
            initialvalue=default,
            parent=self.root,
        )
        if not name:
            name = default
        target = self.goal_dir / f"{safe_name(name)}.json"
        if target.exists():
            overwrite = messagebox.askyesno(
                "目标已存在",
                f"{target.name} 已存在，是否覆盖？",
                parent=self.root,
            )
            if not overwrite:
                target = self.goal_dir / (
                    f"{safe_name(name)}_{time.strftime('%H%M%S')}.json"
                )
        shutil.move(str(self.pending_file), str(target))
        self.pending_file = None
        self.name_prompt_open = False
        if self.pending_record_only:
            self.status.config(text=f"已保存目标：{target.name}，未发送导航目标。")
        else:
            self.status.config(text=f"已保存目标：{target.name}。本次导航继续执行。")

    def choose_saved_goal(self):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return
        files = self.saved_goal_files()
        if not files:
            messagebox.showinfo("没有保存点", "保存目录中还没有目标点，请先选择“录入新目标点”。")
            return

        dialog = tk.Toplevel(self.root)
        dialog.title("选择已保存目标")
        dialog.geometry("420x300")
        dialog.transient(self.root)
        ttk.Label(dialog, text="选择本次要导航的目标点：").pack(pady=10)
        listbox = tk.Listbox(dialog, height=10, width=48)
        listbox.pack(padx=16, fill="both", expand=True)
        for path in files:
            listbox.insert(tk.END, path.stem)
        listbox.selection_set(0)

        def start_selected():
            selection = listbox.curselection()
            if not selection:
                return
            chosen = files[selection[0]]
            dialog.destroy()
            self.start_saved_goal(chosen)

        ttk.Button(dialog, text="开始导航", command=start_selected).pack(pady=10)

    def choose_saved_route(self):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return
        files = self.saved_route_files()
        if not files:
            messagebox.showinfo("没有巡航路线", "请先选择“编排顺序巡航路线”。")
            return

        dialog = tk.Toplevel(self.root)
        dialog.title("选择已保存巡航路线")
        dialog.geometry("440x320")
        dialog.transient(self.root)
        ttk.Label(dialog, text="选择要执行的顺序巡航路线：").pack(pady=10)
        listbox = tk.Listbox(dialog, height=11, width=50)
        listbox.pack(padx=16, fill="both", expand=True)
        for path in files:
            listbox.insert(tk.END, path.stem)
        listbox.selection_set(0)

        def start_selected():
            selection = listbox.curselection()
            if not selection:
                return
            chosen = files[selection[0]]
            dialog.destroy()
            self.start_saved_route(chosen)

        ttk.Button(dialog, text="开始顺序导航", command=start_selected).pack(pady=10)

    def open_route_editor(self):
        point_files = self.saved_goal_files()
        if not point_files:
            messagebox.showinfo(
                "没有单点",
                "请先录入一个或多个独立目标点，再编排巡航路线。",
                parent=self.root,
            )
            return

        dialog = tk.Toplevel(self.root)
        dialog.title("编排顺序巡航路线")
        dialog.geometry("780x500")
        dialog.transient(self.root)
        dialog.grab_set()

        content = ttk.Frame(dialog, padding=14)
        content.pack(fill="both", expand=True)
        ttk.Label(
            content,
            text=(
                "左侧为已录制单点，添加到右侧后可调整先后顺序；"
                "同一点可以重复添加。第一个点必须位于初始可导航范围内。"
            ),
            wraplength=730,
        ).grid(row=0, column=0, columnspan=3, sticky="w", pady=(0, 10))

        ttk.Label(content, text="独立导航点").grid(row=1, column=0)
        ttk.Label(content, text="路线执行顺序").grid(row=1, column=2)
        available = tk.Listbox(content, selectmode=tk.EXTENDED, width=30, height=17)
        ordered_box = tk.Listbox(content, width=38, height=17)
        available.grid(row=2, column=0, sticky="nsew", padx=(0, 10))
        ordered_box.grid(row=2, column=2, sticky="nsew", padx=(10, 0))
        for path in point_files:
            available.insert(tk.END, path.stem)

        ordered = []

        def refresh_ordered(select_index=None):
            ordered_box.delete(0, tk.END)
            for index, path in enumerate(ordered, start=1):
                ordered_box.insert(tk.END, f"{index:02d}. {path.stem}")
            if select_index is not None and ordered:
                select_index = max(0, min(select_index, len(ordered) - 1))
                ordered_box.selection_set(select_index)
                ordered_box.see(select_index)

        def add_selected(_event=None):
            selections = available.curselection()
            for index in selections:
                ordered.append(point_files[index])
            refresh_ordered(len(ordered) - 1 if ordered else None)

        def remove_selected():
            selection = ordered_box.curselection()
            if not selection:
                return
            index = selection[0]
            ordered.pop(index)
            refresh_ordered(min(index, len(ordered) - 1) if ordered else None)

        def move_selected(offset):
            selection = ordered_box.curselection()
            if not selection:
                return
            index = selection[0]
            new_index = index + offset
            if new_index < 0 or new_index >= len(ordered):
                return
            ordered[index], ordered[new_index] = ordered[new_index], ordered[index]
            refresh_ordered(new_index)

        controls = ttk.Frame(content)
        controls.grid(row=2, column=1, sticky="n", pady=20)
        ttk.Button(controls, text="添加 →", command=add_selected, width=10).pack(pady=4)
        ttk.Button(controls, text="移除", command=remove_selected, width=10).pack(pady=4)
        ttk.Button(
            controls, text="上移", command=lambda: move_selected(-1), width=10
        ).pack(pady=4)
        ttk.Button(
            controls, text="下移", command=lambda: move_selected(1), width=10
        ).pack(pady=4)
        available.bind("<Double-Button-1>", add_selected)

        bottom = ttk.Frame(content)
        bottom.grid(row=3, column=0, columnspan=3, sticky="ew", pady=(14, 0))
        ttk.Label(bottom, text="路线名称：").pack(side="left")
        route_name = tk.StringVar(value=f"route_{time.strftime('%Y%m%d_%H%M%S')}")
        ttk.Entry(bottom, textvariable=route_name, width=34).pack(
            side="left", padx=(0, 12)
        )

        def save_route():
            if not ordered:
                messagebox.showwarning("路线为空", "请至少添加一个导航点。", parent=dialog)
                return
            name = safe_name(route_name.get())
            try:
                payload = build_route_payload(name, ordered)
            except (OSError, json.JSONDecodeError, TypeError, ValueError) as exc:
                messagebox.showerror("路线生成失败", str(exc), parent=dialog)
                return

            target = self.route_dir / f"{name}.json"
            if target.exists() and not messagebox.askyesno(
                "路线已存在", f"{target.name} 已存在，是否覆盖？", parent=dialog
            ):
                return
            try:
                target.write_text(
                    json.dumps(payload, ensure_ascii=False, indent=2) + "\n",
                    encoding="utf-8",
                )
            except OSError as exc:
                messagebox.showerror("路线保存失败", str(exc), parent=dialog)
                return
            self.status.config(
                text=(
                    f"已保存路线：routes/{target.name}，"
                    f"共 {len(payload['waypoints'])} 个点。"
                )
            )
            dialog.destroy()

        ttk.Button(bottom, text="保存路线", command=save_route).pack(side="right")
        content.columnconfigure(0, weight=1)
        content.columnconfigure(2, weight=1)
        content.rowconfigure(2, weight=1)


def main():
    parser = argparse.ArgumentParser(description="在线建图导航目标可视化管理器")
    parser.add_argument(
        "--namespace", default="red_standard_robot1", help="机器人 ROS 命名空间"
    )
    parser.add_argument(
        "--use-sim-time",
        choices=("true", "false"),
        default="true",
        help="是否使用 /clock；仿真用 true，实车用 false",
    )
    parser.add_argument(
        "--start-mode",
        choices=("immediate", "referee"),
        default="immediate",
        help="目标发送门控：立即发送，或等待裁判系统 RUNNING",
    )
    parser.add_argument(
        "--game-status-topic",
        default="/referee/game_status",
        help="pb_rm_interfaces/msg/GameStatus 类型的比赛状态话题",
    )
    parser.add_argument(
        "--confirm-before-start",
        action="store_true",
        help="启动目标节点前弹出实车移动安全确认",
    )
    parser.add_argument(
        "--goal-dir",
        default=str(SIMULATION_GOAL_DIR),
        help="目标 JSON 目录；默认使用项目内的仿真目标目录",
    )
    parser.add_argument(
        "--auto-goal",
        metavar="NAME",
        help="打开窗口后自动使用指定名称的已保存目标，无需人工选择",
    )
    parser.add_argument(
        "--auto-route",
        metavar="NAME",
        help="打开窗口后自动使用指定名称的顺序巡航路线",
    )
    parser.add_argument(
        "--list-goals",
        action="store_true",
        help="输出固定目录中的已保存目标名称并退出",
    )
    parser.add_argument(
        "--list-routes",
        action="store_true",
        help="输出 routes 目录中的已保存路线名称并退出",
    )
    args = parser.parse_args()

    if args.auto_goal and args.auto_route:
        parser.error("--auto-goal 和 --auto-route 不能同时使用")

    goal_dir = Path(args.goal_dir).expanduser()
    goal_dir.mkdir(parents=True, exist_ok=True)
    if args.list_goals:
        for path in sorted(goal_dir.glob("*.json")):
            if not path.name.startswith("."):
                print(path.stem)
        return
    if args.list_routes:
        route_dir = goal_dir / "routes"
        for path in sorted(route_dir.glob("*.json")):
            if not path.name.startswith("."):
                print(path.stem)
        return

    root = tk.Tk()
    launcher = GoalLauncher(
        root,
        args.namespace,
        goal_dir,
        use_sim_time=args.use_sim_time == "true",
        start_mode=args.start_mode,
        game_status_topic=args.game_status_topic,
        confirm_before_start=args.confirm_before_start,
    )
    if args.auto_goal:
        root.after(150, lambda: launcher.start_saved_goal_by_name(args.auto_goal))
    elif args.auto_route:
        root.after(150, lambda: launcher.start_saved_route_by_name(args.auto_route))
    try:
        root.mainloop()
    except KeyboardInterrupt:
        launcher.close()
    finally:
        launcher.stop_child()


if __name__ == "__main__":
    main()
