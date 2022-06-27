#ifndef HOPINVADERS_ASSETMANAGER_H
#define HOPINVADERS_ASSETMANAGER_H

#include <string>
#include <map>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

class AssetManager {
public:
    static AssetManager* instance();

    static void release();

    SDL_Texture* getTexture(const std::string& filename);

    SDL_Texture* getTextTexture(const std::string& filename, int size, const std::string& text, SDL_Color color);

    TTF_Font* getFont(const std::string& filename, int size);

private:
    AssetManager();

    ~AssetManager();

private:
    static AssetManager* s_instance;

    std::map<std::string, SDL_Texture*> m_textTextures;
    std::map<std::string, SDL_Texture*> m_textures;
    std::map<std::string, TTF_Font*> m_fonts;
};


#endif //HOPINVADERS_ASSETMANAGER_H
