#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <thread>
#include "world.h"
#include "entity/entity.h"
#include "render/model.h"
#include "render/render-main.h"

int main()
{
	RenderMain renderer;
	renderer.init();
	
	World w;
	w.spawnEntity(new Model({
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f
	}), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	PositionedObject camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	
	renderer.run(w, camera);
	
	// no idea why, but this code fails to run (via sigsegv on first opengl call), but the above
	// succeeds.
	//std::thread render_thread([&renderer, &w, &camera](){renderer.run(w, camera);});
	//render_thread.join();
	
	renderer.shutdown();
	
	return 0;
}

