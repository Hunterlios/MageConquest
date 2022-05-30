#include "TextureLoader.h"


Texture TextureLoader::getTexture()
{
	return this->texture;
}

Sprite TextureLoader::getSprite()
{
	return this->sprite;
}

TextureLoader::TextureLoader(string textureName)
{
	this->texture.loadFromFile(textureName);
	this->sprite.setTexture(texture);
}

TextureLoader::~TextureLoader()
{
}
