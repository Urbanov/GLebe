#pragma once
#include <glm/glm.hpp>

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 tex_coord;

	Vertex() = default;
	Vertex(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& tex_coord);
};
