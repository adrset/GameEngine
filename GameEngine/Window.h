#pragma once
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <string>
#include "inputManager.h"
namespace GameEngine {

	class Window {
	private:
		static void mouse_button_callback(GLFWwindow* window, int button, int action, int mods);
		static void cursor_position_callback(GLFWwindow* window, double xpos, double ypos);
		static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void scroll_callback(GLFWwindow* window, double xoffset, double yoffset);
		GLFWwindow* m_window;
		struct info {
			unsigned int width;
			unsigned int height;
			std::string title;
			info(int w, int h, std::string t) : width(w), height(h), title(t) {};
		} infos;


	public:
		
		struct info getInfo() const { return infos; }
		static InputManager m_input;
		GLFWwindow* getWindowID() const { return m_window; }
		void closeWindow();
		Window(int width, int height, std::string title);
		~Window();
	};


}