#include "PointLight.h"

namespace GameEngine{
	unsigned int PointLight::m_numLights = 0;

	void PointLight::update(Shader& shader) {
		shader.setVec3("pointLights[" + std::to_string(m_lightID) + "].position", m_position);
		shader.setVec3("pointLights[" + std::to_string(m_lightID) + "].ambient", m_ambient);
		shader.setVec3("pointLights[" + std::to_string(m_lightID) + "].diffuse", m_diffuse);
		shader.setVec3("pointLights[" + std::to_string(m_lightID) + "].specular", m_specular);
		shader.setFloat("pointLights[" + std::to_string(m_lightID) + "].constant", m_clq.x);
		shader.setFloat("pointLights[" + std::to_string(m_lightID) + "].linear", m_clq.y);
		shader.setFloat("pointLights[" + std::to_string(m_lightID) + "].quadratic", m_clq.z);
	}

	void PointLight::draw(Shader& shader) {
	}

	PointLight::PointLight(glm::vec3& p, glm::vec3& a, glm::vec3& s, glm::vec3& d, glm::vec3& clq):Light(a, s, d), m_position(p), m_lightID(m_numLights++), m_clq(clq)
	{
	}


	PointLight::~PointLight()
	{
	}
}