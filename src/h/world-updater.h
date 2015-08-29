#ifndef WORLD_UPDATER_INCL
#define WORLD_UPDATER_INCL

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "world.h"
#include "entity/entity.h"
#include "game.h"


class WorldUpdater
{
	public:
		WorldUpdater(Game* game);
		~WorldUpdater();
		void run_once();
	private:
		Game* game;
};

#endif