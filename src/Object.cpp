#include "Object.h"

Object::Object(Sprite* sprite) {
  this->sprite = sprite;
}

Object::~Object() {

}

Sprite* Object::getSprite() {
  return sprite;
}
