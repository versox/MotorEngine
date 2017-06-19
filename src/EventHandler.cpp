#include "EventHandler.h"

EventHandler::EventHandler() {
  keystate = SDL_GetKeyboardState(NULL);
}

EventHandler::~EventHandler() {

}

bool EventHandler::handle(Scene* scene) {
  mouseClick = false;
  //Handle Events
  while(SDL_PollEvent(&event)!=0) {
    switch(event.type) {
      case SDL_MOUSEBUTTONDOWN:
        mouseClick = true;
        break;
      case SDL_QUIT:
        return true;
        break;
    }
  }
  //Handle Mouse
  for(unsigned int i = 0; i < registeredMice.size(); i++) {
    RegisteredMouse rMouse = registeredMice[i];
    MouseType mouseType = std::get<0>(rMouse);
    Object& obj = std::get<1>(rMouse);
    SDL_Rect renderBox = obj.renderBox();
    ObjectCallback callbackFunc = std::get<2>(rMouse);
    int x, y;
    SDL_GetMouseState(&x, &y);
    if(renderBox.x <= x && x <= (renderBox.x + renderBox.w) && renderBox.y <= y && y <= (renderBox.y + renderBox.h)) {
      if(mouseClick) {
        if(mouseType == MOUSE_CLICK) {
          (obj.*callbackFunc)();
        }
      } else {
        if(mouseType == MOUSE_HOVER) {
          (obj.*callbackFunc)();
        }
      }
    }
  }
  //Handle keys
  for(unsigned int i = 0; i < registeredKeys.size(); i++) {
    RegisteredKey rKey = registeredKeys[i];
    SDL_Keycode key = std::get<0>(rKey);
    SDL_Scancode scancode = SDL_GetScancodeFromKey(key);
    if(keystate[scancode]) {
      Object& obj = std::get<1>(rKey);
      ObjectCallback callbackFunc = std::get<2>(rKey);
      (obj.*callbackFunc)();
    }
  }
  return false;
}

void EventHandler::registerKey(SDL_Keycode key, Object& obj, ObjectCallback callbackFunc) {
  registeredKeys.push_back(RegisteredKey(key, obj, callbackFunc));
}

void EventHandler::registerMouse(MouseType mouseType, Object& object, ObjectCallback callbackFunc) {
  registeredMice.push_back(RegisteredMouse(mouseType, object, callbackFunc));
}
