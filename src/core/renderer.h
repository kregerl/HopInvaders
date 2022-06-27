#ifndef HOPINVADERS_RENDERER_H
#define HOPINVADERS_RENDERER_H


#include <SDL2/SDL_ttf.h>
#include "window.h"

class Renderer {
public:
    static Renderer* instance();

    static void release();

    static void renderPreset();

    static void clear();

    static void setClearColor(SDL_Color color);

    static SDL_Texture* loadTexture(const std::string& path);

    static SDL_Texture*
    createTextTexture(const std::string& fontName, int fontSize, const std::string& text, SDL_Color color);

    static TTF_Font* loadFont(const std::string& path, int size);

    [[nodiscard]] SDL_Renderer* getRenderer() const;

private:
    Renderer();

    ~Renderer();

private:
    static Renderer* s_instance;

    SDL_Renderer* m_renderer;
};


#endif //HOPINVADERS_RENDERER_H
