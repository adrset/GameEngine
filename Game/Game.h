#pragma once
#include <iostream>
#include <GameEngine/Window.h>
#include <GameEngine/PointLight.h>
#include <GameEngine/SpotLight.h>
#include <GameEngine/DirLight.h>
#include <GameEngine/Shader.h>
#include <vector>

class Game
{
public:
	Game(int width, int height, std::string title);
	~Game();
	void cleanUp();
private:
	std::vector<GameEngine::PointLight> m_lights;
	GameEngine::SpotLight* m_spotLight;
	GameEngine::DirLight* m_dirLight;
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

