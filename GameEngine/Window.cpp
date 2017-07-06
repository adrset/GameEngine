#include <iostream>
#include "Window.h"
#include "errors.h"

namespace GameEngine {

	InputManager Window::m_input;

	void Window::mouse_button_callback(GLFWwindow* window, int button, int action, int mods)
	{
		(action != GLFW_RELEASE) ? m_input.pressMouseKey(button) : m_input.releaseMouseKey(button);
	}

	void Window::scroll_callback(GLFWwindow* window, double xoffset, double yoffset)
	{
		m_input.addScroll(glm::vec2(xoffset, yoffset));
	}

	void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
	{
		(action != GLFW_RELEASE) ? m_input.pressKey(key) : m_input.releaseKey(key);
	}

	void Window::cursor_position_callback(GLFWwindow* window, double xpos, double ypos)
	{
		m_input.setMouseCoords((float)xpos, (float)ypos);
	}

	Window::~Window() {
		std::cout << "Deleting window" << std::endl;
	}

	Window::Window(int width, int height, std::string title):infos(width, height, title){

		

		if (!glfwInit())
		{
			glfwTerminate();
			fatalError("Could not init GLFW");
		}

		glfwSetErrorCallback(glfwError);

		m_window = glfwCreateWindow(width, height, title.c_str(), nullptr, nullptr);

		if (!m_window)
		{
			closeWindow();
			fatalError("Could not create window!");
		}

		glfwMakeContextCurrent(m_window);

		//glfwSwapInterval(0);
		glewExperimental = GL_TRUE;

		if (glewInit() != 0.0) {
			fatalError("Failed to initialize GLEW!");
		}

		glfwSwapInterval(0);

		const GLFWvidmode* vidmode = glfwGetVideoMode(glfwGetPrimaryMonitor());
		glfwSetWindowPos(m_window, (int)(0.5 * (vidmode->width - width)), int((0.5*(vidmode->height - height))));

		glfwSetInputMode(m_window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
		glfwSetKeyCallback(m_window, key_callback);
		glfwSetCursorPosCallback(m_window, cursor_position_callback);
		glfwSetScrollCallback(m_window, scroll_callback);
		glfwSetMouseButtonCallback(m_window, mouse_button_callback);

	}


	void Window::closeWindow() {
		glfwDestroyWindow(m_window);
		glfwTerminate();
	}
}