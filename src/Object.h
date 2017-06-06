#ifndef OBJECT_H
#define OBJECT_H

#include "Sprite.h"

class Object {
public:
  Object(Sprite* sprite);
  virtual ~Object();
private:
  Sprite* sprite;
};

#endif
