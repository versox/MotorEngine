#ifndef OBJECT_H
#define OBJECT_H

#include "Sprite.h"

class Object {
public:
  Object(Sprite* sprite, int xPos, int yPos, int w, int h);
  virtual ~Object();
  Sprite* getSprite();
  SDL_Rect renderBox();
  bool collision(Object* obj1, Object* obj2);
  int x, y;
private:
  Sprite* sprite;
  int width, height;
};

#endif
