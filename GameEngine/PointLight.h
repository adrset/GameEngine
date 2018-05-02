#pragma once
#include "Light.h"
namespace GameEngine {
	class PointLight: public Light
	{
	public:
		PointLight(glm::vec3& p,glm::vec3& a, glm::vec3& s, glm::vec3& d, glm::vec3& clq);
		~PointLight();
		void update(Shader& shader);
		void draw(Shader& shader);
	private:
		glm::vec3 m_position;
		unsigned int m_lightID;
		glm::vec3 m_clq;
		static unsigned int m_numLights;
		static const unsigned int MAX_LIGHTS = 3;
	};

}