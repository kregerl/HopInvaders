#ifndef HOPINVADERS_COLLIDER_H
#define HOPINVADERS_COLLIDER_H


#include <SDL2/SDL_rect.h>

class Collider {
public:
    explicit Collider(SDL_Rect size);

    Collider(SDL_Rect size, SDL_Point pos);

    [[nodiscard]] bool isWithin(Collider collider) const;

    [[nodiscard]] int top() const;

    [[nodiscard]] int bottom() const;

    [[nodiscard]] int left() const;

    [[nodiscard]] int right() const;

    SDL_Point getPos();

    void setPos(SDL_Point pos);

    void setPosX(int x);

    void setPosY(int y);

private:
    SDL_Rect m_rect;
};


#endif //HOPINVADERS_COLLIDER_H
