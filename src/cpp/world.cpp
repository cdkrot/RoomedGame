// world.h implementation.
#include "world.h"


std::list<Entity> World::getEntitiesIn(AABB aabb)
{
	std::list<Entity> result;
	forEntitiesIn(aabb, [&result](const Entity& e){result.push_back(e);});
	return result;
}

void World::forEntitiesIn(AABB aabb, std::function<void(const Entity&)> observer)
{
	glm::ivec3 vec0 = boxifyFlooring(aabb.lo);
	glm::ivec3 vec1 = boxifyCeiling (aabb.hi);
	
	for (auto x = vec0.x; x != vec1.x; ++x)
		for (auto y = vec0.y; y != vec1.y; ++y)
			for (auto z = vec0.z; z != vec1.z; ++z)
				if (spatial_map.find(glm::ivec3(x, y, z)) != spatial_map.end())
					for (const Entity& e: spatial_map.find(glm::ivec3(x, y, z))->second)
						if (isInsideAABB(aabb, e.position))
							observer(e);
}

glm::ivec3 World::boxifyFlooring(glm::vec3 vec)
{
	auto x = static_cast<int>(floorf(vec.x / box_size_x));
	auto y = static_cast<int>(floorf(vec.y / box_size_y));
	auto z = static_cast<int>(floorf(vec.z / box_size_z));
	
	return glm::ivec3(x, y, z);
}

glm::ivec3 World::boxifyCeiling (glm::vec3 vec)
{
	auto x = static_cast<int>(ceilf(vec.x / box_size_x));
	auto y = static_cast<int>(ceilf(vec.y / box_size_y));
	auto z = static_cast<int>(ceilf(vec.z / box_size_z));
	
	return glm::ivec3(x, y, z);
}

void World::silentlyRemoveEntity(Entity::IDType entity_id)
{
	if (entity_locator.find(entity_id) == entity_locator.end())
		return;
	
	auto res = entity_locator.find(entity_id)->second;
	entity_locator.erase(entity_locator.find(entity_id));
	
	spatial_map[res.first].erase(res.second);
}

void World::silentlyAddEntity(Entity entity)
{
	// asserting, that entity not exist in world
	// (it is internal api, so we don't check this thing here).
	
	glm::ivec3 vec = boxifyFlooring(entity.position);
	spatial_map[vec].push_front(entity);
	entity_locator[entity.id] = make_pair(vec, spatial_map[vec].begin());
}