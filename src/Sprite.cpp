#include "Sprite.h"


void Sprite::setup(SDL_Renderer* renderer) {

    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface == NULL)
         {
    std::cout << "Unable to load image! SDL_image Error: " << IMG_GetError();
  }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture == NULL)
    {
     std::cout << "Unable to create texture. SDL Error: " << SDL_GetError();
  }
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface( surface );
}


Sprite::Sprite(std::string path, double scale) {
    this->path = path;
    this->scale = scale;
}

Sprite::~Sprite() {

}

SDL_Texture * Sprite::getTexture() {
    return texture;
}
