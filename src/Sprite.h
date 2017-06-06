#ifndef SPRITE_H
#define SPRITE_H

//Robbie

#include <string>
#include "SDL.h"
#include "Game.h"

class Sprite {
public:
  Sprite(std::string path, double scale=1, SDL_Renderer* renderer);
  virtual ~Sprite();
  SDL_Texture* getTexture();
  void makeTexture(std::string path);
  void setup();
  void render();
private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    double height;
    double width;
    double scale;
};

#endif
