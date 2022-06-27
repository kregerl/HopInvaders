#include <SDL2/SDL.h>
#include "game.h"

int main() {

    try {
        Game game = Game();
        game.run();
    } catch (std::runtime_error& e) {
        fprintf(stderr, "%s", e.what());
    }
    SDL_Quit();
    return EXIT_SUCCESS;
}
