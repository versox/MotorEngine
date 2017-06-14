#ifndef SPRITE_H
#define SPRITE_H

//Robbie

#include <iostream>
#include <string>
#include "SDL.h"
#include "SDL_image.h"

class Sprite {
public:
  Sprite(std::string path, double scale = 1.0);
  virtual ~Sprite();
  SDL_Texture* getTexture();
  void setup(SDL_Renderer* renderer);
private:
    SDL_Texture* texture;
    std::string path;
    double height;
    double width;
    double scale;
};

#endif
