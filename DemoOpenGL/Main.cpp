#include<iostream>
#include<glad/glad.h>
#include<GLFW/glfw3.h>

#include"shaderClass.h"
#include"VAO.h"
#include"VBO.h"
#include"EBO.h"

int main()
{
	// Initialize GLFW
	glfwInit();

	// Tell GLFW what verison of OpenGL we are using
	// In this case we are using OpenGL 3.3
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

	// Tell GLFW we are using the CORE profile
	// So that means we only have the modern functions
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	// Vertices coordinates
	GLfloat vertices[] =
	{ //            COORDINATES                           /       COLORS        //    
		-0.5f     , -0.5f * float(sqrt(3)) / 3,     0.0f,   0.8f, 0.3f,  0.02f,	// Lower left corner
		 0.5f     , -0.5f * float(sqrt(3)) / 3,     0.0f,	0.8f, 0.3f,  0.02f,	// Lower right corner
		 0.0f     , 0.5f  * float(sqrt(3)) * 2 / 3, 0.0f,	1.0f, 0.6f,  0.32f, // Upper corner
		-0.5f / 2 , 0.5f  * float(sqrt(3)) / 6,     0.0f,	0.9f, 0.45f, 0.17f, // Inner left
		 0.5f / 2 , 0.5f  * float(sqrt(3)) / 6,     0.0f,	0.9f, 0.45f, 0.17f, // Inner right
		 0.0f     , -0.5f * float(sqrt(3)) * 1 / 3, 0.0f,	0.8f, 0.3f,  0.02f  // Inner down
	};

	GLuint indices[] =
	{
		0, 3, 5, // Lower left triangle
		3, 2, 4, // Lower right traingle
		5, 4, 1	 // Upper triangle
	};

	// Create a GLFW window object of 800 by 800 pixels, naming it "OPENGLDEMO"
	GLFWwindow* window = glfwCreateWindow(800, 800, "OPENGLDEMO", NULL, NULL);

	// Error check if the window fails to create
	if (window == NULL)
	{
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}
	// Introduce the window into the current context
	glfwMakeContextCurrent(window);

	//Load GLAD so it configures OpenGL
	gladLoadGL();

	// Specify the viewport of openGL in the Window
	// In this case the viewport goes from x = 0, y = 0, to x = 800 
	glViewport(0, 0, 800, 800);

    // Generates Shader object using shaders default.vert and default.frag
    Shader shaderProgram("default.vert", "default.frag");

    // Generates Vertex Array Object and binds it
    VAO VAO1;
    VAO1.Bind();

    // Generates Vertex Buffer Object and links it to vertices
    VBO VBO1(vertices, sizeof(vertices));
    // Generates Elements Buffer Object and links it to indices
    EBO EBO1(indices, sizeof(indices));

    // Links VBO attributes such as coordinates and colors to VAO
    VAO1.LinkAttrib(VBO1, 0, 3, GL_FLOAT, 6 * sizeof(float), (void*)0);
    VAO1.LinkAttrib(VBO1, 1, 3, GL_FLOAT, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    // Unbind all to prevent accidentally modifying them
    VAO1.Unbind();
    VBO1.Unbind();
    EBO1.Unbind();

    // Gets ID of uniform called "scale"
    GLuint uniID = glGetUniformLocation(shaderProgram.ID, "scale");

	// Main while loop
	while (!glfwWindowShouldClose(window))
	{
		// Specify the color of the background
		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		// Clean the back buffer and assign the new color to it
		glClear(GL_COLOR_BUFFER_BIT);
		// Tell OpenGL which Shader Program we want to use
        shaderProgram.Activate();
        // Assigns a value Shader to the unform; NOTE: Must always be done after activation in the Shader Program
        glUniform1f(uniID, 0.8f);
		// Bind the VAO so OpenGL knows to use it
        VAO1.Bind();
		// Draw the treiangle using the GL_TRIANGLES primitive
		glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		// Swap the back buffer with the front buffer
		glfwSwapBuffers(window);

		// Take care of all GLFW events
		glfwPollEvents();
	}

	// Delete all the objects weve created
    VAO1.Delete();
    VBO1.Delete();
    EBO1.Delete();
    shaderProgram.Delete();

	// Delete the window before the program
	glfwDestroyWindow(window);
	// Terminate GLFW before enfing the program
	glfwTerminate();
	return 0;
}