#version 330 core

layout (location = 0) in vec3 position;
layout (location = 2) in vec2 texCoord;

out vec2 vTexCoord;
  
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vTexCoord = texCoord;
	mat4 staticView = view;
	staticView[3] = vec4(0.0, 0.0, 0.0, 1.0);
	gl_Position = projection * staticView * model * vec4(position, 1.0);
}