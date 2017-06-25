#include "inputManager.h"

namespace GameEngine {

	InputManager::InputManager() :m_mouseCoords(0) {

	}

	InputManager::~InputManager() {

	}
	void InputManager::update() {

		for (auto& it : m_keyMap) {
			m_previousKeyMap[it.first] = it.second;
		}
		for (auto& it : m_mouseKeyMap) {
			m_previousMouseKeyMap[it.first] = it.second;
		}
	}

	void InputManager::pressKey(unsigned int keyID) {
		m_keyMap[keyID] = true; // same as _keyMap.insert();
	}
	void InputManager::releaseKey(unsigned int keyID) {
		m_keyMap[keyID] = false;
	}

	void InputManager::setMouseCoords(float x, float y) {
		m_mouseCoords.x = x;
		m_mouseCoords.y = y;
	}
	bool InputManager::isKeyDown(unsigned int keyID) {
		auto it = m_keyMap.find(keyID);
		if (it != m_keyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	bool InputManager::isKeyPressed(unsigned int keyID)
	{
		bool isPressed = false;
		if (isKeyDown(keyID) == true && wasKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}


	bool InputManager::wasKeyDown(unsigned int keyID)
	{
		auto it = m_previousKeyMap.find(keyID);
		if (it != m_previousKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}
	

	void InputManager::pressMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = true;
	}

	void InputManager::releaseMouseKey(unsigned int keyID) {
		m_mouseKeyMap[keyID] = false;
	}

	bool InputManager::isMouseKeyDown(unsigned int keyID) {
		auto it = m_mouseKeyMap.find(keyID);
		if (it != m_mouseKeyMap.end()) {
			return it->second;//ret val (it's bool)
		}
		else {
			return false;
		}
	}

	void InputManager::addScroll(glm::vec2 scroll) {
		this->m_scroll += scroll;
	}

	bool InputManager::isMouseKeyPressed(unsigned int keyID)
	{
		bool isPressed = false;
		if (isMouseKeyDown(keyID) == true && wasMouseKeyDown(keyID) == false) {
			return true;
		}
		return false;
	}

	bool InputManager::wasMouseKeyDown(unsigned int keyID)
	{
		auto it = m_previousMouseKeyMap.find(keyID);
		if (it != m_previousMouseKeyMap.end()) {
			return it->second; //ret val (it's bool)
		}
		else {
			return false;
		}
	}

}