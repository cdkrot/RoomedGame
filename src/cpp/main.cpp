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
	World w;
	w.spawnEntity(new Model({
		-1.0f, -1.0f, 0.0f,
		1.0f, -1.0f, 0.0f,
		0.0f,  1.0f, 0.0f
	}), glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	PositionedObject camera(glm::vec3(0, 0, 0), glm::vec3(0, 0, 0));
	
	std::thread render_thread([](World& w, PositionedObject& camera)
	{
		RenderMain renderer;
		renderer.init();
		renderer.run(w, camera);
		renderer.shutdown();
	}, std::ref(w), std::ref(camera));
	
	render_thread.join();
	
	return 0;
}

