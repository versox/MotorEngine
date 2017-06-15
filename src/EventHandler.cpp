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

void EventHandler::registerKey(SDL_Keycode key, Object& obj, void * callbackFunc) {
  /*void *gptr = dlsym(some symbol..) ;
typedef void (*fptr)();
fptr my_fptr = reinterpret_cast<fptr>(reinterpret_cast<long>(gptr)) ;*/

  //typedef void (Object::*)()
  //registeredKeys.push_back(RegisteredKey(key, obj, ));
}
