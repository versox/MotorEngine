#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "SDL.h"

class Scene {
public:
  Scene(SDL_Window* window);
  virtual ~Scene();
  //Initialize
  void init();
  //Update
  void update();
  //Get Renderer
  SDL_Renderer * getRenderer();

  //API
  //Add Object
  void addObject(Object* object);
private:
  SDL_Window * window;
  SDL_Renderer * renderer;
  std::vector<Object*> gameObjects;
};

#endif
