// world.h implementation.
#include "world.h"


void World::forEntitiesIn(AABB aabb, std::function<void(Entity&)> observer)
{
	glm::ivec3 vec0 = boxifyFlooring(aabb.lo);
	glm::ivec3 vec1 = boxifyCeiling (aabb.hi);
	
	for (auto x = vec0.x; x != vec1.x; ++x)
		for (auto y = vec0.y; y != vec1.y; ++y)
			for (auto z = vec0.z; z != vec1.z; ++z)
				if (spatial_map.find(glm::ivec3(x, y, z)) != spatial_map.end())
					for (std::list<Entity>::iterator& pEntity: spatial_map.find(glm::ivec3(x, y, z))->second)
						if (isInsideAABB(aabb, pEntity->getPosition()))
							observer(*pEntity);
}

Entity::IDType World::spawnEntity(Model* m, glm::vec3 pos, glm::vec3 rotation)
{
	Entity::IDType id = (next_entity_id++);
	entities.emplace_front(getCallbacksForEntity(), m, id, pos, rotation);
	
	glm::ivec3 vec = boxifyFlooring(pos);
	spatial_map[vec].push_front(entities.begin());
	entity_locator[id] = make_pair(vec, spatial_map[vec].begin());
	
	return id;
}


void World::despawnEntity(Entity::IDType id)
{
	if (entity_locator.find(id) == entity_locator.end())
		return; // throw an error?
	
	auto entityInSpatialMap = entity_locator.find(id)->second;
	entity_locator.erase(entity_locator.find(id));
	
	entities.erase(*(entityInSpatialMap.second));
	spatial_map[entityInSpatialMap.first].erase(entityInSpatialMap.second);
}

void World::doWithEntity(Entity::IDType id, std::function<void(Entity&)> observer)
{
	if (entity_locator.find(id) == entity_locator.end())
		return; // throw an error?
	
	observer(*(*(entity_locator[id].second)));
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

Entity::Callbacks World::getCallbacksForEntity()
{
	Entity::Callbacks res;
	res.onMove = std::function<void(Entity::IDType)>([](Entity::IDType){});
	return res;
}
