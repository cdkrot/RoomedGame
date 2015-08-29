#version 330 core

layout (location = 0) in vec3 vertex_modelspace;
uniform mat4 MVP;

void main()
{
	vec4 v      = vec4(vertex_modelspace, 1);
	gl_Position = MVP * v;
}