#ifndef MODEL_INCL_H
#define MODEL_INCL_H

#include <vector>
#include <glm/glm.hpp>
#include "triangle.h"

// models in space of object.
class Model
{
	public:
		Model(const std::vector<Triangle> triangles): triangles(triangles) {}
		~Model() = default;
		
		const std::vector<Triangle>& getTriangles();
	private:
		const std::vector<Triangle> triangles;
};

#endif