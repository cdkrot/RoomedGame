#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "world.h"
#include "world-updater.h"
#include "entity/entity.h"
#include "render/model.h"
#include "render/render-main.h"

int main()
{
	Game game
	{
		World(),
		PositionedObject(glm::vec3(-1, 0, 0), glm::vec3(0, 0, 0)), // Camera.
		nullptr, // window handle.
		true // running?
	};
	
	game.world.spawnEntity(new Model({
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	}), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		
	
	// throwed away multithreading for a while
	RenderMain   renderer(&game);
	WorldUpdater updater (&game); // polls input and runs the update.
	
	while (game.should_run)
	{
		updater.run_once();
		renderer.run_once();
	}
	
	return 0;
}

