#include "Game.h"
#include <GameEngine/Texture.h>
#include <GameEngine/stb_image.h>
#include <GameEngine/Camera.h>
#include <GameEngine/PointLight.h>
#include <GameEngine/Model.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


GameEngine::Camera camera(glm::vec3(0.0f, 0.0f, 3.0f));
bool firstMouse = true;

// timing
float deltaTime = 0.0f;	// time between current frame and last frame
float lastFrame = 0.0f;


Game::Game(int width, int height, std::string title): m_width(width), m_height(height), m_title(title)
{
	m_window = new GameEngine::Window(m_width, m_height, m_title);
	lastX = m_width / 2.0f;
	lastY = m_height / 2.0f;
	//loop will be probably public soon
	loop();
}

void Game::loop() {

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);

	// build and compile our shader zprogram
	// ------------------------------------
	GameEngine::Shader lightingShader("6.multiple_lights.vs", "6.multiple_lights.fs");

	GameEngine::Model suit = GameEngine::Model("nanosuit.obj");

	glm::vec3 pointLightPositions[] = {
		glm::vec3(100.0f,  0.2f,  2.0f),
		glm::vec3(2.3f, -3.3f, -4.0f),
		glm::vec3(-4.0f,  2.0f, -12.0f),
		glm::vec3(0.0f,  0.0f, -3.0f)
	};

	m_lights.push_back(GameEngine::PointLight(pointLightPositions[0], glm::vec3(0.05f, 0.03f,0.02f), glm::vec3(1.0f),glm::vec3(0.8f),glm::vec3(1.0f, 0.0f, 0.0f)));
	m_lights.push_back(GameEngine::PointLight(pointLightPositions[1], glm::vec3(0.05f), glm::vec3(1.0f), glm::vec3(0.8f), glm::vec3(1.0f, 0.09f, 0.032f)));
	m_lights.push_back(GameEngine::PointLight(pointLightPositions[2], glm::vec3(0.35f), glm::vec3(1.0f), glm::vec3(0.8f), glm::vec3(1.0f, 0.09f, 0.032f)));
	m_lights.push_back(GameEngine::PointLight(pointLightPositions[3], glm::vec3(0.05f), glm::vec3(1.0f), glm::vec3(0.8f), glm::vec3(1.0f, 0.09f, 0.032f)));
	m_dirLight = new GameEngine::DirLight(glm::vec3(0.5f,0.1f,0.8f), glm::vec3(0.5f), glm::vec3(0.4f), glm::vec3(-0.2f, -1.0f, -0.3f ));
	m_spotLight = new GameEngine::SpotLight(glm::vec3(0.0f), glm::vec3(1.0f), glm::vec3(1.0f), glm::vec3(1.0f, 0.09f, 0.032f), glm::vec2(glm::cos(glm::radians(12.5f)), glm::cos(glm::radians(15.0f))));


	// render loop
	// -----------
	while (!glfwWindowShouldClose(m_window->getWindowID()))
	{
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		// per-frame time logic
		// --------------------
		// -----
		processInput();

		// render
		// ------
		glClearColor(0.1f, 0.1f, 0.1f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// be sure to activate shader when setting uniforms/drawing objects
		lightingShader.use();
		lightingShader.setVec3("viewPos", camera.Position);
		lightingShader.setFloat("material.shininess", 32.0f);

		// directional light
		m_dirLight->update(lightingShader);
		// point light 1
		for (auto& pl : m_lights)
			pl.update(lightingShader);
		// spotLight
		m_spotLight->update(lightingShader);
		m_spotLight->updateCamera(lightingShader,camera);

		// view/projection transformations
		glm::mat4 projection = glm::perspective(glm::radians(camera.Zoom), (float)m_width / (float)m_height, 0.1f, 100.0f);
		glm::mat4 view = camera.GetViewMatrix();

		lightingShader.setMat4("projection", projection);
		lightingShader.setMat4("view", view);

	
		glm::mat4 model;
		model = glm::translate(model, glm::vec3());
		lightingShader.setMat4("model", model);
		suit.draw(lightingShader);

		// glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
		// -------------------------------------------------------------------------------
		glfwSwapBuffers(m_window->getWindowID());
		glfwPollEvents();
	}

	// optional: de-allocate all resources once they've outlived their purpose:
	// ------------------------------------------------------------------------

	cleanUp();

}

void Game::processInput()
{
	if(m_window->m_input.isKeyPressed(GLFW_KEY_ESCAPE))
		glfwSetWindowShouldClose(m_window->getWindowID(), true);

	if (m_window->m_input.isKeyDown(GLFW_KEY_W))
		camera.ProcessKeyboard(GameEngine::FORWARD, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_S))
		camera.ProcessKeyboard(GameEngine::BACKWARD, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_A))
		camera.ProcessKeyboard(GameEngine::LEFT, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_D))
		camera.ProcessKeyboard(GameEngine::RIGHT, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_SPACE))
		camera.ProcessKeyboard(GameEngine::UP, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_C))
		camera.ProcessKeyboard(GameEngine::DOWN, deltaTime);
	if (m_window->m_input.isKeyDown(GLFW_KEY_Q))
		camera.ProcessMouseMovement(-1, 0);
	if (m_window->m_input.isKeyDown(GLFW_KEY_E))
		camera.ProcessMouseMovement(1, 0);
	glm::vec2 temp = m_window->m_input.getDXY();
	camera.ProcessMouseMovement(0, -temp.y);
}



void Game::cleanUp() {
	m_window->closeWindow();
	delete m_window;
	delete m_dirLight;
}


Game::~Game()
{
	std::cout << "Closing game." << std::endl;
}
