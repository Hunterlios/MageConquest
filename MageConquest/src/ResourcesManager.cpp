#include "ResourcesManager.h"

ResourcesManager::ResourcesManager()
{
}

ResourcesManager::~ResourcesManager()
{
}

void ResourcesManager::LoadTexture(string name, string file)
{
	Texture texture;
	if (texture.loadFromFile(file))
	{
		this->textures[name] = texture;
	}
}

Texture& ResourcesManager::GetTexture(string name)
{
	return this->textures.at(name);
}
