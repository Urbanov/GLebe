#pragma once
#include "texture2d.h"
#include <glm/glm.hpp>
#include <memory>

class Material {
private:
	Texture2D m_diffuse;
	GLfloat m_shininess;
	glm::vec3 m_specular;
	GLfloat m_opacity;

public:
	Material(const char* filename, GLfloat shininess, const glm::vec3& specular);
	void apply(GLuint shader) const;
	static std::shared_ptr<Material> create(const char* filename, GLfloat shininess, const glm::vec3& specular);
	static std::shared_ptr<Material> create(const char* filename);
	void setOpacity(GLfloat opacity);
	void setTextureDisplacement(const glm::vec2& displacement);
	GLfloat getOpacity() const;
	const glm::vec2& getTextureDisplacement() const;
};
