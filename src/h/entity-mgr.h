#ifndef ENTITY_MGR_INCL_H
#define ENTITY_MGR_INCL_H

#include <unordered_map>
#include <limits>
#include "entity/entity.h"
#include "world.h"

class EntityMgr
{
	public:
		EntityMgr() = default;
		~EntityMgr() = default;
		
		World* getEntityWorld(Entity::IDType entity_id);
		void spawnEntityTo(Entity e, World* new_world);
	private:
		Entity::IDType registerNewEntity();
		
		Entity::IDType next_available_id = std::numeric_limits<Entity::IDType>::min();
		std::unordered_map<Entity::IDType, World*> entity_info;
		
		friend class Entity;
};

#endif