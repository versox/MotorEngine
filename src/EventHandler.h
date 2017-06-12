#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include "Scene.h"

class EventHandler {
public:
  EventHandler();
  virtual ~EventHandler();
  bool handle(Scene& scene);
  void registerKey();
private:
  SDL_Event event;
};

#endif
