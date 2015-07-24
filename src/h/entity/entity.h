#ifndef ENTITY_INCL_H
#define ENTITY_INCL_H

#include <glm/glm.hpp>
#include "model.h"

class EntityMgr;

class Entity
{
	public:
		Entity(EntityMgr& mgr);
		~Entity() = default;
		
		glm::vec3 position;
		glm::vec3 rotation;
		const Model* model;
		
		typedef uint32_t IDType;
		const IDType id;
};

#endif