#include "collider.h"

Collider::Collider(SDL_Rect size) : m_rect(size) {
}

Collider::Collider(SDL_Rect size, SDL_Point pos) : m_rect(SDL_Rect{pos.x, pos.y, size.w, size.h}) {
}

SDL_Point Collider::getPos() {
    return SDL_Point{m_rect.x, m_rect.y};
}

void Collider::setPosX(int x) {
    m_rect.x = x;
}

void Collider::setPosY(int y) {
    m_rect.y = y;
}

void Collider::setPos(SDL_Point pos) {
    m_rect.x = pos.x;
    m_rect.y = pos.y;
}

bool Collider::isWithin(Collider collider) const {
    return (top() > collider.top() && right() < collider.right() && bottom() < collider.bottom() &&
            left() > collider.left());
}

int Collider::top() const {
    return m_rect.y;
}

int Collider::bottom() const {
    return m_rect.y + m_rect.h;
}

int Collider::left() const {
    return m_rect.x;
}

int Collider::right() const {
    return m_rect.x + m_rect.w;
}




