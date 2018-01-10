#pragma once
#include <GL/glew.h>
#include <glm/detail/type_vec2.hpp>

class Texture2D {
private:
	GLuint m_id;
	glm::vec2 m_displacement;

public:
	explicit Texture2D(const char* filename);
	~Texture2D();
	void apply(GLuint shader) const;
	void setDisplacement(const glm::vec2& displacement);
	const glm::vec2& getDisplacement() const;
};
