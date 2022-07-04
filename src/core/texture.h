#ifndef HOPINVADERS_TEXTURE_H
#define HOPINVADERS_TEXTURE_H

#include <string>
#include <SDL2/SDL.h>

class Texture {
public:
    explicit Texture(const std::string& textureName);

    Texture(const std::string& fontName, int fontSize, const std::string& text, SDL_Color color, std::string registryName = "");

    [[nodiscard]] SDL_Texture* get() const;

    [[nodiscard]] int getWidth() const;

    [[nodiscard]] int getHeight() const;

    [[nodiscard]] SDL_Rect getSize();

    [[nodiscard]] std::string getRegistryName();

private:
    SDL_Texture* m_texture;
    SDL_Rect m_size{};
    std::string m_registryName;
};


#endif //HOPINVADERS_TEXTURE_H
