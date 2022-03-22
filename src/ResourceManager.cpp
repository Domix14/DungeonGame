#include "ResourceManager.h"

bool ResourceManager::GetTexture(Texture* &texture, const std::string& textureName)
{
    // Load texture if not loaded
    if (textures.size() == 0 || textures.find(textureName) == textures.end())
    {
        if (!LoadTextureFromName(textureName)) return false;
    }
    texture = &textures[textureName];
    
    return true;
}

bool ResourceManager::LoadTextureFromName(const std::string& textureName)
{
    Texture2D texture = LoadTexture(std::string("textures/" + textureName + ".png").c_str());
    if (texture.width > 0 && texture.height > 0)
    {
        textures[textureName] = texture;
        return true;
    }
    return false;
}
