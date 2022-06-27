#ifndef HOPINVADERS_SPRITE_H
#define HOPINVADERS_SPRITE_H

#include "renderer.h"
#include "texture.h"

#include <string>
#include <memory>
#include <SDL2/SDL.h>

class Sprite {
public:
    Sprite(const std::string& textureName, int width, int height, int numFrames = 1);

    void draw(SDL_Point pos);

    [[nodiscard]] SDL_Rect getSize() const;

public:
    Texture m_texture;
    SDL_Rect m_spriteSize;
    int m_numFrames;
};


#endif //HOPINVADERS_SPRITE_H
