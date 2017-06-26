#include <iostream>
#include <vector>
#include "Game.h"
#include "EventHandler.h"
#include "Scene.h"
#include "Sound.h"

#include "SceneSwitcher.h"
#include "MovingBox.h"

#ifdef main
# undef main
#endif

//The code in main.cpp acts as a demo

//The following files are not needed for MotorEngine to function
//they were just included as part of the demo:
// SceneSwitcher.cpp
// SceneSwitcher.h
// MovingBox.cpp
// MovingBox.h

typedef void (Object::*ObjectCallback)();

int main(int argc, char* args[]) {
    Game game("Demo", FIXED_WINDOW, 1280, 720);

    //Field Scene:
    //demonstrates a basic object with simple movement
    Scene* fieldScene = game.createScene();
    Sprite* fieldSprite = game.createSprite("asset/field.png");
    fieldScene->setBackground(fieldSprite);

    Sprite* boxSprite = game.createSprite("asset/box.png");
    Object* box = new Object(boxSprite, game.getWidth() / 2, game.getHeight() / 2, 225, 225);
    fieldScene->addObject(box);
    game.getEventHandler()->registerControl(X_AXIS, SDLK_RIGHT, SDLK_LEFT, *box, 1);
    game.getEventHandler()->registerControl(Y_AXIS, SDLK_DOWN, SDLK_UP, *box, 1);

    //Fog (tree) Scene:
    Scene* fogScene = game.createScene();
    Sprite* fogSprite = game.createSprite("asset/fog.png");
    fogScene->setBackground(fogSprite);

    //we use the same box from the field scene
    fogScene->addObject(box);

    MovingBox* box2 = new MovingBox(boxSprite, game.getWidth() - (game.getWidth() / 4), game.getHeight() - (game.getHeight() / 4), 112, 112, box);
    MovingBox* box3 = new MovingBox(boxSprite, game.getWidth() / 4, game.getHeight() - (game.getHeight() / 4), 112, 112, box);
    MovingBox* box4 = new MovingBox(boxSprite, 0, game.getHeight() - (game.getHeight() / 4), 112, 112, box);

    fogScene->addObject(box2);
    fogScene->addObject(box3);
    fogScene->addObject(box4);

    //Bird Scene:
    Scene* birdScene = game.createScene();
    Sprite* birdSprite = game.createSprite("asset/bird.png");
    birdScene->setBackground(birdSprite);

    //Scenes
    std::vector<Scene*> scenes;
    scenes.push_back(fieldScene);
    scenes.push_back(fogScene);
    scenes.push_back(birdScene);

    //Scene Switcher
    Sprite* flip = game.createSprite("asset/flip.png");
    SceneSwitcher* sceneSwitcher = new SceneSwitcher(flip, game.getWidth() - (game.getWidth() / 8), game.getHeight() - (game.getHeight() / 8), 128, 128, scenes, &game);
    for(unsigned int i = 0; i < scenes.size(); i++) {
      scenes[i]->addObject(sceneSwitcher);
    }

    //Handle mouseclicks and call user defined functions
    game.getEventHandler()->registerMouse(MOUSE_CLICK, *sceneSwitcher, static_cast<ObjectCallback>(&SceneSwitcher::switchScene));

    game.setScene(fieldScene);
    game.startGame();
    return 0;
}
