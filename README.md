# OpenGL Colored Triangles Demo

This project demonstrates rendering a custom colored triangle mesh using modern OpenGL (version 3.3 core profile). It leverages GLFW for window/context creation, GLAD for OpenGL function loading, and a set of helper classes (Shader, VAO, VBO, EBO) to manage OpenGL objects cleanly.

## Overview
The application creates a window and draws a composite figure made of three triangles arranged as a stylized hexagon or triangular pattern with color gradients. The rendering uses indexed vertex drawing and shader-based coloring with a uniform to scale the vertices.

---

### Features
+ Modern OpenGL (3.3 core) rendering pipeline  
+ Indexed drawing with `glDrawElements`  
+ Vertex positions and colors specified in a single interleaved array  
+ Use of custom shader programs for vertex transformation and fragment coloring  
+ Clean resource management with custom wrapper classes for VAO, VBO, and EBO  
+ Interactive window with GLFW, ready for future input handling or animation  

---

### Files & Components

#### Main program (`main.cpp`)
- Initializes GLFW and GLAD  
- Creates an 800x800 window  
- Defines vertex data (positions + colors) and indices for three triangles forming the composite shape  
- Loads and compiles shaders via the Shader class  
- Sets up VAO, VBO, and EBO for vertex attribute management  
- Uses a uniform variable `scale` in the vertex shader to control the size of the rendered shape  
- Renders the triangles in a loop until the window is closed  
- Properly cleans up OpenGL resources on exit  

#### Shader files (`default.vert`, `default.frag`)

**default.vert (vertex shader):**  
+ Accepts vertex positions and colors as attributes  
+ Uses a uniform `scale` to scale vertex positions uniformly  
+ Passes vertex color to the fragment shader  

**default.frag (fragment shader):**  
+ Receives interpolated colors from the vertex shader  
+ Outputs the final fragment color  

#### Helper classes

**Shader**  
+ Manages compiling, linking, and activating shader programs  
+ Provides methods for setting uniforms, such as `glUniform1f` for floats  

**VAO (Vertex Array Object)**  
+ Encapsulates the creation and binding of OpenGL VAOs  
+ Links vertex attribute pointers to VBOs  

**VBO (Vertex Buffer Object)**  
+ Encapsulates the creation and binding of OpenGL VBOs  
+ Uploads vertex data to the GPU  

**EBO (Element Buffer Object)**  
+ Encapsulates creation and binding of EBOs  
+ Uploads index data for indexed drawing  

---

### Vertex Data Explanation

The `vertices` array contains six vertices with:  
+ Coordinates: 3 floats (x, y, z), forming a pattern resembling a triangle subdivided into smaller triangles.  
+ Colors: 3 floats (r, g, b), giving a warm orange gradient effect.  

Indices define three triangles using these vertices:  
+ Lower left triangle: vertices 0, 3, 5  
+ Lower right triangle: vertices 3, 2, 4  
+ Upper triangle: vertices 5, 4, 1  

---

### Important Notes
+ The uniform `scale` controls the overall size of the rendered shape. Adjusting this value modifies the size dynamically.  
+ The issue with a "trapezoid" shape previously was caused by an incorrect scale uniform value.  
+ The viewport is set to 800x800 pixels, matching the GLFW window size.  
+ The shader paths `"default.vert"` and `"default.frag"` must be present in the executable's working directory.  

---

### How to Build and Run
+ Ensure GLFW, GLAD, and OpenGL development libraries are installed.  
+ Place `default.vert` and `default.frag` shaders in the working directory.  
+ Compile the project with your favorite C++ compiler, linking GLFW and OpenGL.  
+ Run the executable; an OpenGL window displaying colored triangles will open.  
+ Close the window to terminate the program cleanly.  

---

### Real Visual Output
+ A composite shape made of 3 triangles is rendered on screen.  
+ Each vertex has a color with orange-ish hues (ranging from dark orange to light orange).  
+ The colors smoothly interpolate across the triangles thanks to the vertex colors and the shader.  
+ The shape looks like a triangular cluster with inner smaller triangles, shaded in orange tones.  
+ The background is dark blue.  
+ The shape’s size is controlled by the `scale` uniform in the shader, affecting its overall size on screen.

![Warm Orange Subdivided Triangle Composed of Three Adjacent Triangles](https://github.com/user-attachments/assets/1816d17a-eb90-443f-96b4-7885156cbd4d)

*figure 1: Warm Orange Subdivided Triangle Composed of Three Adjacent Triangles*
