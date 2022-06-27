#ifndef HOPINVADERS_PLAYER_H
#define HOPINVADERS_PLAYER_H

#include <optional>
#include "sprite.h"
#include "renderer.h"
#include "events.h"
#include "../entity/bullet.h"

class Player {
public:
    explicit Player();

    void onUpdate();

private:
    void shoot();

private:
    Sprite m_sprite;
    std::optional<Bullet> m_bullet;
    SDL_Point m_position;

};


#endif //HOPINVADERS_PLAYER_H
