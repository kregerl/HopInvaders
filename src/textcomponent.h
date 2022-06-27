#ifndef HOPINVADERS_TEXTCOMPONENT_H
#define HOPINVADERS_TEXTCOMPONENT_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include "renderer.h"
#include "texture.h"

enum class Alignment {
    Left,
    Right,
    Center
};

class TextComponent {
public:
    TextComponent(const std::string& font, const std::string& text, SDL_Point position, int font_size = 10,
                  Alignment alignment = Alignment::Left);

    void onUpdate();

    void draw();

private:
    SDL_Point getAdjustedPoint(SDL_Point point, Alignment alignment);

private:
    Texture m_texture;
    SDL_Point m_pos;
};


#endif //HOPINVADERS_TEXTCOMPONENT_H
