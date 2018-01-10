#version 330 core

in vec2 vTexCoord;

out vec4 color;

struct Material {
	sampler2D diffuse;
};

uniform Material material;

void main()
{
	color = texture(material.diffuse, vTexCoord);
}