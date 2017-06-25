#include "Game.h"



Game::Game(int width, int height, std::string title): m_width(width), m_height(height), m_title(title)
{
	m_window = new GameEngine::Window(m_width, m_height, m_title);

	//loop will be probably public soon
	loop();
}

void Game::loop() {
	while (!glfwWindowShouldClose(m_window->getWindowID()))
	{
		glfwPollEvents();

		m_window->m_input.update();
	
		glClearColor(0.5f, 0.5f, 0.5f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(m_window->getWindowID());
	}
	cleanUp();

}

void Game::cleanUp() {
	m_window->closeWindow();
}


Game::~Game()
{
	std::cout << "Closing game." << std::endl;
}
