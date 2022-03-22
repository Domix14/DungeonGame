#pragma once

#include <raylib.h>
#include <unordered_map>

class ResourceManager
{
public:
	bool GetTexture(Texture* &texture, const std::string& textureName);
	bool LoadTextureFromName(const std::string& textureName);


private:
	std::unordered_map<std::string, Texture2D> textures;
};

