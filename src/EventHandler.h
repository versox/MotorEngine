#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <tuple>
#include <vector>
#include "SDL.h"
#include "Scene.h"
#include "Object.h"

class EventHandler {
public:
  EventHandler();
  virtual ~EventHandler();
  bool handle(Scene* scene);
  void registerKey(SDL_Keycode key, Object& obj, void * callbackFunc);
private:
  SDL_Event event;

  typedef std::tuple<SDL_Keycode, Object&, void (Object::*) ()> RegisteredKey;
  std::vector<RegisteredKey> registeredKeys;
};

#endif
