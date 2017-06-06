#ifndef OBJECT_H
#define OBJECT_H

#include "Sprite.h"

class Object {
public:
  Object(Sprite* sprite);
  virtual ~Object();
  Sprite* getSprite();
private:
  Sprite* sprite;
};

#endif
