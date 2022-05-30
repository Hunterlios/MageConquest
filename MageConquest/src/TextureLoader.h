#pragma once
#include"pch.h"
class TextureLoader
{
private:
	Texture texture;
	Sprite sprite;

public:
	Texture getTexture();
	Sprite getSprite();
	TextureLoader(string textureName);
	~TextureLoader();


};

