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
		void           doWithEntity(Entity::IDType id, std::function<void(Entity&)> observer);
		void           despawnEntity(Entity::IDType id);

		
	private:
		glm::ivec3 boxifyFlooring(glm::vec3 vec);
		glm::ivec3 boxifyCeiling (glm::vec3 vec);
		
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
		
		// i am satisfied with following objects (they are too complex for understanding),
		// but out interfaces seems to be well.
		uint32_t next_entity_id = 0;
		std::list<Entity> entities;
		std::unordered_map<glm::ivec3, std::list<std::list<Entity>::iterator>, hasher> spatial_map;
		std::unordered_map<Entity::IDType, std::pair<glm::ivec3, std::list<std::list<Entity>::iterator>::iterator>> entity_locator;
};

#endif