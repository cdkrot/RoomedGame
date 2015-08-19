#ifndef RENDER_MAIN_INCL
#define RENDER_MAIN_INCL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "world.h"
#include "entity/entity.h"
#include "render/model-cache.h"


class RenderMain
{
	public:
		void init(); // run library initilization
		void run(const World& world, const PositionedObject& camera); // just run.
		void requestStop();
		void shutdown(); // run library shutdowns.
	private:
		GLuint vertex_array_object;
		bool should_run = true;
		GLFWwindow* window;
		ModelCache model_cache;
};

#endif