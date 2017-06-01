#include <iostream>
#include "Game.h"
#include "TestGame.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    Game game;
    Game::setupGame(game);
    return 0;
}
