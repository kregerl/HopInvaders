#include "renderer.h"
#include "assetmanager.h"
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>

Renderer* Renderer::s_instance = nullptr;

Renderer::Renderer() {
    m_renderer = SDL_CreateRenderer(Window::instance()->getWindow(), -1, SDL_RENDERER_SOFTWARE);

    if (m_renderer == nullptr) {
        SDL_DestroyWindow(Window::instance()->getWindow());
        throw std::runtime_error("SDL_CreateRenderer Error: " + std::string(SDL_GetError()) + "\n");
    }
}

Renderer::~Renderer() {
    SDL_DestroyRenderer(m_renderer);
}

SDL_Renderer* Renderer::getRenderer() const {
    return m_renderer;
}

void Renderer::renderPreset() {
    SDL_RenderPresent(Renderer::instance()->getRenderer());
}

void Renderer::clear() {
    SDL_RenderClear(Renderer::instance()->getRenderer());
}

void Renderer::setClearColor(SDL_Color color) {
    SDL_SetRenderDrawColor(Renderer::instance()->getRenderer(), color.r, color.g, color.b, color.a);
}

Renderer* Renderer::instance() {
    if (s_instance == nullptr) {
        s_instance = new Renderer();

        int flags = IMG_INIT_PNG;
        if (!(IMG_Init(flags) & flags)) {
            throw std::runtime_error("Error initializing SDL_Image at IMG_Init: " + std::string(IMG_GetError()) + "\n");
        }

        if (TTF_Init() < 0) {
            throw std::runtime_error("Error initializing SDL_ttf at TTF_Init: " + std::string(TTF_GetError()) + "\n");
        }
    }
    return s_instance;
}

void Renderer::release() {
    IMG_Quit();
    TTF_Quit();
    delete s_instance;
    s_instance = nullptr;
}

SDL_Texture* Renderer::loadTexture(const std::string& path) {
    SDL_Texture* tex = IMG_LoadTexture(Renderer::instance()->getRenderer(), path.c_str());
    if (tex == nullptr) {
        throw std::runtime_error("Error loading texture: " + std::string(SDL_GetError()) + "\n");
    }
    return tex;
}

TTF_Font* Renderer::loadFont(const std::string& path, int size) {
    TTF_Font* font = TTF_OpenFont(path.c_str(), size);
    if (font == nullptr) {
        throw std::runtime_error("Error loading font: " + std::string(SDL_GetError()) + "\n");
    }
    return font;
}

SDL_Texture*
Renderer::createTextTexture(const std::string& fontName, int fontSize, const std::string& text, SDL_Color color) {
    TTF_Font* font = AssetManager::instance()->getFont(fontName, fontSize);

    SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
    if (surface == nullptr) {
        throw std::runtime_error("Error creating surface: " + std::string(SDL_GetError()) + "\n");
    }

    SDL_Texture* texture = SDL_CreateTextureFromSurface(Renderer::instance()->getRenderer(), surface);
    if (texture == nullptr) {
        throw std::runtime_error("Error creating texture from surface: " + std::string(SDL_GetError()) + "\n");
    }

    return texture;
}



