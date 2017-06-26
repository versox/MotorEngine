#ifndef MOVING_BOX_H
#define MOVING_BOX_H

#include <iostream>
#include "Sprite.h"
#include "Object.h"

class MovingBox : public Object {
public:
  MovingBox(Sprite* sprite, int x, int y, int w, int h, Object* boxPlayer);
  virtual ~MovingBox();
  void update();
private:
  Object* boxPlayer;
};

#endif
