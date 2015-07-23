#ifndef ENTITY_INCL_H
#define ENTITY_INCL_H

#include <glm/glm.hpp>
#include "model.h"

class Entity
{
	public:
		glm::vec3 position;
		glm::vec3 rotation;
		const Model model;
};

#endif