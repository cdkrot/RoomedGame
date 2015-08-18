#include "entity/entity.h"

Entity::Entity(Callbacks callback, Model* m, IDType id, glm::vec3 pos, glm::vec3 rot) noexcept:
	callback(callback), model(m), id(id), position(pos), rotation(rot)
{
	
}

const Model* Entity::getModel() const noexcept
{
	return model;
}

Entity::IDType Entity::getID() const noexcept
{
	return id;
}

glm::vec3 Entity::getPosition() const noexcept
{
	return position;
}

glm::vec3 Entity::getRotation() const noexcept
{
	return rotation;
}
