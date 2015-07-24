#ifndef WORLD_INCL_H
#define WORLD_INCL_H

#include <list>
#include <utility>
#include <functional>
#include <unordered_map>
#include "aabb.h"
#include "entity/entity.h"

class EntityMgr;

class World
{
	public:
		World(EntityMgr* mgr): mgr(mgr) {}
		~World() = default;
		
		std::list<Entity> getEntitiesIn(AABB aabb);
		void              forEntitiesIn(AABB aabb, std::function<void(const Entity&)> observer);
		
	private:
		glm::ivec3 boxifyFlooring(glm::vec3 vec);
		glm::ivec3 boxifyCeiling (glm::vec3 vec);
		void silentlyRemoveEntity(Entity::IDType entity_id);
		void silentlyAddEntity(Entity entity);
		
		const uint32_t box_size_x = 32;
		const uint32_t box_size_y = 32;
		const uint32_t box_size_z = 32;
		
		struct hasher
		{
			size_t operator()(glm::ivec3 vec) const noexcept
			{
				auto hash_int = std::hash<int>();
				return hash_int(vec.x) xor hash_int(vec.y) xor hash_int(vec.z);
			}
		};
		
		const EntityMgr* mgr;
		std::unordered_map<glm::ivec3, std::list<Entity>, hasher> spatial_map;
		std::unordered_map<Entity::IDType, std::pair<glm::ivec3, std::list<Entity>::iterator>> entity_locator;
		friend class EntityMgr;
};

#endif