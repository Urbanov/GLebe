#pragma once
#include <GL/glew.h>
#include <glm/detail/type_vec2.hpp>
#include <glm/detail/type_vec3.hpp>

struct KeyFrame {
	GLfloat timestamp;
	glm::vec3 position;
	glm::vec3 rotation;
	GLfloat opacity;
	glm::vec2 displacement;

	KeyFrame(GLfloat timestamp, const glm::vec3& position, const glm::vec3& rotation, GLfloat opacity, const glm::vec2& displacement);
	static KeyFrame interpolate(const KeyFrame& first, const KeyFrame& second, GLfloat timestamp);
};
