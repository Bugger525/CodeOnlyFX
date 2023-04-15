#include "Graphics/Texture.h"
#include <GL/glew.h>

namespace co
{
	Texture::Texture() : m_Texture(NULL), m_Size(0, 0)
	{
	}
	Texture::Texture(unsigned int width, unsigned int height, std::span<unsigned int> rawImage) : m_Texture(NULL), m_Size(width, height)
	{
		m_Image.assign(rawImage.begin(), rawImage.end());

		glGenTextures(1, &m_Texture);
		glBindTexture(GL_TEXTURE_2D, m_Texture);
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, rawImage.data());

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	Texture::Texture(Texture* spriteSheet, unsigned int spriteSize, unsigned int x, unsigned int y)
	{
		m_Size = { spriteSize, spriteSize };

		const int xp = x * spriteSize, yp = y * spriteSize;

		for (auto ty = 0; ty < spriteSize; ty++)
		{
			for (auto tx = 0; tx < spriteSize; tx++)
			{
				auto i = (xp + tx) + (yp + ty) * spriteSheet->GetSize().x;
				unsigned int pixel = spriteSheet->GetImage()[i];
				m_Image.push_back(pixel);
			}
		}
	}
	Texture::~Texture()
	{
		Cleanup();
	}
	void Texture::Bind() const
	{
		glBindTexture(GL_TEXTURE_2D, m_Texture);
	}
	void Texture::GenerateMipmap() const
	{
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	const std::vector<unsigned int>& Texture::GetImage() const
	{
		return m_Image;
	}
	const glm::uvec2& Texture::GetSize() const
	{
		return m_Size;
	}
	void Texture::Cleanup()
	{
		if (m_Texture)
			glDeleteTextures(1, &m_Texture);
	}
}