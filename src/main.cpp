#include <iostream>
#include "Game.h"
#include "Scene.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
    Game game("Test", FIXED_WINDOW);
    game.startGame();
    return 0;
}
