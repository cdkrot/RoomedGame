#include "entity-mgr.h"
#include <stdexcept>

World* EntityMgr::getEntityWorld(Entity::IDType entity_id)
{
	if (entity_info.find(entity_id) == entity_info.end())
		return nullptr;
	else
		return entity_info.find(entity_id)->second;
}

Entity::IDType EntityMgr::registerNewEntity()
{
	if (next_available_id == std::numeric_limits<Entity::IDType>::max())
		throw std::runtime_error("I can't believe you created so much entities");
	
	return (next_available_id++);
}

void EntityMgr::spawnEntityTo(Entity entity, World* new_world)
{
	if (entity_info.find(entity.id) != entity_info.end())
	{
		World* old_world = entity_info.find(entity.id)->second;
		old_world->silentlyRemoveEntity(entity.id);
		entity_info.erase(entity_info.find(entity.id));
	}
	
	if (new_world != nullptr)
	{
		new_world->silentlyAddEntity(entity);
		entity_info[entity.id] = new_world;
	}
}
