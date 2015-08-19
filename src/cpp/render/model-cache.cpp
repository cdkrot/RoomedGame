#include "render/model-cache.h"

std::pair<size_t, GLuint> ModelCache::getModelBuffer(const Model* m)
{
	if (the_cache.find(m) != the_cache.end())
		return the_cache[m];
	else
	{
		const GLfloat* data = (*m).getVertices().data();
		GLuint buffer;
		glGenBuffers(1, &buffer);
		glBindBuffer(GL_ARRAY_BUFFER, buffer);
		glBufferData(GL_ARRAY_BUFFER, (*m).getVertices().size() * sizeof(GLfloat), data, GL_STATIC_DRAW);
		
		return (the_cache[m] = std::make_pair((*m).getVertices().size(), buffer));
	}
}