#include "game.h"
#include "assetmanager.h"

#include <SDL2/SDL_ttf.h>

#define HEADER_FONT_SIZE 20

Game::Game() : m_state(GameState::RUNNING) {

    auto windowSize = Window::instance()->getWindowSize();
    SDL_RenderSetLogicalSize(Renderer::instance()->getRenderer(), windowSize.w, windowSize.h);
    m_textComponents.emplace_back("space_invaders.ttf", "Score", SDL_Point{.x=0, .y=0}, HEADER_FONT_SIZE);
    m_textComponents.emplace_back("space_invaders.ttf", "High Score", SDL_Point{.x=(windowSize.w / 2), .y=0},
                                  HEADER_FONT_SIZE,
                                  Alignment::Center);
    m_textComponents.emplace_back("space_invaders.ttf", "Lives", SDL_Point{.x=windowSize.w, .y=0}, HEADER_FONT_SIZE,
                                  Alignment::Right);
}

void Game::run() {
    SDL_Event e;

    while (m_state != GameState::EXITED) {
        while (SDL_PollEvent(&e)) {
            pollEvents(e);
        }
        Renderer::clear();
        if (m_state == GameState::RUNNING) {
            m_player.onUpdate();

            for (auto& tc : m_textComponents) {
                tc.onUpdate();
            }

        } else if (m_state == GameState::PAUSED) {
//            m_test.draw();
        }
        Renderer::renderPreset();
        SDL_Delay(16);
    }
    AssetManager::release();
    Renderer::release();
    Window::release();
    SDL_Quit();
}

void Game::pollEvents(SDL_Event& e) {
    switch (e.type) {
        case SDL_QUIT: {
            m_state = GameState::EXITED;
            break;
        }
        case SDL_KEYDOWN: {
            switch (e.key.keysym.sym) {
                case SDLK_ESCAPE: {
                    if (m_state == GameState::PAUSED) {
                        m_state = GameState::RUNNING;
                    } else if (m_state == GameState::RUNNING) {
                        m_state = GameState::PAUSED;
                    }
                    break;
                }
            }
            break;
        }
        default: {}
    }
}
