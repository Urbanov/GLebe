#include "keyframe.h"
#include <glm/common.hpp>

KeyFrame::KeyFrame(GLfloat timestamp, const glm::vec3& position, const glm::vec3& rotation, GLfloat opacity, const glm::vec2& displacement)
	: timestamp(timestamp)
	, position(position)
	, rotation(rotation)
	, opacity(opacity)
	, displacement(displacement)
{}

KeyFrame KeyFrame::interpolate(const KeyFrame& first, const KeyFrame& second, GLfloat timestamp)
{
	GLfloat val = (timestamp - first.timestamp) / (second.timestamp - first.timestamp);
	return {
		timestamp,
		glm::mix(first.position, second.position, val),
		glm::mix(first.rotation, second.rotation, val),
		glm::mix(first.opacity, second.opacity, val),
		glm::mix(first.displacement, second.displacement, val)
	};
}