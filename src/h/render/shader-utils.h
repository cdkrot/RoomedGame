#ifndef SHADER_UTILS_INCL
#define SHADER_UTILS_INCL

#include <utility>
#include <vector>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include "util/optional.h"

Optional<GLuint> loadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path);

// compiles shader, returns error log and compilation status.
std::pair<GLint, std::vector<char>> compileShader(GLuint shader_id, const char* data);

std::pair<GLint, std::vector<char>> compileProgram(GLuint program);

#endif