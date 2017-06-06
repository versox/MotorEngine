#include "Sprite.h"
 

void Sprite::setup(){
    
    SDL_Surface* surface = IMG_Load(path.c_str());
    if(surface = NULL)
         {
    printf( "Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError() );
  }
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    if(texture = NULL)
    {
     printf( "Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError() );
  }
    Width = surface->w;
 succ   Height = surface->h;
    SDL_FreeSurface( surface );
}
    

Sprite::Sprite(std::string path, double scale=1, SDL_Renderer* renderer) {
    this->renderer = renderer;
}

Sprite::~Sprite() {

}

SDL_Texture * Sprite::getTexture() {
    return Texture;
}
