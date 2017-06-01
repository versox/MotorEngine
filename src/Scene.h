#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"

class Scene {
public:
  Scene();
  virtual ~Scene();
  //Update
  void update();
  //Add Object
  void addObject(Object object);
  //Remove Object
  void removeObject(Object object);
  SDL_Renderer * getRenderer();
private:
  SDL_Renderer * renderer;
};

#endif
