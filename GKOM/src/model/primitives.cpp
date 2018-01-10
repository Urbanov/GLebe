#include "primitives.h"
#include <glm/gtc/constants.inl>

std::shared_ptr<Mesh> Primitives::cube(GLfloat width, GLfloat height, GLfloat depth)
{
	std::vector<GLuint> indices {
		0, 1, 2,
		2, 1, 3,
		4, 5, 6,
		6, 5, 7,
		8, 9, 10,
		10, 9, 11,
		12, 13, 14,
		14, 13, 15,
		16, 17, 18,
		18, 17, 19,
		20, 21, 22,
		22, 21, 23
	};

	std::vector<Vertex> vertices;
	vertices.reserve(24);

	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(0, 0, 1), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(0, 0, 1), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(0, 0, 1), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(0, 0, 1), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(0, 0, -1), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(0, 0, -1), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(0, 0, -1), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(0, 0, -1), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(0, 1, 0), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(0, 1, 0), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(0, 1, 0), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(0, 1, 0), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(0, -1, 0), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(0, -1, 0), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(0, -1, 0), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(0, -1, 0), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(1, 0, 0), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(1, 0, 0), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(1, 0, 0), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(1, 0, 0), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, -0.5 * depth), glm::vec3(-1, 0, 0), glm::vec2(0, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, 0.5 * depth), glm::vec3(-1, 0, 0), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, -0.5 * depth), glm::vec3(-1, 0, 0), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, 0.5 * depth), glm::vec3(-1, 0, 0), glm::vec2(1, 1));

	return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}

std::shared_ptr<Mesh> Primitives::plane(GLfloat width, GLfloat height)
{
	std::vector<GLuint> indices{ 0, 1, 2, 1, 3, 2 };
	
	std::vector<Vertex> vertices;
	vertices.reserve(4);

	vertices.emplace_back(glm::vec3(-0.5 * width, -0.5 * height, 0), glm::vec3(0, 0, -1), glm::vec2(1, 1));
	vertices.emplace_back(glm::vec3(0.5 * width, -0.5 * height, 0), glm::vec3(0, 0, -1), glm::vec2(0, 1));
	vertices.emplace_back(glm::vec3(-0.5 * width, 0.5 * height, 0), glm::vec3(0, 0, -1), glm::vec2(1, 0));
	vertices.emplace_back(glm::vec3(0.5 * width, 0.5 * height, 0), glm::vec3(0, 0, -1), glm::vec2(0, 0));

	return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}

std::shared_ptr<Mesh> Primitives::cylinder(GLfloat radius, GLfloat height, GLuint segments)
{
	std::vector<Vertex> vertices;
	std::vector<GLuint> indices;

	GLfloat angle = glm::two_pi<float>() / segments;

	for (GLuint i = 0; i <= segments; ++i) {
		float x = radius * std::cos(angle * i);
		float y = radius * std::sin(angle * i);

		vertices.emplace_back(glm::vec3(x, y, -height / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2(0.5f + static_cast<GLfloat>(i) / segments * 0.5f, 1));
		vertices.emplace_back(glm::vec3(x, y, height / 2), glm::normalize(glm::vec3(x, y, 0)), glm::vec2(0.5f + static_cast<GLfloat>(i) / segments * 0.5f, 0));
	}

	indices.emplace_back(0);
	indices.emplace_back(2);
	indices.emplace_back(1);

	for (GLuint i = 0; i < 2 * segments - 1; ++i) {
		indices.emplace_back(2 * ((i + 2) / 2));
		indices.emplace_back(i + 3);
		indices.emplace_back(2 * ((i + 1) / 2) + 1);
	}

	GLuint center = vertices.size();

	vertices.emplace_back(glm::vec3(0, 0, -height / 2), glm::vec3(0, 0, -1), glm::vec2(0.25, 0.75));
	for (GLuint i = 0; i <= segments; ++i) {
		float x = std::cos(angle * i);
		float y = std::sin(angle * i);

		vertices.emplace_back(glm::vec3(x * radius, y * radius, -height / 2), glm::vec3(0, 0, -1), glm::vec2(0.25 + 0.25 * x, 0.75 - y * 0.25));
	}

	for (GLuint i = 1; i < segments + 1; ++i) {
		indices.emplace_back(center);
		indices.emplace_back(center + i);
		indices.emplace_back(center + i + 1);
	}

	center = vertices.size();
	vertices.emplace_back(glm::vec3(0, 0, height / 2), glm::vec3(0, 0, 1), glm::vec2(0.25, 0.25));
	for (GLuint i = 0; i <= segments; ++i) {
		float x = std::cos(angle * i);
		float y = std::sin(angle * i);

		vertices.emplace_back(glm::vec3(radius * x, radius * y, height / 2), glm::vec3(0, 0, 1), glm::vec2(0.25 + 0.25 * x, 0.25 - y * 0.25));
	}

	for (GLuint i = 1; i < segments + 1; ++i) {
		indices.emplace_back(center);
		indices.emplace_back(center + i);
		indices.emplace_back(center + i + 1);
	}

	return std::make_shared<Mesh>(std::move(vertices), std::move(indices));
}
