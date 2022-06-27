#include "window.h"
#include <stdexcept>

Window* Window::s_instance = nullptr;

Window::Window() : m_windowSize(SDL_Point{.x=1280, .y=720}) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_JOYSTICK) != 0) {
        throw std::runtime_error("Could not initalize SDL2: " + std::string(SDL_GetError()) + "\n");
    }
    SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");

    m_window = SDL_CreateWindow("Hop Invaders", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, m_windowSize.x,
                                m_windowSize.y,
                                SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (m_window == nullptr) {
        throw std::runtime_error("SDL_CreateWindow Error: " + std::string(SDL_GetError()) + "\n");
    }
}

Window::~Window() {
    SDL_DestroyWindow(m_window);
}

SDL_Window* Window::getWindow() const {
    return m_window;
}

SDL_Point Window::getWindowSize() {
    return m_windowSize;
}

Window* Window::instance() {
    if (s_instance == nullptr) {
        s_instance = new Window();
    }
    return s_instance;
}

void Window::release() {
    delete s_instance;
    s_instance = nullptr;
}

