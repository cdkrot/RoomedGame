#include "render/shader-utils.h"
#include "util/read-file.h"

std::pair<GLint, std::vector<char>> compileShader(GLuint shader_id, const char* data)
{
	glShaderSource(shader_id, 1, &data, NULL);
	glCompileShader(shader_id);
	
	GLint result, log_len;
	
	glGetShaderiv(shader_id, GL_COMPILE_STATUS, &result);
	glGetShaderiv(shader_id, GL_INFO_LOG_LENGTH, &log_len);
	std::vector<char> compilation_log(log_len);
	glGetShaderInfoLog(shader_id, log_len, NULL, compilation_log.data());
	
	return make_pair(result, compilation_log);
}

std::pair<GLint, std::vector<char>> compileProgram(GLuint program)
{
	glLinkProgram(program);
	
	GLint result, log_len;
	
	glGetProgramiv(program, GL_LINK_STATUS, &result);
	glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_len);
	std::vector<char> compilation_log(log_len);
	glGetProgramInfoLog(program, log_len, NULL, compilation_log.data());
	
	return make_pair(result, compilation_log);
}

Optional<GLuint> loadShaders(const std::string& vertex_file_path, const std::string& fragment_file_path)
{
	GLuint   vertex_shader_id = glCreateShader(GL_VERTEX_SHADER);
	GLuint fragment_shader_id = glCreateShader(GL_FRAGMENT_SHADER);
	
	Optional<std::vector<char>> vertex_shader_code = readFile(vertex_file_path);
	Optional<std::vector<char>> fragment_shader_code = readFile(fragment_file_path);
	
	if ((not fragment_shader_code) or (not vertex_shader_code))
		return NullOpt;
	
	auto vertex_shader_log   = compileShader(  vertex_shader_id,   vertex_shader_code->data());
	auto fragment_shader_log = compileShader(fragment_shader_id, fragment_shader_code->data());
	
	if (not vertex_shader_log.second.empty())
		fprintf(stderr, "During compilation of %s:\n%s\n", vertex_file_path.c_str(), vertex_shader_log.second.data());
	
	if (not fragment_shader_log.second.empty())
		fprintf(stderr, "During compilation of %s:\n%s\n", fragment_file_path.c_str(), fragment_shader_log.second.data());
	
	if (vertex_shader_log.first == GL_FALSE or fragment_shader_log.first == GL_FALSE)
		return NullOpt;
 
	GLuint program = glCreateProgram();
	glAttachShader(program, vertex_shader_id);
	glAttachShader(program, fragment_shader_id);
	
	auto program_log = compileProgram(program);
	if (not program_log.second.empty())
		fprintf(stderr, "During linking of %s and %s:\n%s\n",
		       vertex_file_path.c_str(), fragment_file_path.c_str(), program_log.second.data());
	
	glDeleteShader(vertex_shader_id);
	glDeleteShader(fragment_shader_id);
	
	if (program_log.first == GL_FALSE)
		return NullOpt;
	else
		return program;
}