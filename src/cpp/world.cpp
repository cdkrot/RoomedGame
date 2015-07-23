// world.h implementation.
#include "world.h"


std::list<Entity> World::getEntitiesIn(AABB aabb)
{
	std::list<Entity> result;
	forEntitiesIn(aabb, [&result](const Entity& e){result.push_back(e);});
	return result;
}
