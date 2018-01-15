#pragma once
#include <glm/vec3.hpp>
#include <GL/glew.h>

class Light {
private:
	static constexpr GLfloat STEP = 0.8f;

	GLuint m_id;
	glm::vec3 m_position;
	glm::vec3 m_ambient;
	glm::vec3 m_diffuse;
	glm::vec3 m_specular;
	GLfloat m_intensity;
	GLfloat m_constant;
	GLfloat m_linear;
	GLfloat m_quadratic;

public:
	explicit Light(const glm::vec3& position);
	Light& setAmbientColor(const glm::vec3& ambient);
	Light& setDiffuseColor(const glm::vec3& diffuse);
	Light& setSpecularColor(const glm::vec3& specular);
	Light& setIntensity(GLfloat intensity);
	Light& setAttenuation(GLfloat constant, GLfloat linear, GLfloat quadratic);
	void lighten(GLfloat delta);
	void darken(GLfloat delta);
	void render(GLuint shader) const;
};
