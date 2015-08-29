#ifndef RENDER_MAIN_INCL
#define RENDER_MAIN_INCL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "world.h"
#include "entity/entity.h"
#include "render/model-cache.h"
#include "game.h"


class RenderMain
{
	public:
		RenderMain(Game* game);
		~RenderMain();
		void run(); // just run.
		void run_once(); // just render once.
	private:
		GLuint vertex_array_object;
		Game* game;
		GLuint gl_program;
		ModelCache model_cache;
};

#endif