#ifndef HOPINVADERS_WINDOW_H
#define HOPINVADERS_WINDOW_H

#include <string>

#include <SDL2/SDL.h>
#include <memory>


class Window {
public:
    static Window* instance();

    static void release();

    [[nodiscard]] SDL_Window* getWindow() const;

    SDL_Rect getWindowSize();

private:
    Window();

    ~Window();

private:
    static Window* s_instance;

    SDL_Window* m_window;
    SDL_Rect m_windowSize;
};


#endif //HOPINVADERS_WINDOW_H
