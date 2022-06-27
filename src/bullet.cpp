#include "bullet.h"

#define VELOCITY 2

Bullet::Bullet(Sprite sprite, SDL_Point position, Bullet::Direction dir) : m_sprite(sprite), m_position(position),
                                                                           m_moving(false), m_direction(dir) {

}

void Bullet::onUpdate() {
    if (m_moving) {
        m_position.y += static_cast<int>(m_direction) * VELOCITY;
    }

    m_sprite.draw(m_position);
}

void Bullet::setMoving(bool moving) {
    m_moving = moving;
}

bool Bullet::isMoving() {
    return m_moving;
}

void Bullet::setPosition(SDL_Point pos) {
    m_position = pos;
}


