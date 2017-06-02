#ifndef SPRITE_H
#define SPRITE_H

//Robbie

#include <string>
#include "SDL.h"

class Sprite {
public:
  Sprite(std::string path, double scale=1);
  virtual ~Sprite();
  SDL_Texture * getTexture();
  void setup();
  void render();
};

#endif
