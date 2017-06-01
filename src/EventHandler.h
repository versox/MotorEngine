#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

class EventHandler {
public:
  EventHandler();
  virtual ~EventHandler();
  void handle();
  void registerKey();
};

#endif
