#pragma once
#include "Camera.h"
#include "PointLight.h"
namespace GameEngine {
	class SpotLight : public Light
	{
	public:
		void update(Shader& shader);
		void updateCamera(Shader& shader, Camera& camera);
		SpotLight(glm::vec3& a, glm::vec3& s, glm::vec3& d, glm::vec3& clq, glm::vec2& cut);
		~SpotLight();
	private:
		glm::vec2 m_cut;
		glm::vec3 m_clq;
	};

}