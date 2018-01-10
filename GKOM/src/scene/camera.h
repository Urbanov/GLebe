#pragma once
#include <GL/glew.h>
#include <glm/glm.hpp>

class Camera
{
private:
	static constexpr GLfloat STEP = 8.0f;
	static constexpr GLfloat FOV = 45.0f;

	glm::vec3 m_position;
	glm::mat4 m_projection;
	glm::mat4 m_view;

	glm::vec3 m_front;
	glm::vec3 m_up;
	glm::vec3 m_right;
	glm::vec3 m_world_up;
	GLfloat m_yaw;
	GLfloat m_pitch;

	void racelculate();

public:
	Camera(const glm::vec3& position, GLfloat yaw, GLfloat pitch);
	void forward(GLfloat delta);
	void backward(GLfloat delta);
	void right(GLfloat delta);
	void left(GLfloat delta);
	void up(GLfloat delta);
	void down(GLfloat delta);
	void rotate(GLfloat x_delta, GLfloat y_delta);
	void applyView(GLuint shader);
};
