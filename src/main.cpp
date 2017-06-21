#include <iostream>
#include "Game.h"
#include "Scene.h"
#include "Sound.h"

#ifdef main
# undef main
#endif

int main(int argc, char* args[]) {
  //This is a graphics test / demo... Feel free to delete it and make your own game :)
    Game game("Test", SCALED_FULLSCREEN);
    Scene* testScene = game.createScene();
    testScene->setBackground(21, 155, 185, 0);
    Sprite* boxSprite = game.createSprite("asset/box.png");
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2, game.getHeight() / 2 , 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 100, game.getHeight() / 2 , 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 200, game.getHeight() / 2 , 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 200, game.getHeight() / 2 + 100, 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 200, game.getHeight() / 2 + 200, 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2, game.getHeight() / 2 + 100, 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2, game.getHeight() / 2 + 200, 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 100, game.getHeight() / 2 + 200, 100, 100));
    testScene->addObject(game.createObject(boxSprite, game.getWidth() / 2 + 200, game.getHeight() / 2 + 200, 100, 100));
    game.setScene(testScene);
    game.startGame();
    return 0;
}
