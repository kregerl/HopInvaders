#include "bullet.h"

#include <utility>

#define VELOCITY 2

Bullet::Bullet(Sprite sprite, SDL_Point position, Bullet::Direction dir) : m_sprite(std::move(sprite)),
                                                                           m_collider(m_sprite.getSize(), position),
                                                                           m_moving(false), m_direction(dir) {

}

void Bullet::onUpdate() {
    if (m_moving) {
        m_collider.setPosY(m_collider.getPos().y + static_cast<int>(m_direction) * VELOCITY);
    }


    m_sprite.draw(m_collider.getPos());
}

void Bullet::setMoving(bool moving) {
    m_moving = moving;
}

bool Bullet::isMoving() {
    return m_moving;
}

void Bullet::setPosition(SDL_Point pos) {
    m_collider.setPos(pos);
}

Collider Bullet::getCollider() const {
    return m_collider;
}


