#pragma once
#include <GL/glew.h>
#include <string>
#include <assimp/Importer.hpp>
#include "errors.h"
#include "stb_image.h"
namespace GameEngine {

	class Texture
	{
	public:
		Texture(std::string textureName);
		Texture(std::string path, std::string typeName);
		~Texture();

		unsigned int getID() const { return m_texture; }
		unsigned int getWidth() const { return m_width; }
		unsigned int getHeight() const { return m_height; }
		std::string getType() const { return m_type; }
		aiString getPath() const { return m_path; }
	private:
		std::string m_type;
		aiString m_path;
		unsigned int m_texture;
		int m_width, m_height, m_nrChannels;
	};

}

