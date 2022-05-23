#include "pch.h"

class TextureLoader
{

public:
	Texture texture;
	Sprite sprite;
	string textureName;
	TextureLoader(string textureName);
	~TextureLoader();
	bool loadTexture(string textureName);
	


};

