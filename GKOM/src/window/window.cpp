#include "window.h"
#include <stdexcept>
#include <GL/glew.h>

Window::Window(GLuint width, GLuint height, const char* title)
	: m_mouse_begin(true)
	, m_mouse_last_x(0.0f)
	, m_mouse_last_y(0.0f)
	, m_mouse_current_x(0.0f)
	, m_mouse_current_y(0.0f)
	, m_frame_current(-1.0f)
	, m_frame_last(-1.0f)
{
	if (glfwInit() != GL_TRUE) {
		throw std::runtime_error("GLFW initialization failed");
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

	m_window = glfwCreateWindow(width, height, title, nullptr, nullptr);
	if (m_window == nullptr) {
		throw std::runtime_error("GLFW window not created");
	}
	glfwMakeContextCurrent(m_window);
	glfwSetWindowUserPointer(m_window, this);

	glewExperimental = GL_TRUE;
	if (glewInit() != GLEW_OK)
		throw std::runtime_error("GLEW initialization failed");

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glDisable(GL_CULL_FACE);

	glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods) { 
		if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
			static_cast<Window*>(glfwGetWindowUserPointer(window))->m_mouse_begin = true;
		}
	});
}

bool Window::shouldClose() const
{
	return glfwWindowShouldClose(m_window) == GL_TRUE;
}

bool Window::isKeyPressed(int key) const
{
	return glfwGetKey(m_window, key) == GLFW_PRESS;
}

bool Window::isButtonPressed(int button) const
{
	return glfwGetMouseButton(m_window, button) == GLFW_PRESS;
}

GLfloat Window::getCursorOffsetX() const
{
	return static_cast<GLfloat>(m_mouse_current_x - m_mouse_last_x);
}

GLfloat Window::getCursorOffsetY() const
{
	return static_cast<GLfloat>(m_mouse_current_y - m_mouse_last_y);
}

std::pair<int, int> Window::viewPort()
{
	GLint viewport[4];
	glGetIntegerv(GL_VIEWPORT, viewport);
	return std::make_pair(viewport[2], viewport[3]);
}

GLfloat Window::frameTime() const
{
	if (m_frame_last < 0) {
		return 0;
	}
	return m_frame_current - m_frame_last;
}

void Window::nextFrame()
{
	glfwSwapBuffers(m_window);
	m_frame_last = m_frame_current;
	m_frame_current = static_cast<GLfloat>(glfwGetTime());

	glfwPollEvents();

	m_mouse_last_x = m_mouse_current_x;
	m_mouse_last_y = m_mouse_current_y;
	glfwGetCursorPos(m_window, &m_mouse_current_x, &m_mouse_current_y);

	if (m_mouse_begin) {
		m_mouse_begin = false;
		m_mouse_last_x = m_mouse_current_x;
		m_mouse_last_y = m_mouse_current_y;
	}
}