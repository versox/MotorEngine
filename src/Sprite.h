#ifndef SPRITE_H
#define SPRITE_H

//Robbie

#include <string>
#include "SDL.h"

class Sprite {
public:
  Sprite(std::string path);
  virtual ~Sprite();
  SDL_Texture * getTexture();
};

#endif
