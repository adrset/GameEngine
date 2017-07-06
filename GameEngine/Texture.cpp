#include "Texture.h"

namespace GameEngine {
	Texture::Texture(std::string textureName) : m_path(textureName)
	{

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(textureName.c_str(), &m_width, &m_height, &m_nrChannels, 0);
		// target / mipmap lvl / colours / known/ known /always 0 / rgb as previously / char = usigned byte / data
		if (data) {
			GLenum format;
			if (m_nrChannels == 1)
				format = GL_RED;
			else if (m_nrChannels == 3)
				format = GL_RGB;
			else if (m_nrChannels == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, m_texture);
			glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else {
			fatalError("Could not load the texture!");
		}

	}

	Texture::Texture(std::string path,std::string typeName) :m_type (typeName), m_path(path)
	{

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(path.c_str(), &m_width, &m_height, &m_nrChannels, 0);
		// target / mipmap lvl / colours / known/ known /always 0 / rgb as previously / char = usigned byte / data
		if (data) {
			GLenum format;
			if (m_nrChannels == 1)
				format = GL_RED;
			else if (m_nrChannels == 3)
				format = GL_RGB;
			else if (m_nrChannels == 4)
				format = GL_RGBA;

			glBindTexture(GL_TEXTURE_2D, m_texture);
			glTexImage2D(GL_TEXTURE_2D, 0, format, m_width, m_height, 0, format, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);

			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			stbi_image_free(data);
		}
		else {
			fatalError("Could not load the texture!");
		}

	}


	Texture::~Texture()
	{
	}
}
