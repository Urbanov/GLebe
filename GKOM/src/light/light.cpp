#include "light.h"
#include <glm/gtc/type_ptr.hpp>
#include <string>

Light::Light(const glm::vec3& position)
	: m_id([]()->GLuint {
		static GLuint id = 0;
		return id++;
	}())
	, m_position(position)
	, m_intensity(0.0f)
	, m_constant(1.0f)
	, m_linear(0.0f)
	, m_quadratic(0.0f)
{}

Light& Light::setAmbientColor(const glm::vec3& ambient)
{
	m_ambient = ambient;
	return *this;
}

Light& Light::setDiffuseColor(const glm::vec3& diffuse)
{
	m_diffuse = diffuse;
	return *this;
}

Light& Light::setSpecularColor(const glm::vec3& specular)
{
	m_specular = specular;
	return *this;
}

Light& Light::setIntensity(GLfloat intensity)
{
	m_intensity = intensity;
	return *this;
}

Light& Light::setAttenuation(GLfloat constant, GLfloat linear, GLfloat quadratic)
{
	m_constant = constant;
	m_linear = linear;
	m_quadratic = quadratic;
	return *this;
}

void Light::lighten(GLfloat delta)
{
	m_intensity += STEP;
	if (m_intensity > 1.0f) {
		m_intensity = 1.0f;
	}
}

void Light::darken(GLfloat delta)
{
	m_intensity -= STEP;
	if (m_intensity < 0.0f) {
		m_intensity = 0.0f;
	}
}

void Light::render(GLuint shader) const
{
	auto id = std::to_string(m_id);
	glUniform3fv(glGetUniformLocation(shader, ("lights[" + id + "].position").c_str()), 1, glm::value_ptr(m_position));
	glUniform3fv(glGetUniformLocation(shader, ("lights[" + id + "].ambient").c_str()), 1, glm::value_ptr(m_ambient));
	glUniform3fv(glGetUniformLocation(shader, ("lights[" + id + "].diffuse").c_str()), 1, glm::value_ptr(m_diffuse));
	glUniform3fv(glGetUniformLocation(shader, ("lights[" + id + "].specular").c_str()), 1, glm::value_ptr(m_specular));
	glUniform1f(glGetUniformLocation(shader, ("lights[" + id + "].intensity").c_str()), m_intensity);
	glUniform1f(glGetUniformLocation(shader, ("lights[" + id + "].constant").c_str()), m_constant);
	glUniform1f(glGetUniformLocation(shader, ("lights[" + id + "].linear").c_str()), m_linear);
	glUniform1f(glGetUniformLocation(shader, ("lights[" + id + "].quadratic").c_str()), m_quadratic);
}
