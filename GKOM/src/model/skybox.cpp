#include "skybox.h"
#include "primitives.h"
#include <glm/gtc/constants.inl>

Skybox::Skybox(const char* top, const char* bottom, const char* front, const char* back, const char* left, const char* right)
	: m_top(Primitives::plane(SIZE, SIZE), Material::create(top))
	, m_bottom(Primitives::plane(SIZE, SIZE), Material::create(bottom))
	, m_front(Primitives::plane(SIZE, SIZE), Material::create(front))
	, m_back(Primitives::plane(SIZE, SIZE), Material::create(back))
	, m_left(Primitives::plane(SIZE, SIZE), Material::create(left))
	, m_right(Primitives::plane(SIZE, SIZE), Material::create(right))
{
	m_top.setRotation(glm::vec3(90.0f, -90.0f, 0)).setPosition(glm::vec3(0, SIZE / 2, 0));
	m_bottom.setRotation(glm::vec3(-90.0f, -90.0f, 0)).setPosition(glm::vec3(0, -SIZE / 2, 0));
	m_front.setPosition(glm::vec3(0, 0, -SIZE / 2));
	m_back.setRotation(glm::vec3(0, 180.0f, 0)).setPosition(glm::vec3(0, 0, SIZE / 2));
	m_left.setRotation(glm::vec3(0, 90.0f, 0)).setPosition(glm::vec3(-SIZE / 2, 0, 0));
	m_right.setRotation(glm::vec3(0, -90.0f, 0)).setPosition(glm::vec3(SIZE / 2, 0, 0));
}

void Skybox::render(GLuint shader) const
{
	m_top.render(shader);
	m_bottom.render(shader);
	m_front.render(shader);
	m_back.render(shader);
	m_left.render(shader);
	m_right.render(shader);
}
