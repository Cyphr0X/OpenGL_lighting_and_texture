✅ 1st Code: Drawing a Custom Triangle with VAO, VBO, and EBO

Purpose:
This code demonstrates a basic OpenGL application that initializes a window and renders a colorful triangle (actually a stylized triangle made up of 3 sub-triangles) using modern OpenGL practices.

Key Features:
+  GLFW & GLAD: Used to create a window and handle OpenGL function loading.
+  Shader Management: Custom vertex and fragment shaders are compiled and used.
+  Vertex Definition: The vertices array defines six 3D vertices, each with a position and color attribute.
+  Indexing: The indices array groups the vertices into three triangles for efficient drawing.

Abstraction Layers:
+  VAO (Vertex Array Object): Manages the vertex attribute configuration.
+  VBO (Vertex Buffer Object): Stores vertex data.
+  EBO (Element Buffer Object): Stores index data.

Uniforms: A scale uniform is sent to the shader to allow for transformation or animation.

Rendering Loop:
+  Clears the screen with a custom color.
+  Activates the shader program.
+  Draws the triangle using glDrawElements.

Outcome:
Displays a simple multi-colored triangle composed of three sub-triangles, demonstrating foundational OpenGL rendering, buffer abstraction, and shader integration.
