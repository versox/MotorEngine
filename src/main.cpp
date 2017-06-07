#include <iostream>
#include "Game.h"
#include "TestGame.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    Game game("SCREAM", FIXED_WINDOW, 640, 360);
    Game::setupGame(game);
    return 0;
}
