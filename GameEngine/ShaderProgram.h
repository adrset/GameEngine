#pragma once
#include <string>
#include <iostream>
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec2.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "errors.h"
namespace GameEngine {
	class ShaderProgram
	{
	private:
		int m_programID;
		int m_vertexShaderID;
		int m_fragmentShaderID;
		int loadShader(std::string file, int type);
	public:
		void start();
		void stop();
		void cleanUp();
		ShaderProgram(std::string vertexFile, std::string fragmentFile);
		~ShaderProgram();
	protected:
		void init();
		void loadFloat(int location, float value);
		void loadVector(int location, glm::vec3 vector);
		void loadBoolean(int location, bool value);
		void loadVector2D(int location, glm::vec2 vector);
		void loadMatrix(int location, glm::mat4 matrix);
		void bindAttribute(int attribute, std::string variableName);
		/*virtual void bindAttributes() = 0;
		virtual void getAllUniformLocations() = 0;*/
		int getUniformLocation(std::string uniformName);
	};
}
