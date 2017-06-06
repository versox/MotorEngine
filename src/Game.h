#ifndef GAME_H
#define GAME_H

#include <string>
#include <cstdio>
#include "SDL.h"
#include "SDL_image.h"
#include "Scene.h"

enum DisplayMode {SCALED_FULLSCREEN, FIXED_WINDOW};

class Game {
public:
  //Setup Game
  static void setupGame(Game& g);
  //Constructors
  Game();
  Game(std::string name);
  Game(std::string name, DisplayMode displayMode);
  Game(std::string name, DisplayMode displayMode, int width, int height);
  Game(std::string name, DisplayMode displayMode, int width, int height, int updateTime);
  //Destructor
  virtual ~Game();
  //Initialize
  void init();
  //User init code
  virtual void setup();
  //Game Loop
  void loop();
  //User update code
  virtual void update();
  //End
  void end();

  //API
  Scene* createScene();
  void setScene(Scene* scene);

  SDL_Window * getWindow();
private:
  //Window
  SDL_Window* window;
  std::string name;
  DisplayMode displayMode;
  int width;
  int height;
  int updateTime;

  //Scene
  Scene* scene;
};

#endif
