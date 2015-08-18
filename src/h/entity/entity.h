#ifndef ENTITY_INCL_H
#define ENTITY_INCL_H

#include <functional>
#include <glm/glm.hpp>
#include "model.h"

class Entity
{
	public:
		typedef uint32_t IDType;
		struct Callbacks
		{
			std::function<void(IDType id)> onMove;
		};
		
		// To be called by World::spawnEntity ONLY.
		Entity(Callbacks callback, Model* m, IDType id, glm::vec3 pos, glm::vec3 rotation) noexcept;
		const Model* getModel()    const noexcept;
		IDType       getID()       const noexcept;
		glm::vec3    getPosition() const noexcept;
		glm::vec3    getRotation() const noexcept;
		
	private:
		const Callbacks callback;
		const Model* model;
		const IDType id;
		glm::vec3 position;
		glm::vec3 rotation;
};

#endif