#include <glm/glm.hpp>
#include "gtest/gtest.h"
#include "aabb.h"

TEST (AABB, isInsideAABB)
{
	AABB aabb = {glm::vec3(-10.0f, 4.0f, -8.0f), glm::vec3(+4.0f, +10.0f, +2.0f)};
	
	EXPECT_TRUE(isInsideAABB(aabb, glm::vec3(0.0f, 5.0f, 0.0f)));
	EXPECT_TRUE(isInsideAABB(aabb, glm::vec3(3.0f, 4.3f, -4.0f)));
	
	EXPECT_FALSE(isInsideAABB(aabb, glm::vec3(-10.5f, 5.0f, 0.0f)));
	EXPECT_FALSE(isInsideAABB(aabb, glm::vec3(5.0f, 0.4f, 0.0f)));
	EXPECT_FALSE(isInsideAABB(aabb, glm::vec3(3.0f, 3.0f, 3.0f)));
}
