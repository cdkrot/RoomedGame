#ifndef MODEL_INCL_H
#define MODEL_INCL_H

#include <initializer_list>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

// models in space of object.
class Model
{
	// under construction.
	public:
		Model(const std::vector<GLfloat>& data)  noexcept: data(data) {}
		Model(const std::vector<GLfloat>&& data) noexcept: data(data) {}
		Model(const std::initializer_list<GLfloat> data)  noexcept: data(data) {}
		Model()  noexcept = default;
		~Model() noexcept = default;
		
		const std::vector<GLfloat>& getVertices() const noexcept {return data;}
	private:
		const std::vector<GLfloat> data;
};

#endif