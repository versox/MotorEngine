#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <cstdio>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_mixer.h"
#include "EventHandler.h"
#include "Scene.h"
#include "Sprite.h"
#include "Object.h"

enum DisplayMode {SCALED_FULLSCREEN, FIXED_WINDOW};
enum GameMode {QUIT, SPLASH, GAME};

class Game {
public:
  //Constructors
  Game();
  Game(std::string name);
  Game(std::string name, DisplayMode displayMode);
  Game(std::string name, DisplayMode displayMode, int width, int height);
  Game(std::string name, DisplayMode displayMode, int width, int height, int updateTime);
  //Destructor
  virtual ~Game();
private:
  //Initialize
  void init();
  //Game Loop
  void loop();
  //End
  void end();

public:
  //API
  int getWidth() { return width; }
  int getHeight() { return height; }
  void startGame();
  //Scenes
  Scene* createScene();
  void setScene(Scene* scene);
  //Sprites
  Sprite* createSprite(std::string path, double scale = 1);
  //ObjectS
  Object* createObject(Sprite* sprite, int xPos, int yPos, int w, int h);
  SDL_Window * getWindow();
private:
  GameMode gameMode;
  EventHandler eventHandler;
  //Window
  SDL_Window* window;
  SDL_Renderer* renderer;
  std::string name;
  DisplayMode displayMode;
  int width;
  int height;
  int updateTime;

  //Scene
  Scene* splashScene;
  Scene* currentScene;
};

#endif
