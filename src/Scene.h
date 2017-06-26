#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "Object.h"

class Scene {
public:
  Scene(SDL_Renderer* Renderer, int width, int height);
  virtual ~Scene();
  //Initialize
  void init();
  //Update
  void update();
  //Render
  void render();
  //Set Background
  void setBackground(Sprite* backGroundSprite);
  void setBackground(int r, int g, int b, int a);
  //API
  //Add Object
  void addObject(Object* object);
  //Get Objects
  std::vector<Object*> getObjects() { return gameObjects; }
private:
    SDL_Renderer* renderer;
    int w, h;
    SDL_Rect screen;
    Sprite* background;
    bool imageBackground = false;
    std::vector<Object*> gameObjects;
};

#endif
