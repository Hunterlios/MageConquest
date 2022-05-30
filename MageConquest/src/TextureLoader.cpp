#include "TextureLoader.h"



TextureLoader::TextureLoader()
{
	this->playerTexture = new Texture;
	this->loadTextures();
	this->textures.insert({ "pTexture", playerTexture });
}

void TextureLoader::loadTextures()
{
	this->playerTexture->loadFromFile("Mage.png");
	this->backgroundTexture.loadFromFile("Mapa_MageConquest.png");
}

Texture* TextureLoader::getTexture(string textureName)
{
	return this->textures.at(textureName);
}

Sprite TextureLoader::getbgSprite()
{
	this->bgSprite.setTexture(this->backgroundTexture);
	return this->bgSprite;
}



TextureLoader::~TextureLoader()
{
	delete this->playerTexture;
}
