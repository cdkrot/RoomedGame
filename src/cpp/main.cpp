#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <iostream>
#include <thread>

int main();
void render_main();

int main()
{
	std::thread render_thread(render_main);
	render_thread.join();
	return 0;
}

void render_main()
{
	// this code is based on opengl-tutorial.org
	// as i understand they don't mind using it
	// for any purpose.
	
	if(not glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		std::terminate();
	}
	
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow( 1024, 768, "Tutorial 01", NULL, NULL); 
	if(window == NULL)
	{
		fprintf(stderr, "Failed to open GLFW window, use opengl 3.3+.\n" );
		glfwTerminate();
		std::terminate();
	}
	
	glfwMakeContextCurrent(window);
	glewExperimental = true;
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW\n");
		glfwTerminate();
		std::terminate();
	}
	
	while (true)
	{
		// Swap buffers
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	
	glfwTerminate();
}
