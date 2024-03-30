import tkinter as tk
from tkinter import ttk
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.animation import FuncAnimation
import platform


class Node:
    def __init__(self, k, v):
        self.key = k
        self.value = v
        self.next = None
        self.prev = None


class LRU_cache:
    def __init__(self, capacity):
        self.capacity = capacity
        self.dic = dict()
        self.head = Node(0, 0)
        self.tail = Node(0, 0)
        self.head.next = self.tail
        self.tail.prev = self.head

    def _add(self, node):
        p = self.tail.prev
        p.next = node
        self.tail.prev = node
        node.next = self.tail
        node.prev = p

    def _remove(self, node):
        p = node.prev
        n = node.next
        p.next = n
        n.prev = p

    def get(self, key):
        if key in self.dic:
            n = self.dic[key]
            self._remove(n)
            self._add(n)
            return n.value
        return -1

    def set(self, key, value):
        n = Node(key, value)
        self._add(n)
        self.dic[key] = n
        if len(self.dic) > self.capacity:
            n = self.head.next
            self._remove(n)
            del self.dic[n.key]


class LRUCacheApp:
    def __init__(self, master):
        self.master = master
        self.master.title("LRU Cache Visualization")
        self.cache = LRU_cache(3)

        # Key Entry
        self.key_label = ttk.Label(self.master, text="Enter Key:")
        self.key_label.grid(row=0, column=0, padx=5, pady=5)
        self.key_entry = ttk.Entry(self.master)
        self.key_entry.grid(row=0, column=1, padx=5, pady=5)

        # Value Entry
        self.value_label = ttk.Label(self.master, text="Enter Value:")
        self.value_label.grid(row=0, column=2, padx=5, pady=5)
        self.value_entry = ttk.Entry(self.master)
        self.value_entry.grid(row=0, column=3, padx=5, pady=5)

        # Buttons
        self.set_button = ttk.Button(
            self.master, text="Set Value", command=self.set_value
        )
        self.set_button.grid(row=0, column=4, padx=5, pady=5)

        self.get_button = ttk.Button(
            self.master, text="Get Value", command=self.get_value
        )
        self.get_button.grid(row=0, column=5, padx=5, pady=5)

        # Result Label
        self.result_var = tk.StringVar()
        self.result_label = ttk.Label(
            self.master, textvariable=self.result_var, foreground="green"
        )
        self.result_label.grid(row=1, column=0, columnspan=6, pady=10)

        # Graph Display
        self.fig, self.ax = plt.subplots(figsize=(6, 2))  # Adjust the height as needed
        self.canvas = FigureCanvasTkAgg(self.fig, master=self.master)
        self.canvas_widget = self.canvas.get_tk_widget()
        self.canvas_widget.grid(row=2, column=0, columnspan=6, pady=10)

        # Update Graph Button
        self.update_graph_button = ttk.Button(
            self.master, text="Update Graph", command=self.update_graph
        )
        self.update_graph_button.grid(row=3, column=0, columnspan=6, pady=10)

    def update_cache_display(self):
        cache_content = [
            f"{node.key}: {node.value}" for node in self.cache.dic.values()
        ]
        self.cache_display.config(text=f"LRU Cache: {', '.join(cache_content)}")

    def update_graph(self):
        keys = list(self.cache.dic.keys())
        values = [node.value for node in self.cache.dic.values()]

        self.ax.clear()
        self.ax.bar(keys, values, color="blue")
        self.ax.set_xlabel("Keys")
        self.ax.set_ylabel("Values")
        self.ax.set_title("LRU Cache Visualization")
        self.canvas.draw()

    def get_value(self):
        key = self.key_entry.get()
        value = self.cache.get(key)

        if value != -1:
            result_text = f"Value for key '{key}': {value}"
        else:
            result_text = f"Key '{key}' not found in the cache."

        self.result_var.set(result_text)

        # Update cache display and graph
        self.update_cache_display()
        self.update_graph()

    def set_value(self):
        key = self.key_entry.get()
        value = self.value_entry.get()
        self.cache.set(key, value)
        print(f"Key-Value pair '{key}: {value}' set in the cache.")
        self.update_cache_display()


if __name__ == "__main__":
    root = tk.Tk()
    app = LRUCacheApp(root)
    root.mainloop()



