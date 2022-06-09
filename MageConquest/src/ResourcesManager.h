#pragma once
#include"pch.h"
class ResourcesManager
{
private:
	map<string, Texture> textures;

public:
	ResourcesManager();
	~ResourcesManager();
	void LoadTexture(string name, string file);
	Texture& GetTexture(string name);
};


