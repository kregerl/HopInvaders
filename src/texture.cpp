#include "texture.h"
#include "assetmanager.h"

Texture::Texture(const std::string& fontName, int fontSize, const std::string& text, SDL_Color color) {
    m_texture = AssetManager::instance()->getTextTexture(fontName, fontSize, text, color);

    SDL_Rect r = {
            .x = 0,
            .y = 0
    };

    SDL_QueryTexture(m_texture, nullptr, nullptr, &r.w, &r.h);
    m_size = r;
}


Texture::Texture(const std::string& textureName) {
    m_texture = AssetManager::instance()->getTexture(textureName);

    SDL_Rect r = {
            .x = 0,
            .y = 0
    };

    SDL_QueryTexture(m_texture, nullptr, nullptr, &r.w, &r.h);
    m_size = r;
}

int Texture::getWidth() const {
    return m_size.w;
}

int Texture::getHeight() const {
    return m_size.h;
}

SDL_Texture* Texture::get() const {
    return m_texture;
}

SDL_Rect Texture::getSize() {
    return m_size;
}



