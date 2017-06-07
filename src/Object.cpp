#include "Object.h"

Object::Object(Sprite* sprite, int xPos, int yPos, int w, int h) {
  this->sprite = sprite;
  this->x = xPos;
  this->y = yPos;
  this->width = w;
  this ->height = h;
}

Object::~Object() {

}

Sprite* Object::getSprite() {
  return sprite;
}

SDL_Rect Object::renderBox(){
    SDL_Rect renderRect;
    renderRect.x=this->x-(this->width/2);
    renderRect.y=this->y-(this->height/2);
    renderRect.w=this->width-(this->x/2);
    renderRect.h=this->height-(this->y/2);
    
    return renderRect;
}

bool Object::collision(Object* obj1, Object* obj2){
    bool collide=false;
    if(((obj1->x+(obj1->width/2))<=(obj2->x+(obj2->width/2)))&&((obj1->x-(obj1->width/2)>(obj2->x-(obj2->width/2))))){
        collide = true;
    }
    return collide;
}