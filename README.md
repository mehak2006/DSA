# DSA # Running C++ Code in GitHub Codespaces

This guide provides step-by-step instructions on how to compile and run your C++ program in GitHub Codespaces using the integrated terminal.

## 📌 Steps to Run C++ Code

### 1️⃣ Open the Integrated Terminal
- In GitHub Codespaces, open the **Terminal** by clicking on `Terminal > New Terminal` or using the shortcut **Ctrl + `** (backtick).

### 2️⃣ Navigate to Your Code Directory (If Needed)
If your C++ file (`main.cpp`) is inside a folder, navigate to it using:
```sh
cd path/to/your/code
```
To verify you're in the right directory, list files using:
```sh
ls  # On Linux/macOS
```
or
```sh
dir  # On Windows
```

### 3️⃣ Compile the C++ Code
Use the `g++` compiler to compile your C++ file:
```sh
g++ main.cpp -o output
```
This will create an executable file named `output`.

### 4️⃣ Run the Executable
After successful compilation, run the program using:
```sh
./output
```

## 🛠️ Common Issues & Fixes

### ❌ "Command not found" error for `g++`
- Ensure the `g++` compiler is installed. Run:
  ```sh
  g++ --version
  ```
  If not installed, install it using:
  ```sh
  sudo apt update && sudo apt install g++
  ```

### ❌ "Permission denied" error on `./output`
- Grant execution permission with:
  ```sh
  chmod +x output
  ```
  Then run `./output` again.

### ❌ "No such file or directory"
- Make sure you are in the correct directory.
- Use `ls` to list files and `cd path/to/your/code` to navigate.

## 🎯 Additional Commands
- **Compile with debugging info:**
  ```sh
  g++ -g main.cpp -o output
  ```
- **Compile with warnings enabled:**
  ```sh
  g++ -Wall -Wextra -pedantic main.cpp -o output
  ```
- **Run the program with input redirection:**
  ```sh
  ./output < input.txt
  ```

---
✅ Now you're ready to run your C++ programs in GitHub Codespaces! 🚀

