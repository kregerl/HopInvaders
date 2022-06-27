#include <sstream>
#include "countingcomponent.h"

CountingComponent::CountingComponent(const std::string& font, const std::string& text, SDL_Point position,
                                     int font_size, Alignment alignment) : TextComponent(font, text, position,
                                                                                         font_size, alignment),
                                                                           m_count(0) {

}

void CountingComponent::increment(int amount) {
    m_count += amount;
    std::stringstream ss;
    ss << m_text;
    ss << std::to_string(m_count);
    m_texture = Texture(m_fontName, m_fontSize, ss.str(), m_color);
}


