#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include "SDL.h"

class Scene {
public:
  Scene(SDL_Window* window);
  virtual ~Scene();
  //Initialize
  void init();
  //Set Scene
  void setScene();
  //Update
  void update();
  //Add Object
//  void addObject(Object object);
  //Remove Object
//  void removeObject(Object object);
  SDL_Renderer * getRenderer();
private:
  SDL_Window * window;
  SDL_Renderer * renderer;
};

#endif
