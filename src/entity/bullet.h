#ifndef HOPINVADERS_BULLET_H
#define HOPINVADERS_BULLET_H


#include <SDL2/SDL_rect.h>
#include "../core/sprite.h"
#include "../core/collider.h"

class Bullet {
public:
    enum class Direction {
        Up = -1,
        Down = 1
    };

    Bullet(Sprite sprite, SDL_Point position, Direction dir);

    void onUpdate();

    Collider getCollider() const;

    void setMoving(bool moving);

    bool isMoving();

    void setPosition(SDL_Point pos);

private:
    Direction m_direction;
    Sprite m_sprite;
    Collider m_collider;
    bool m_moving;
};


#endif //HOPINVADERS_BULLET_H
