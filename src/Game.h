#ifndef GAME_H
#define GAME_H

#include <string>
#include "SDL.h"

enum DisplayMode {SCALED_FULLSCREEN, FIXED_WINDOW};

class Game {
public:
  //SetupGame
  static void setupGame(Game& g);
  //Constructors
  Game();
  Game(std::string name);
  Game(std::string name, DisplayMode displayMode);
  Game(std::string name, DisplayMode displayMode, int width, int height);
  //Destructor
  virtual ~Game();
  //Initialize
  void init();
  //User init code
  virtual void main();
  //Game Loop
  void loop();
  //User update code
  virtual void update();
  //End
  void end();
private:
  std::string name;
  DisplayMode displayMode;
  int width;
  int height;
};

#endif
