#pragma once
#include <GL/glew.h>
#include <string>
#include "errors.h"
#include "stb_image.h"
namespace GameEngine {
	class Texture
	{
	public:
		Texture(std::string textureName);
		~Texture();

		unsigned int getID() const { return m_texture; }
		unsigned int getWidth() const { return m_width; }
		unsigned int getHeight() const { return m_height; }
	private:
		unsigned int m_texture;
		int m_width, m_height, m_nrChannels;
	};

}

