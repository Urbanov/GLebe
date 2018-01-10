#pragma once
#include "mesh.h"
#include <memory>
#include "../material/material.h"

class Model {
private:
	std::shared_ptr<Mesh> m_mesh;
	std::shared_ptr<Material> m_material;
	glm::vec3 m_position;
	glm::vec3 m_rotation;
	glm::mat4 m_transform;

	void recalculate();

public:
	explicit Model(std::shared_ptr<Mesh> mesh, std::shared_ptr<Material> material);
	Model(const Model& other);
	void render(GLuint shader) const;
	Model& setPosition(const glm::vec3& position);
	Model& setRotation(const glm::vec3& rotation);
	Model& setOpacity(GLfloat opacity);
	Model& setTextureDisplacement(const glm::vec2& displacement);
	const glm::vec3& getPosition() const;
	const glm::vec3& getRotation() const;
	GLfloat getOpacity() const;
	const glm::vec2& getTextureDisplacement() const;
};
