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
