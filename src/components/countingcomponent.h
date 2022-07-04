#ifndef HOPINVADERS_COUNTINGCOMPONENT_H
#define HOPINVADERS_COUNTINGCOMPONENT_H


#include "textcomponent.h"

class CountingComponent : public TextComponent {
public:
    CountingComponent(const std::string& font, const std::string& text, SDL_Point position, int font_size,
                      Alignment alignment, std::string registryName);

    void increment(int amount);

private:
    int m_count;
    std::string m_registryName;
};


#endif //HOPINVADERS_COUNTINGCOMPONENT_H
