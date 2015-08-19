#include "entity/entity.h"


PositionedObject::PositionedObject(glm::vec3 pos, glm::vec3 rot) noexcept: position(pos), rotation(rot)
{
	
}

glm::vec3 PositionedObject::getPosition() const noexcept
{
	return position;
}

glm::vec3 PositionedObject::getRotation() const noexcept
{
	return rotation;
}

Entity::Entity(Callbacks callback, Model* m, IDType id, glm::vec3 pos, glm::vec3 rot) noexcept:
	PositionedObject(pos, rot), callback(callback), model(m), id(id)
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
