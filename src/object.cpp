/* 
 * File:   object.cpp
 * Author: mathp0455
 * 
 * Created on June 1, 2017, 10:30 AM
 */

#include "object.h"

object::object(Game* window, Sprite* sprite, int xPos, int yPos, int size) {
    this->window = window;
    this->sprite = sprite;
    this->xPos = xPos;
    this ->yPos = yPos;
    this->size = size;
    visible = true;
}

object::~object() {
}

int object::getID(){
    return objID;
}