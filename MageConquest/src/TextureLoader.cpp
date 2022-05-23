#include "TextureLoader.h"

TextureLoader::TextureLoader(string textureName)
{
	if (!loadTexture(textureName))
	{
		cout << textureName << " not loaded!" << endl;
	}
}

TextureLoader::~TextureLoader()
{
}

bool TextureLoader::loadTexture(string textureName)
{
	if (!texture.loadFromFile(textureName))
	{
		cout << textureName << " not loaded!" << endl;
		return 0;
	}
	sprite.setTexture(texture);
}
