#include "EventHandler.h"

EventHandler::EventHandler() {

}

EventHandler::~EventHandler() {

}

bool EventHandler::handle(Scene* scene) {
  while(SDL_PollEvent(&event)!=0) {
    if(event.type == SDL_QUIT){
      return true;
    }
  }
  return false;
}

void EventHandler::registerKey(SDL_Keycode key, Object& obj, ObjectCallback callbackFunc) {
  registeredKeys.push_back(RegisteredKey(key, obj, callbackFunc));
}
