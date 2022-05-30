#pragma once
#include"pch.h"
class TextureLoader
{
private:
	Texture *playerTexture, backgroundTexture;
	Sprite bgSprite;
	map<string, Texture*> textures;

public:
	TextureLoader();
	void loadTextures();
	Texture* getTexture(string textureName);
	Sprite getbgSprite();
	~TextureLoader();


};

