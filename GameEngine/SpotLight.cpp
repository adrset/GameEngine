#include "SpotLight.h"
namespace GameEngine {

	void SpotLight::updateCamera(Shader& shader, Camera& camera) {
		shader.setVec3("spotLight.position", camera.Position);
		shader.setVec3("spotLight.direction", camera.Front);
	}
	void SpotLight::update(Shader& shader) {
		
		shader.setVec3("spotLight.ambient",m_ambient);
		shader.setVec3("spotLight.diffuse", m_diffuse);
		shader.setVec3("spotLight.specular", m_specular);
		shader.setFloat("spotLight.constant", m_clq.x);
		shader.setFloat("spotLight.linear", m_clq.y);
		shader.setFloat("spotLight.quadratic", m_clq.z);
		shader.setFloat("spotLight.cutOff", m_cut.x);
		shader.setFloat("spotLight.outerCutOff", m_cut.y);
	}

	SpotLight::SpotLight(glm::vec3& a, glm::vec3& s, glm::vec3& d, glm::vec3& clq, glm::vec2& cut) :Light(a, s, d),  m_cut(cut), m_clq(clq)
	{
	}


	SpotLight::~SpotLight()
	{
	}
}