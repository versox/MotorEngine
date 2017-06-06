#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <vector>
#include "SDL.h"
#include "Object.h"

class Scene {
public:
  Scene();
  virtual ~Scene();
  //Initialize
  void init();
  //Update
  void update();
  //Render
  void render(SDL_Renderer* renderer);

  //API
  //Add Object
  void addObject(Object* object);
private:
  std::vector<Object*> gameObjects;
};

#endif
