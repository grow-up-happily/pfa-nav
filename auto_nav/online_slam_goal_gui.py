#!/usr/bin/env python3
"""Small GUI launcher for recording and replaying online-SLAM goals.

The ROS implementation remains in online_slam_goal.py. This launcher only
handles the human-facing workflow and keeps saved goals in one directory.
"""

import argparse
import os
import re
import shutil
import subprocess
import sys
import time
import tkinter as tk
from pathlib import Path
from tkinter import messagebox, simpledialog, ttk


PROJECT_ROOT = Path(__file__).resolve().parents[1]
GOAL_DIR = PROJECT_ROOT / "online_slam_goals"
CORE_SCRIPT = Path(__file__).resolve().with_name("online_slam_goal.py")


def safe_name(value):
    value = re.sub(r"[^0-9A-Za-z_\-\u4e00-\u9fff]+", "_", value.strip())
    return value.strip("._") or f"goal_{time.strftime('%Y%m%d_%H%M%S')}"


class GoalLauncher:
    def __init__(self, root, namespace, goal_dir):
        self.root = root
        self.namespace = namespace.strip("/")
        self.goal_dir = Path(goal_dir).expanduser()
        self.goal_dir.mkdir(parents=True, exist_ok=True)
        self.child = None
        self.pending_file = None
        self.name_prompt_open = False

        root.title("在线建图导航目标")
        root.geometry("520x300")
        root.resizable(False, False)

        frame = ttk.Frame(root, padding=24)
        frame.pack(fill="both", expand=True)
        ttk.Label(
            frame,
            text="在线建图导航",
            font=("Sans", 18, "bold"),
        ).pack(pady=(0, 8))
        ttk.Label(
            frame,
            text="请选择本次操作：首次使用请录入目标点，之后可直接使用已保存目标。",
            wraplength=460,
            justify="center",
        ).pack(pady=(0, 18))

        buttons = ttk.Frame(frame)
        buttons.pack()
        ttk.Button(
            buttons,
            text="录入新目标点",
            command=self.record_goal,
            width=20,
        ).grid(row=0, column=0, padx=8, pady=8)
        ttk.Button(
            buttons,
            text="使用已保存目标",
            command=self.choose_saved_goal,
            width=20,
        ).grid(row=0, column=1, padx=8, pady=8)

        self.status = ttk.Label(frame, text=f"保存目录：{self.goal_dir}", wraplength=470)
        self.status.pack(pady=(24, 0))

    def ros_prefix(self):
        ns = f"/{self.namespace}" if self.namespace else ""
        return [
            "--ros-args",
            "-r",
            "__ns:=" + ns,
            "-r",
            "/tf:=" + ns + "/tf",
            "-r",
            "/tf_static:=" + ns + "/tf_static",
            "-p",
            "use_sim_time:=true",
        ]

    def start_core(self, extra_args):
        command = [sys.executable, str(CORE_SCRIPT), *extra_args, *self.ros_prefix()]
        self.status.config(text="已启动 ROS 目标节点，请查看终端输出和 RViz。")
        self.child = subprocess.Popen(command, cwd=str(PROJECT_ROOT))

    def saved_goal_files(self):
        return sorted(
            path
            for path in self.goal_dir.glob("*.json")
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

    def start_saved_goal(self, path):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
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

    def record_goal(self):
        if self.child is not None and self.child.poll() is None:
            messagebox.showwarning("目标节点正在运行", "当前已经有一个目标节点在运行。")
            return
        pending = self.goal_dir / f".pending_{os.getpid()}.json"
        if pending.exists():
            pending.unlink()
        self.pending_file = pending
        self.name_prompt_open = False
        self.start_core(
            [
                "--wait-click",
                "--goal-frame",
                "odom",
                "--goal-file",
                str(pending),
            ]
        )
        self.status.config(
            text=(
                "请在 RViz 将 Fixed Frame 设为 odom，点击 Publish Point，"
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


def main():
    parser = argparse.ArgumentParser(description="在线建图导航目标可视化管理器")
    parser.add_argument(
        "--namespace", default="red_standard_robot1", help="机器人 ROS 命名空间"
    )
    parser.add_argument(
        "--goal-dir",
        default=str(GOAL_DIR),
        help=f"目标 JSON 固定目录，默认 {GOAL_DIR}",
    )
    parser.add_argument(
        "--auto-goal",
        metavar="NAME",
        help="打开窗口后自动使用指定名称的已保存目标，无需人工选择",
    )
    parser.add_argument(
        "--list-goals",
        action="store_true",
        help="输出固定目录中的已保存目标名称并退出",
    )
    args = parser.parse_args()

    goal_dir = Path(args.goal_dir).expanduser()
    goal_dir.mkdir(parents=True, exist_ok=True)
    if args.list_goals:
        for path in sorted(goal_dir.glob("*.json")):
            if not path.name.startswith("."):
                print(path.stem)
        return

    root = tk.Tk()
    launcher = GoalLauncher(root, args.namespace, goal_dir)
    if args.auto_goal:
        root.after(150, lambda: launcher.start_saved_goal_by_name(args.auto_goal))
    root.mainloop()


if __name__ == "__main__":
    main()
