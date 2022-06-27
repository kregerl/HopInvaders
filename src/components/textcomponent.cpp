#include "textcomponent.h"
#include "../core/assetmanager.h"

TextComponent::TextComponent(const std::string& font, const std::string& text, SDL_Point position, int fontSize,
                             Alignment alignment, SDL_Color color)
        : m_texture(font, fontSize, text, color),
          m_pos(getAdjustedPoint(position, alignment)),
          m_fontSize(fontSize),
          m_fontName(font),
          m_color(color),
          m_text(text) {

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

SDL_Color TextComponent::getColor() const {
    return m_color;
}

std::string TextComponent::getFont() const {
    return m_fontName;
}

int TextComponent::getFontSize() const {
    return m_fontSize;
}


