#ifndef SCENE_H
#define SCENE_H

#include "SDL.h"

class Scene {
public:
  Scene();
  virtual ~Scene();
  SDL_Renderer * getRenderer();
private:
  SDL_Renderer * renderer;
};

#endif
