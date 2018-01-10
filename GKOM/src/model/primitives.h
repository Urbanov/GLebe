#pragma once
#include "mesh.h"
#include <memory>

class Primitives {
public:
	Primitives() = delete;
	static std::shared_ptr<Mesh> cube(GLfloat width, GLfloat height, GLfloat depth);
	static std::shared_ptr<Mesh> plane(GLfloat width, GLfloat height);
	static std::shared_ptr<Mesh> cylinder(GLfloat radius, GLfloat height, GLuint segments);
};
