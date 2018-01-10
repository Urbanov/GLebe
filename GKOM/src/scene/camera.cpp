#include <glm/gtc/matrix_transform.hpp>
#include "camera.h"
#include <algorithm>
#include <glm/gtc/type_ptr.inl>
#include "../window/window.h"
#include "../model/skybox.h"

void Camera::racelculate()
{
	glm::vec3 front;
	front.x = cos(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	front.y = sin(glm::radians(m_pitch));
	front.z = sin(glm::radians(m_yaw)) * cos(glm::radians(m_pitch));
	m_front = glm::normalize(front);
	m_right = glm::normalize(glm::cross(m_front, m_world_up));
	m_up = glm::normalize(glm::cross(m_right, m_front));
	m_view = glm::lookAt(m_position, m_position + m_front, m_up);
}

Camera::Camera(const glm::vec3& position, GLfloat yaw, GLfloat pitch)
	: m_position(position)
	, m_front(glm::vec3(0.0f, 0.0f, -1.0f))
	, m_world_up(glm::vec3(0.0f, 1.0f, 0.0f))
	, m_yaw(yaw)
	, m_pitch(pitch)
{
	auto viewport = Window::viewPort();
	GLfloat width = static_cast<float>(viewport.first);
	GLfloat height = static_cast<float>(viewport.second);
	m_projection = glm::perspective(glm::radians(FOV), width / height, 0.1f, Skybox::SIZE);
	racelculate();
}

void Camera::forward(GLfloat delta)
{
	m_position += m_front * STEP * delta;
	racelculate();
}

void Camera::backward(GLfloat delta)
{
	m_position -= m_front * STEP * delta;
	racelculate();
}

void Camera::right(GLfloat delta)
{
	m_position += m_right * STEP * delta;
	racelculate();
}

void Camera::left(GLfloat delta)
{
	m_position -= m_right * STEP * delta;
	racelculate();
}

void Camera::up(GLfloat delta)
{
	m_position += m_up * STEP * delta;
	racelculate();
}

void Camera::down(GLfloat delta)
{
	m_position -= m_up * STEP * delta;
	racelculate();
}

void Camera::rotate(GLfloat x_delta, GLfloat y_delta)
{
	auto sensitivity = FOV / Window::viewPort().second;
	m_yaw -= x_delta * sensitivity;
	m_pitch += y_delta * sensitivity;
	m_pitch = std::min(m_pitch, 89.0f);
	m_pitch = std::max(m_pitch, -89.0f);
	racelculate();
}

void Camera::applyView(GLuint shader)
{
	glUniformMatrix4fv(glGetUniformLocation(shader, "projection"), 1, GL_FALSE, glm::value_ptr(m_projection));
	glUniformMatrix4fv(glGetUniformLocation(shader, "view"), 1, GL_FALSE, glm::value_ptr(m_view));
	glUniform3fv(glGetUniformLocation(shader, "viewPosition"), 1, glm::value_ptr(m_position));
}
