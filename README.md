# File Compressor

This project implements a simple file compressor using a C++ backend for compression and a Python GUI for user interaction. It allows users to compress various file types such as MP3, MP4, and documents.

## Features

- Select any file to compress
- Choose the destination for the compressed file
- User-friendly interface built with Tkinter

## Prerequisites

### C++ Dependencies
- C++ compiler (g++, clang, etc.)
- CMake
- zlib

### Python Dependencies
- Python 3.x
- Tkinter (usually included with Python)
- ctypes (included with Python)

## Installation

### Step 1: Clone the Repository

```bash
git clone https://github.com/yourusername/file-compressor.git
cd file-compressor
```
### Step 2: Compile the Backend of C++
1. Navigate to the build directory and create it if it doesn't exist:

```bash
mkdir build
cd build
```
2. Run CMake to configure the project:

```bash
cmake ..
```
3. Compile the Project:

```bash
make
```
This will create a shared library (libcompressor.so on Linux or compressor.dll on Windows) in the build directory.

### Run the Python GUI:

1. Navigate back to the main project directory:

```bash
cd ..
```
2. Run the Python script:

```bash
python gui.py
```
## Usage

1. Click on the "Browse" button to select the file you want to compress.
2. Enter the destination path for the compressed file.
3. Click the "Compress" button to start the compression process.
4. A message box will inform you of the success or failure of the compression.

## Notes
Ensure that the C++ shared library is in the same directory as the Python script or adjust the library path in the gui.py file accordingly.
If you encounter any issues, check the console for error messages.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

