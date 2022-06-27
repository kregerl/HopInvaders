#ifndef HOPINVADERS_TEXTCOMPONENT_H
#define HOPINVADERS_TEXTCOMPONENT_H

#include <string>
#include <SDL2/SDL_ttf.h>
#include "../core/renderer.h"
#include "../core/texture.h"

enum class Alignment {
    Left,
    Right,
    Center
};

class TextComponent {
public:
    TextComponent(const std::string& font, const std::string& text, SDL_Point position, int fontSize = 10,
                  Alignment alignment = Alignment::Left, SDL_Color color = {.r=255, .g=255, .b=255, .a=255});

    void onUpdate();

    void draw();

    [[nodiscard]] SDL_Color getColor() const;

    [[nodiscard]] std::string getFont() const;

    [[nodiscard]] int getFontSize() const;

private:
    SDL_Point getAdjustedPoint(SDL_Point point, Alignment alignment);

protected:
    Texture m_texture;
    SDL_Point m_pos;
    std::string m_text;
    SDL_Color m_color;
    std::string m_fontName;
    int m_fontSize;
};


#endif //HOPINVADERS_TEXTCOMPONENT_H
