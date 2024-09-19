import tkinter as tk
from tkinter import filedialog, messagebox
import ctypes
import os

# Load the shared library
compressor = ctypes.CDLL('./build/libcompressor.so')

# Define the argument types for the C++ function
compressor.compress.argtypes = [ctypes.c_char_p, ctypes.c_char_p]

def select_file():
    file_path = filedialog.askopenfilename()
    if file_path:
        source_var.set(file_path)

def compress_file():
    source = source_var.get()
    dest = dest_var.get()
    
    if not source or not dest:
        messagebox.showerror("Error", "Please select a source file and a destination.")
        return

    try:
        compressor.compress(source.encode('utf-8'), dest.encode('utf-8'))
        messagebox.showinfo("Success", f"File compressed to {dest}")
    except Exception as e:
        messagebox.showerror("Error", str(e))

# Create GUI
root = tk.Tk()
root.title("File Compressor")

source_var = tk.StringVar()
dest_var = tk.StringVar()

tk.Label(root, text="Source File:").pack()
tk.Entry(root, textvariable=source_var).pack()
tk.Button(root, text="Browse", command=select_file).pack()

tk.Label(root, text="Destination File:").pack()
tk.Entry(root, textvariable=dest_var).pack()

tk.Button(root, text="Compress", command=compress_file).pack()

root.mainloop()
