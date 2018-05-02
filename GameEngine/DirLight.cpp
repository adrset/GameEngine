#include "DirLight.h"
namespace GameEngine {

	unsigned int DirLight::m_numLights = 0;
	void DirLight::update(Shader& shader) {
		shader.setVec3("pointLights.direction", m_direction);
		shader.setVec3("pointLights.ambient", m_ambient);
		shader.setVec3("pointLights.diffuse", m_diffuse);
		shader.setVec3("pointLights.specular", m_specular);
	}

	DirLight::DirLight(glm::vec3& a, glm::vec3& s, glm::vec3 d, glm::vec3& dir): Light(a, s, d), m_direction(dir)
	{
		m_numLights++;
		if (m_numLights > 1)
			fatalError("To many directional lights!\nAllowed: " + std::to_string(MAX_DIR_LIGHTS) + "\n");
	}


	DirLight::~DirLight()
	{
	}
}