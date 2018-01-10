#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 texCoord;

out vec2 vTexCoord;
out vec3 vNormal;
out vec3 vFragPosition;
  
uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main()
{
	vTexCoord = texCoord;
	vFragPosition = vec3(model * vec4(position, 1.0));
	vNormal = mat3(transpose(inverse(model))) * normal;
	gl_Position = projection * view * vec4(vFragPosition, 1.0);
} 