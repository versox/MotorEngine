#include "MovingBox.h"

MovingBox::MovingBox(Sprite* sprite, int x, int y, int w, int h, Object* boxPlayer) : Object(sprite, x, y, w, h) {
  this->boxPlayer = boxPlayer;
}

MovingBox::~MovingBox() {

}

void MovingBox::update() {
  if(this->collision(this, boxPlayer)) {
    this->y -= 1;
  }
}
