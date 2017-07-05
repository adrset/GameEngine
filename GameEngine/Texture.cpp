#include "Texture.h"


namespace GameEngine {
	Texture::Texture(std::string textureName)
	{

		glGenTextures(1, &m_texture);
		glBindTexture(GL_TEXTURE_2D, m_texture);

		stbi_set_flip_vertically_on_load(true);

		unsigned char *data = stbi_load(textureName.c_str(), &m_width, &m_height, &m_nrChannels, 0);
		// target / mipmap lvl / colours / known/ known /always 0 / rgb as previously / char = usigned byte / data
		if (data) {
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else {
			fatalError("Could not load the texture!");
		}
		//free the memory
		stbi_image_free(data);

	}


	Texture::~Texture()
	{
	}
}
