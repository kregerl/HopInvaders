#include "player.h"

#define MOVEMENT_SPEED 10
#define BOTTOM_MARGIN 5


Player::Player() :
        m_position({.x = Window::instance()->getWindowSize().x / 2, .y=Window::instance()->getWindowSize().y -
                                                                       (m_sprite.m_spriteSize.h + BOTTOM_MARGIN)}),
        m_sprite("HopThruster.png",
                 64, 64) {
}

void Player::onUpdate() {
    const Uint8* keyState = SDL_GetKeyboardState(nullptr);
    if (keyState[SDL_SCANCODE_LEFT]) {
        m_position.x -= MOVEMENT_SPEED;
    }
    if (keyState[SDL_SCANCODE_RIGHT]) {
        m_position.x += MOVEMENT_SPEED;
    }
    if (keyState[SDL_SCANCODE_UP]) {
        shoot();
    }

    m_sprite.draw(m_position);
    if (m_bullet) {
        m_bullet->onUpdate();
    }
}

void Player::shoot() {
    if (!m_bullet) {
        SDL_Point centeredPos = m_position;
        Sprite bulletSprite = Sprite("HopThruster.png", 16, 16);
        centeredPos.x += (m_sprite.getSize().w / 2) - (bulletSprite.getSize().w / 2);

        m_bullet = Bullet(bulletSprite, centeredPos, Bullet::Direction::Up);
        m_bullet->setMoving(true);
    }
}
