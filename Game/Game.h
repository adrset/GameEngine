#pragma once
#include <iostream>
#include <GameEngine/Window.h>
#include <GameEngine/Shader.h>

class Game
{
public:
	Game(int width, int height, std::string title);
	~Game();
	void cleanUp();
private:
	void Game::processInput();
	int m_width;
	int m_height;
	std::string m_title;
	std::string m_name;
	GameEngine::Window* m_window;
	float lastX;
	float lastY;
	void loop();
};

