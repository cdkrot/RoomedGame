#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include <ctime>
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
		PositionedObject(glm::vec3(-1, 0.5, 0), glm::vec3(0, 0, 0)), // Camera.
		nullptr, // window handle.
		true // running?
	};
	
	game.world.spawnEntity(new Model({
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f,
	}), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		
	
	game.world.spawnEntity(new Model({
		-1.0f, -1.5f, -1.0f,
		1.0f, -1.5f, -1.0f,
		0.0f, -1.5f, 1.0f
	}), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
		

	
	
	// throwed away multithreading for a while
	RenderMain   renderer(&game);
	WorldUpdater updater (&game); // polls input and runs the update.
	
	const std::clock_t clocks_per_upd = CLOCKS_PER_SEC / 40;
	std::clock_t prev = clock();
	std::clock_t lag = 0;
	while (game.should_run)
	{
		std::clock_t now = clock();
		lag += now - prev, prev = now;
		
		if (lag >= std::clock_t(5 * CLOCKS_PER_SEC))
			lag = 0;
		else if (lag < clocks_per_upd)
		{
			long nanosec = (clocks_per_upd - lag) * (1000000000 / CLOCKS_PER_SEC);
			timespec req = {0, nanosec};
			nanosleep(&req, NULL);
			lag += (clocks_per_upd - lag);
		}
		else while (lag >= clocks_per_upd)
			updater.run_once(), lag -= clocks_per_upd;
		renderer.run_once();
	}
	
	return 0;
}

