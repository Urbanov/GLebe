#include "vertex.h"

Vertex::Vertex(const glm::vec3& position, const glm::vec3& normal, const glm::vec2& tex_coord)
	: position(position)
	, normal(normal)
	, tex_coord(tex_coord)
{}