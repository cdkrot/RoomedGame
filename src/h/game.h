#ifndef GAME_H_INCL

#define GAME_H_INCL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "world.h"
#include "entity/entity.h"

// resources, which have to be shared between different objects.
struct Game
{
	World world;
	PositionedObject camera;
	GLFWwindow* window;
	bool should_run;
};

#endif