#include "textcomponent.h"
#include "assetmanager.h"

TextComponent::TextComponent(const std::string& font, const std::string& text, SDL_Point position, int font_size,
                             Alignment alignment)
        : m_texture(font, font_size, text, {.r=255, .g=255, .b=255, .a=255}),
          m_pos(getAdjustedPoint(position, alignment)) {

}

void TextComponent::onUpdate() {
    draw();
}

void TextComponent::draw() {
    SDL_Rect r = m_texture.getSize();
    r.x = m_pos.x;
    r.y = m_pos.y;

    SDL_RenderCopy(Renderer::instance()->getRenderer(), m_texture.get(), nullptr, &r);
}

SDL_Point TextComponent::getAdjustedPoint(SDL_Point point, Alignment alignment) {
    SDL_Point pos = point;
    switch (alignment) {
        case Alignment::Left:break;
        case Alignment::Right: {
            pos.x -= m_texture.getWidth();
            break;
        }
        case Alignment::Center: {
            pos.x -= m_texture.getWidth() / 2;
            break;
        }
    }
    return pos;
}


