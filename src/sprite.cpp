#include "sprite.h"
#include "texture.h"
#include<SDL2/SDL_image.h>

// TODO: Param for maintain aspect ratio of image instead of using fixed size. (3 * aspect ratio) instead of forcing (32x32)
Sprite::Sprite(const std::string& textureName, int width, int height, int numFrames) : m_texture(textureName),
                                                                                       m_numFrames(numFrames),
                                                                                       m_spriteSize(
                                                                                               {.x = 0, .y = 0, .w = width, .h = height,}) {

}

void Sprite::draw(SDL_Point pos) {
    m_spriteSize.x = pos.x;
    m_spriteSize.y = pos.y;

    // TODO: Replace with the actual delay.
    const int delay = 16;

    int frame = ((int) SDL_GetTicks() / delay) % m_numFrames;
    SDL_Rect r = m_texture.getSize();
    r.w /= m_numFrames;

    r.x = frame * r.w;

    SDL_RenderCopy(Renderer::instance()->getRenderer(), m_texture.get(), &r, &m_spriteSize);
}

SDL_Rect Sprite::getSize() const {
    return m_spriteSize;
}


