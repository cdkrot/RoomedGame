#ifndef WORLD_INCL_H
#define WORLD_INCL_H

#include <list>
#include <functional>
#include <unordered_map>
#include "aabb.h"
#include "entity/entity.h"

class World
{
	public:
		World() = default;
		~World() = default;
		
		std::list<Entity> getEntitiesIn(AABB aabb);
		void              forEntitiesIn(AABB aabb, std::function<void(const Entity&)> observer);
		
		void addEntity(Entity entity);
	private:
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

		
		std::unordered_map<glm::ivec3, std::list<Entity>, hasher> spatialMap;
		
};

#endif