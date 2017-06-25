#pragma once
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <GLM/vec2.hpp>
namespace GameEngine {
	class InputManager
	{
	public:
		InputManager();
		~InputManager();

		void update();
		bool wasMouseKeyDown(unsigned int keyID);
		bool isMouseKeyPressed(unsigned int keyID);
		void pressMouseKey(unsigned int keyID);
		void releaseMouseKey(unsigned int keyID);

		bool isMouseKeyDown(unsigned int keyID);
		void pressKey(unsigned int keyID);
		void releaseKey(unsigned int keyID);
		void setMouseCoords(float x, float y);

		bool isKeyDown(unsigned int keyID);
		bool isKeyPressed(unsigned int keyID);

		void addScroll(glm::vec2 scroll);
		glm::vec2 getMouseCoords() const { return m_mouseCoords; }
	private:
		bool wasKeyDown(unsigned int keyID);
		std::unordered_map<unsigned int, bool> m_mouseKeyMap;
		std::unordered_map<unsigned int, bool> m_previousMouseKeyMap;
		std::unordered_map<unsigned int, bool> m_keyMap;
		std::unordered_map<unsigned int, bool> m_previousKeyMap;
		
		glm::vec2 m_scroll;

		glm::vec2 m_mouseCoords;
	};

}