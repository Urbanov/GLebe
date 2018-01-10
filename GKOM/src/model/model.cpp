#include <glm/gtc/type_ptr.hpp>
#include "model.h"
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

void Model::recalculate()
{
	m_transform = glm::translate(glm::mat4(), m_position) * glm::eulerAngleYXZ(glm::radians(m_rotation.y), glm::radians(m_rotation.x), glm::radians(m_rotation.z));
}

Model::Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material)
	: m_mesh(std::move(mesh))
	, m_material(std::move(material))
{}

Model::Model(const Model& other)
	: m_mesh(std::make_shared<Mesh>(*other.m_mesh))
	, m_material(std::make_shared<Material>(*other.m_material))
	, m_position(other.m_position)
	, m_rotation(other.m_rotation)
	, m_transform(other.m_transform)
{}

void Model::render(GLuint shader) const
{
	glUniformMatrix4fv(glGetUniformLocation(shader, "model"), 1, GL_FALSE, glm::value_ptr(m_transform));
	m_material->apply(shader);
	m_mesh->draw();
}

Model& Model::setPosition(const glm::vec3& position)
{
	m_position = position;
	recalculate();
	return *this;
}

Model& Model::setRotation(const glm::vec3& rotation)
{
	m_rotation = rotation;
	recalculate();
	return *this;
}

Model& Model::setOpacity(GLfloat opacity)
{
	m_material->setOpacity(opacity);
	return *this;
}

Model& Model::setTextureDisplacement(const glm::vec2& displacement)
{
	m_material->setTextureDisplacement(displacement);
	return *this;
}

const glm::vec3& Model::getPosition() const
{
	return m_position;
}

const glm::vec3& Model::getRotation() const
{
	return m_rotation;
}

GLfloat Model::getOpacity() const
{
	return m_material->getOpacity();
}

const glm::vec2& Model::getTextureDisplacement() const
{
	return m_material->getTextureDisplacement();
}
