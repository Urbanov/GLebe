#include "material.h"
#include <glm/gtc/type_ptr.inl>

Material::Material(const char* filename, GLfloat shininess, const glm::vec3& specular)
	: m_diffuse(filename)
	, m_shininess(shininess)
	, m_specular(specular)
	, m_opacity(1.0f)
{}

void Material::apply(GLuint shader) const
{
	m_diffuse.apply(shader);
	glUniform3fv(glGetUniformLocation(shader, "material.specular"), 1, glm::value_ptr(m_specular));
	glUniform1f(glGetUniformLocation(shader, "material.shininess"), m_shininess);
	glUniform1f(glGetUniformLocation(shader, "material.opacity"), m_opacity);
}

std::shared_ptr<Material> Material::create(const char* filename, GLfloat shininess, const glm::vec3& specular)
{
	return std::make_shared<Material>(filename, shininess, specular);
}

std::shared_ptr<Material> Material::create(const char* filename)
{
	return std::make_shared<Material>(filename, 32.0f, glm::vec3(0.5f, 0.5f, 0.5f));
}

void Material::setOpacity(GLfloat opacity)
{
	m_opacity = opacity;
}

void Material::setTextureDisplacement(const glm::vec2& displacement)
{
	m_diffuse.setDisplacement(displacement);
}

GLfloat Material::getOpacity() const
{
	return m_opacity;
}
const glm::vec2& Material::getTextureDisplacement() const
{
	return m_diffuse.getDisplacement();
}
