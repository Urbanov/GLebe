#pragma once
#include "model.h"

class Skybox {
private:
	Model m_top;
	Model m_bottom;
	Model m_front;
	Model m_back;
	Model m_left;
	Model m_right;

public:
	static constexpr GLfloat SIZE = 300;

	Skybox(const char* top, const char* bottom, const char* front, const char* back, const char* left, const char* right);
	void render(GLuint shader) const;
};
