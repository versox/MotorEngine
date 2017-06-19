#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <tuple>
#include <vector>
#include "SDL.h"
#include "Scene.h"
#include "Object.h"

enum MouseType {MOUSE_HOVER, MOUSE_CLICK};

class EventHandler {
public:
  typedef void (Object::*ObjectCallback)();
  EventHandler();
  virtual ~EventHandler();
  bool handle(Scene* scene);
  void registerKey(SDL_Keycode key, Object& object, ObjectCallback callbackFunc);
  void registerMouse(MouseType mouseType, Object& object, ObjectCallback callbackFunc);
private:
  SDL_Event event;
  //Pointer to state of keyboard provided by SDL
  const Uint8 * keystate;

  bool mouseClick;

  typedef std::tuple<SDL_Keycode, Object&, ObjectCallback> RegisteredKey;
  std::vector<RegisteredKey> registeredKeys;
  typedef std::tuple<MouseType, Object&, ObjectCallback> RegisteredMouse;
  std::vector<RegisteredMouse> registeredMice;
};

#endif
