#include "world-updater.h"

WorldUpdater::WorldUpdater(Game* game): game(game)
{
}

WorldUpdater::~WorldUpdater()
{
}

void WorldUpdater::run_once()
{
	if (glfwGetKey(game->window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		game->should_run = false;
}