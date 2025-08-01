# 🟠 OpenGL Colored Triangles Demo

This project demonstrates rendering a custom-colored triangle mesh using **modern OpenGL (version 3.3 core profile)**. It leverages **GLFW** for window/context creation, **GLAD** for OpenGL function loading, and a set of helper classes (`Shader`, `VAO`, `VBO`, `EBO`) for clean management of OpenGL objects.

---

## 📚 Table of Contents

- [🎯 Overview](#-overview)
- [✨ Features](#-features)
- [📁 Files & Components](#-files--components)
  - [🔹 Main Program (`main.cpp`)](#-main-program-maincpp)
  - [🧾 Shader Files (`default.vert`, `default.frag`)](#-shader-files-defaultvert-defaultfrag)
  - [🛠 Helper Classes](#-helper-classes)
- [🧬 Vertex Data Explanation](#-vertex-data-explanation)
- [⚠️ Important Notes](#️-important-notes)
- [⚙️ How to Build and Run](#️-how-to-build-and-run)
- [🎨 Real Visual Output](#-real-visual-output)

---

## 🎯 Overview

The application creates a window and draws a composite figure made of three triangles arranged in a **stylized hexagon or triangular pattern** with **color gradients**. The rendering uses **indexed vertex drawing** and **shader-based coloring**, with a **uniform to scale** the vertices.

---

## ✨ Features

- ✅ Modern OpenGL (3.3 core) rendering pipeline  
- ✅ Indexed drawing with `glDrawElements`  
- ✅ Vertex positions and colors specified in a single interleaved array  
- ✅ Custom shaders for vertex transformation and fragment coloring  
- ✅ Clean wrapper classes for VAO, VBO, and EBO  
- ✅ Interactive window via GLFW (ready for animation or input handling)  

---

## 📁 Files & Components

### 🔹 Main Program (`main.cpp`)

- Initializes **GLFW** and **GLAD**  
- Creates a **800x800** window  
- Defines vertex and index data for a custom triangle shape  
- Loads and uses shaders via the `Shader` class  
- Sets up `VAO`, `VBO`, and `EBO`  
- Uses a `scale` uniform to adjust rendered size  
- Renders in a loop and cleans up on exit  

---

### 🧾 Shader Files (`default.vert`, `default.frag`)

#### 📌 `default.vert` (vertex shader)
- Accepts vertex positions and colors  
- Scales positions using a `uniform float scale`  
- Passes color to the fragment shader  

#### 📌 `default.frag` (fragment shader)
- Receives interpolated colors  
- Outputs final color to the screen  

---

### 🛠 Helper Classes

| Class  | Responsibility |
|--------|----------------|
| **Shader** | Compiles, links, and activates GLSL programs. Provides uniform-setting methods. |
| **VAO** | Encapsulates VAO creation and attribute pointer linkage. |
| **VBO** | Handles uploading vertex data to the GPU. |
| **EBO** | Manages index data for efficient drawing using `glDrawElements`. |

---

## 🧬 Vertex Data Explanation

- Each vertex: **6 floats**  
  - 3 for **position** `(x, y, z)`  
  - 3 for **color** `(r, g, b)`  
- Total of **6 vertices**  
- Forms **3 triangles** using **indexed drawing**

**Triangle Indices:**

| Triangle         | Indices      |
|------------------|--------------|
| Lower Left       | `0, 3, 5`     |
| Lower Right      | `3, 2, 4`     |
| Upper Triangle   | `5, 4, 1`     |

---

## ⚠️ Important Notes

- `scale` is a **uniform float** that controls the shape’s size dynamically  
- A previous trapezoid shape was caused by an incorrect `scale` value  
- Viewport size: **800x800 pixels**, matching the GLFW window  
- Make sure shader files `default.vert` and `default.frag` are in the **working directory**

---

## ⚙️ How to Build and Run

1. ✅ Install GLFW, GLAD, and OpenGL development libraries  
2. ✅ Place `default.vert` and `default.frag` in the working directory  
3. ✅ Compile with a C++ compiler, linking against OpenGL and GLFW  
4. ✅ Run the executable  
5. ✅ Close the window to terminate the program  

---

## 🎨 Real Visual Output

- The shape consists of **3 smoothly-shaded triangles**  
- Each vertex uses a **warm orange hue** (dark to light gradient)  
- The background is **dark blue**  
- Colors are smoothly interpolated across the triangles  
- Shape resembles a **triangular cluster**, like a **stylized subdivided triangle**

![Warm Orange Subdivided Triangle Composed of Three Adjacent Triangles](https://github.com/user-attachments/assets/1816d17a-eb90-443f-96b4-7885156cbd4d)

*Figure 1: Warm Orange Subdivided Triangle Composed of Three Adjacent Triangles*

---

# 🎨 OpenGL Lighting & Texturing Engine — Second Sub-Project

## Overview

This sub-project is an OpenGL-based graphics engine focused on **lighting**, **texturing**, and **efficient buffer management** using modern OpenGL practices. It features:

- Multiple light types (point, directional, spotlight) with ambient, diffuse, and specular components.
- Texture loading and management using the popular `stb_image` library.
- Abstractions for Vertex Buffer Objects (VBO), Element Buffer Objects (EBO), and Vertex Array Objects (VAO).
- A flexible shader class that handles shader loading, compiling, linking, and error checking.

This codebase serves as a solid foundation for rendering 3D objects with realistic lighting and texture effects.

---

## 📑 Table of Contents

- [🎯 Features](#-features)  
- [🗂️ Code Structure](#️-code-structure)  
- [⚙️ How It Works Together](#️-how-it-works-together)  
- [🚀 How to Use](#-how-to-use)  
- [🔮 Future Plans](#-future-plans)  
- [📦 Dependencies](#-dependencies)  

---

## 🎯 Features

### 1. **Shaders**

- **Lighting Shaders** (`default.frag`, `default.vert`):
  - Support for **point light**, **directional light**, and **spotlight**.
  - Implements the classic Phong lighting model with ambient, diffuse, and specular terms.
  - Uses multiple textures for diffuse and specular maps.
  - Calculates lighting effects per fragment for realistic shading.

- **Light Source Shaders** (`light.frag`, `light.vert`):
  - Simple shaders to render light sources as colored objects in the scene.

### 2. **Texture Management**

- Loads images using `stb_image`.
- Supports various texture types, formats, and pixel types.
- Configures texture wrapping, filtering, and mipmapping for quality and performance.
- Manages texture binding to texture units and uniform communication with shaders.

### 3. **Buffer Management**

- **VBO (Vertex Buffer Object)**: Stores vertex data in GPU memory.
- **EBO (Element Buffer Object)**: Stores vertex indices for indexed drawing.
- **VAO (Vertex Array Object)**: Encapsulates vertex attribute setup for easy binding.
- Each class manages its OpenGL resource lifecycle (generate, bind, unbind, delete).

### 4. **Shader Class**

- Loads shader source code from files.
- Compiles vertex and fragment shaders, linking them into a shader program.
- Provides detailed error output for debugging.
- Simplifies activating and deleting shader programs.

---

## 🗂️ Code Structure

/Shaders
├─ default.frag # Fragment shader with lighting calculations
├─ default.vert # Vertex shader passing vertex data and matrices
├─ light.frag # Fragment shader for light source rendering
└─ light.vert # Vertex shader for light source rendering

/Source
├─ Texture.cpp # Texture loading and management
├─ VBO.cpp # Vertex Buffer Object abstraction
├─ EBO.cpp # Element Buffer Object abstraction
├─ VAO.cpp # Vertex Array Object abstraction
└─ ShaderClass.cpp # Shader loading, compiling, linking, and error handling

---

## ⚙️ How It Works Together

1. **ShaderClass** loads and compiles the shaders (`default` for objects, `light` for light sources).
2. **Texture** loads images and binds them to OpenGL texture units.
3. **VBO**, **EBO**, and **VAO** manage geometry data and how it’s sent to the GPU.
4. During rendering:
   - The **camera** and **model** matrices are passed to shaders.
   - Lighting parameters (light position, color, camera position) control shading.
   - Textures are sampled for diffuse and specular lighting contributions.
5. The fragment shader computes realistic lighting with Phong shading per pixel.

---

## 🚀 How to Use

- Include the shader source files in your project.
- Use the **Shader** class to load and activate your shaders.
- Load textures with the **Texture** class and bind them to texture units.
- Create and bind your geometry using **VBO**, **EBO**, and **VAO** classes.
- Pass uniforms like transformation matrices and lighting parameters before drawing.
- Render objects with proper lighting and texture effects.

---

## 📦 Dependencies

- OpenGL 3.3 or higher  
- `GLFW` or similar for window/context creation (not included here)  
- `GLAD` or similar OpenGL function loader (not included here)  
- `stb_image.h` for texture loading  

---

Feel free to explore and extend this project! If you want to merge it with other sub-projects later, just reach out.

---
