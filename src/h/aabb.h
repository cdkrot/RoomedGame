#ifndef AABB_INCL_H
#define AABB_INCL_H

#include <glm/glm.hpp>

// triangles must be clockwise.
struct AABB
{
	glm::vec3 lo;
	glm::vec3 hi;
};

inline bool isInsideAABB(AABB aabb, glm::vec3 point)
{
	return (aabb.lo.x <= point.x and aabb.lo.y <= point.y and aabb.lo.z <= point.z)
	   and (aabb.hi.x >= point.x and aabb.hi.y >= point.y and aabb.hi.z >= point.z);
}

#endif