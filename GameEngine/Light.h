#pragma once
#include <glm/vec3.hpp>
#include "Shader.h"
namespace GameEngine {
	class Light
	{
	public:
		Light(glm::vec3& a, glm::vec3& s, glm::vec3 d);
		virtual ~Light() {};
		virtual void update(Shader& shader) = 0;
	protected:
		glm::vec3 m_ambient;
		glm::vec3 m_specular;
		glm::vec3 m_diffuse;

	};

}