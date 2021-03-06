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
		World()  = default;
		~World() = default;
		
		Entity::IDType spawnEntity(Model* m, glm::vec3 pos, glm::vec3 rotation);
		void           forEntitiesIn(AABB aabb, std::function<void(Entity&)> observer);
		//void           forEntitiesIn(AABB aabb, std::function<void(const Entity&)> observer) const;
		void           doWithEntity(Entity::IDType id, std::function<void(Entity&)> observer);
		void           despawnEntity(Entity::IDType id);

		
	private:
		glm::ivec3 boxifyFlooring(glm::vec3 vec) const noexcept;
		glm::ivec3 boxifyCeiling (glm::vec3 vec) const noexcept;
		
		Entity::Callbacks getCallbacksForEntity();
		
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
		
		uint32_t next_entity_id = 0;
		std::unordered_map<Entity::IDType, std::pair<glm::ivec3, Entity>> entities;
		std::unordered_map<glm::ivec3, std::list<decltype(entities)::iterator>, hasher> spatial_map;

};

#endif