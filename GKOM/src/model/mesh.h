#pragma once
#include <vector>
#include "vertex.h"
#include <GL/glew.h>

class Mesh {
private:
	std::vector<Vertex> m_vertices;
	std::vector<GLuint> m_indices;
	GLuint m_VAO;
	GLuint m_VBO;
	GLuint m_EBO;

public:
	Mesh(std::vector<Vertex>&& vertices, std::vector<GLuint>&& indices);
	~Mesh();
	void draw() const;
};
