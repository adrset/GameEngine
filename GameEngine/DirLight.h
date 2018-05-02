#pragma once
#include "Light.h"
namespace GameEngine {
	class DirLight : public Light
	{
	public:
		void update(Shader& shader);
		DirLight(glm::vec3& a, glm::vec3& s, glm::vec3 d, glm::vec3& dir);
		~DirLight();
	private:
		glm::vec3 m_direction;
		static unsigned int m_numLights;
		static const unsigned int MAX_DIR_LIGHTS = 1;
	};

}