#define private public
// VERY Temporary.

#include "world-updater.h"

WorldUpdater::WorldUpdater(Game* game): game(game)
{
}

WorldUpdater::~WorldUpdater()
{
}

void WorldUpdater::run_once()
{
	if (glfwGetKey(game->window, GLFW_KEY_ESCAPE) == GLFW_PRESS or glfwWindowShouldClose(game->window))
		game->should_run = false;
	
	float factor = 0.1;
	
	if (glfwGetKey(game->window, GLFW_KEY_UP) == GLFW_PRESS)
		game->camera.position += factor * glm::vec3(0, 0, -1);
	if (glfwGetKey(game->window, GLFW_KEY_DOWN) == GLFW_PRESS)
		game->camera.position += factor * glm::vec3(0, 0, +1);
	if (glfwGetKey(game->window, GLFW_KEY_LEFT) == GLFW_PRESS)
		game->camera.position += factor * glm::vec3(-1, 0, 0);
	if (glfwGetKey(game->window, GLFW_KEY_RIGHT) == GLFW_PRESS)
		game->camera.position += factor * glm::vec3(+1, 0, 0);
}