# OpenGL-Engine

**OpenGL-Engine** is my **hobby project** written in **C++** – a graphics engine built with an **Entity Component System (ECS)** architecture.  
This project is primarily for **fun, learning, and self-improvement**, and also to serve as a part of my portfolio.  
⚠️ This is **not meant to be a production-ready engine** for mass use. Instead, it's a playground for experimenting with engine architecture, rendering backends, and graphics programming.

---

## Features
- Entity Component System (ECS) architecture,  
- Backend system already in place → future support for multiple graphics APIs,  
- Currently supports **OpenGL**,  
- Written in modern **C++**,  
- Build system powered by **Premake5**.  
---

## Building the Project

### 🔹 Linux

**Requirements:**
- C++ compiler (`g++` or `clang++`),  
- `make`,  
- [Premake5](https://premake.github.io/),  
- Git.  

**Steps:**
1. Clone the repository:
   ```bash
   git clone https://github.com/your-username/OpenGL-Engine.git
   cd OpenGL-Engine
   ```

2. Generate Makefiles with Premake5:

   ```bash
   premake5 gmake2
   ```

3. Build the project:

   ```bash
   make
   ```

4. Run the executable (inside `bin/` folder):

   ```bash
   ./bin/Debug/OpenGL-Engine
   ```

   *(Path may vary depending on your build configuration)*
---

### 🔹 Windows

**Requirements:**

* [Visual Studio](https://visualstudio.microsoft.com/) (2019 or newer recommended),
* [Premake5](https://premake.github.io/),
* Git.

**Steps:**

1. Clone the repository:

   ```powershell
   git clone https://github.com/your-username/OpenGL-Engine.git
   cd OpenGL-Engine
   ```

2. Run the batch script to generate the Visual Studio project files:

   ```powershell
   GenerateProject.bat
   ```

3. Open the generated `.sln` file in Visual Studio.

4. Build the project (`Debug` or `Release`).

5. Run the compiled executable from the `bin/` directory.

---

## Project Status

👉 This is a **purely hobby project** created for learning purposes.
I'm not aiming for this to be a widely used engine, but rather a **personal exploration of graphics programming, C++, and engine architecture**.

Future goals:

* Scene editor,
* Support for additional graphics APIs (e.g., Vulkan, DirectX),
* Resource management improvements,
* Developer tools (profiler, debug renderer).

---

## License

This project is provided **for educational and hobby purposes only**.
Feel free to explore, learn, and use it as a reference – but keep in mind this is **work-in-progress** with no guarantees of stability.

---

✌️ Thanks for checking out my project!
I’m building this mostly for myself – but if you’d like to learn alongside me or suggest improvements, feel free to open an issue or contact me.
