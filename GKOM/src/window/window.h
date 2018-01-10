#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <utility>

class Window {
private:
	GLFWwindow* m_window;
	bool m_mouse_begin;
	double m_mouse_last_x;
	double m_mouse_last_y;
	double m_mouse_current_x;
	double m_mouse_current_y;
	GLfloat m_frame_current;
	GLfloat m_frame_last;

public:
	Window(GLuint width, GLuint height, const char* title);
	bool shouldClose() const;
	bool isKeyPressed(int key) const;
	bool isButtonPressed(int button) const;
	GLfloat getCursorOffsetX() const;
	GLfloat getCursorOffsetY() const;
	static std::pair<int, int> viewPort();
	GLfloat frameTime() const;
	void nextFrame();
};
