#include "render/render-main.h"
#include "render/shader-utils.h"
#include "world.h"
#include "aabb.h"

void RenderMain::init()
{
	// this code is based on opengl-tutorial.org
	
	if(!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW\n");
		std::terminate();
	}
	
	glfwWindowHint(GLFW_SAMPLES, 4); // 4x antialiasing
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	window = glfwCreateWindow( 1024, 768, "roomed-game", NULL, NULL); 
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
}

void RenderMain::requestStop()
{
	should_run = false;
}

void RenderMain::run(const World& world, const PositionedObject& camera)
{
	glClearColor(0.0f, 0.0f, 0.4f, 0.0f);
	
	GLuint gl_program = *loadShaders("res/vertex.glsl", "res/fragment.glsl");
	glGenVertexArrays(1, &vertex_array_object);
	glBindVertexArray(vertex_array_object);
	
	while (should_run and glfwWindowShouldClose(window) == 0) // temporary.
	{
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(gl_program);
		glEnableVertexAttribArray(0);
		
		
		AABB cameraAABB = makeCenteredAABB(camera.getPosition(), 100.0);
		auto drawEntity = std::function<void(const Entity&)>([this](const Entity& e) -> void
		{
			auto buffer_info = (this->model_cache).getModelBuffer(e.getModel());
			glBindBuffer(GL_ARRAY_BUFFER, buffer_info.second);
			glVertexAttribPointer(
				0,                     // shader attribute id
				buffer_info.first / 3, // size.
				GL_FLOAT,              // type
				GL_FALSE,              // normalization
				0,                     // stride,
				static_cast<void*>(0)  // offset.
			);
			
			fprintf(stderr, "Requested render\n");
			glDrawArrays(GL_TRIANGLES, 0, buffer_info.first / 3);
		});
		
		world.forEntitiesIn(cameraAABB, drawEntity);
		
		glDisableVertexAttribArray(0);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
}

void RenderMain::shutdown()
{
	glfwTerminate();
}
