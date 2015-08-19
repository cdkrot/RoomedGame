#ifndef MODEL_CACHE_INCL
#define MODEL_CACHE_INCL

#include <unordered_map>
#include <utility>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "render/model.h"

class ModelCache
{
	public:
		std::pair<size_t, GLuint> getModelBuffer(const Model* model);
	private:
		std::unordered_map<const Model*, std::pair<size_t, GLuint>> the_cache;
};

#endif