#ifndef HOPINVADERS_GAME_H
#define HOPINVADERS_GAME_H

#include <vector>
#include "window.h"
#include "sprite.h"
#include "renderer.h"
#include "player.h"
#include "../components/textcomponent.h"


enum class GameState {
    PAUSED,
    RUNNING,
    STOPPED,
    EXITED
};


class Game {
public:
    explicit Game();

    void run();

    void pollEvents(SDL_Event& e);

private:
    Player m_player;
    GameState m_state;
    std::vector<TextComponent> m_textComponents;
};


#endif //HOPINVADERS_GAME_H
