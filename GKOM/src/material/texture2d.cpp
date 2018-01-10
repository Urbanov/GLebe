#include <SOIL.h>
#include "texture2d.h"
#include <glm/gtc/type_ptr.hpp>
#include <stdexcept>

Texture2D::Texture2D(const char* filename)
	: m_displacement(0, 0)
{
	int width, height;
	unsigned char* image = SOIL_load_image(filename, &width, &height, 0, SOIL_LOAD_RGB);
	if (image == nullptr) {
		throw std::runtime_error("Failed to load texture " + std::string(filename));
	}

	glGenTextures(1, &m_id);
	glBindTexture(GL_TEXTURE_2D, m_id);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	SOIL_free_image_data(image);
}

Texture2D::~Texture2D()
{
	if (m_id) {
		glDeleteTextures(1, &m_id);
	}
	m_id = 0;
}

void Texture2D::apply(GLuint shader) const
{
	glUniform2fv(glGetUniformLocation(shader, "material.displacement"), 1, glm::value_ptr(m_displacement));
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, m_id);
}

void Texture2D::setDisplacement(const glm::vec2& displacement)
{
	if (m_displacement == glm::vec2(0.0f, 0.0f)) {
		glBindTexture(GL_TEXTURE_2D, m_id);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	m_displacement = displacement;
}

const glm::vec2& Texture2D::getDisplacement() const
{
	return m_displacement;
}
