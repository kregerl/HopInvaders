#ifndef HOPINVADERS_BULLET_H
#define HOPINVADERS_BULLET_H


#include <SDL2/SDL_rect.h>
#include "sprite.h"

class Bullet {
public:
    enum class Direction {
        Up = -1,
        Down = 1
    };

    Bullet(Sprite sprite, SDL_Point position, Direction dir);

    void onUpdate();

    void setMoving(bool moving);

    bool isMoving();

    void setPosition(SDL_Point pos);

private:
    Direction m_direction;
    Sprite m_sprite;
    SDL_Point m_position;
    bool m_moving;
};


#endif //HOPINVADERS_BULLET_H
