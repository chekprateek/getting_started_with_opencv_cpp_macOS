
# Setting Up OpenCV with C++17 on macOS

This guide outlines how to install and set up OpenCV with C++17 support on macOS, using Homebrew for package management, `clang++` for compiling, and Sublime Text as the editor.

## Prerequisites

1. **Homebrew**: macOS package manager for easy installation of software packages.
2. **OpenCV**: Computer vision library.
3. **clang++**: C++ compiler (comes with macOS Xcode Command Line Tools).
4. **Sublime Text**: Text editor (or any preferred code editor).

### Step 1: Install Homebrew

Homebrew is required for installing OpenCV and other necessary dependencies. To install Homebrew, run the following command in your terminal:

```bash
/bin/bash -c "$(curl -fsSL https://raw.githubusercontent.com/Homebrew/install/HEAD/install.sh)"
```

### Step 2: Install OpenCV with Homebrew

OpenCV can be easily installed via Homebrew. Run the following command to install the latest version of OpenCV (OpenCV 4.x):

```bash
brew install opencv
```

Once the installation is complete, you can verify that OpenCV is installed correctly by checking its version:

```bash
brew info opencv
```

This will provide information about the OpenCV installation path and related files.

### Step 3: Install Clang (if not already installed)

macOS includes `clang` as part of its developer tools.

You can verify the `clang++` version by running:

```bash
clang++ --version
```

Ensure that it shows `clang++ version 11.0.0` or higher, which supports C++11, C++14, and C++17.

### Step 4: Install Sublime Text (Optional)

Sublime Text is a popular text editor for coding. If you don’t have it installed, you can install it via Homebrew:

```bash
brew install --cask sublime-text
```

Alternatively, you can download it directly from [Sublime Text's website](https://www.sublimetext.com/).

### Step 5: Write Your OpenCV C++ Code

Open Sublime Text (or your preferred editor), and create a new C++ file (e.g., `main.cpp`). An example code to stream through your webcam is in main.cpp

### Step 6: Compile Your Code

To compile your code using `clang++`, use the following command:

```bash
clang++ -std=c++17 main.cpp -o webcam_stream `pkg-config --cflags --libs opencv4`
```

Explanation:
- `clang++`: Invokes the C++ compiler.
- `-std=c++17`: Specifies to use the C++17 standard.
- `main.cpp`: Your source file.
- `-o webcam_stream`: Specifies the output executable name.
- `` `pkg-config --cflags --libs opencv4` ``: Provides the necessary OpenCV flags for compiling and linking.

### Step 7: Run the Program

Once compiled, you can run the program with:

```bash
./webcam_stream
```

Press the **'q'** key to close the webcam window and stop the program.

---

## Troubleshooting

- If you encounter any issues with the `pkg-config` command, try reinstalling OpenCV with Homebrew or verifying that OpenCV's `pkg-config` file is correctly installed.
- Ensure that the OpenCV installation is linked correctly by checking that `pkg-config` points to the correct directories (usually `/opt/homebrew/opt/opencv` on Apple Silicon or `/usr/local/opt/opencv` on Intel-based Macs).

---

Feel free to adjust these instructions according to your specific setup or preferences. If any errors pop up during compilation or execution, don't hesitate to contact me for further assistance.
