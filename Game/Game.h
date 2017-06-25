#pragma once
#include <iostream>
#include <GameEngine\Window.h>
class Game
{
public:
	Game(int width, int height, std::string title);
	~Game();
	void cleanUp();
private:
	int m_width;
	int m_height;
	std::string m_title;
	std::string m_name;
	GameEngine::Window* m_window;

	void loop();
};

