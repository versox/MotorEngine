#include "Game.h"

//SetupGame
void Game::setupGame(Game& g) {
  g.init();
  g.setup();
  g.loop();
  g.end();
}

//Constructors
Game::Game() {
  name = "Generic Motor Engine Game";
  displayMode = FIXED_WINDOW;
  width = 800;
  height = 400;
  updateTime = 10;
}

Game::Game(std::string name) {
  this->name = name;
  displayMode = FIXED_WINDOW;
  width = 800;
  height = 400;
  updateTime = 10;
}

Game::Game(std::string name, DisplayMode displayMode) {
  this->name = name;
  this->displayMode = displayMode;
  width = 800;
  height = 400;
  updateTime = 10;
}

Game::Game(std::string name, DisplayMode displayMode, int width, int height) {
  this->name = name;
  this->displayMode = displayMode;
  this->width = width;
  this->height = height;
  updateTime = 10;
}

Game::Game(std::string name, DisplayMode displayMode, int width, int height, int updateTime) {
  this->name = name;
  this->displayMode = displayMode;
  this->width = width;
  this->height = height;
  this->updateTime = updateTime;
}

//Destructor
Game::~Game() {

}

//Initialize
void Game::init() {

}

//User init
void Game::setup() {

}

//Game loop
void Game::loop() {
  bool quit = false;
  unsigned int lastTime = 0;
  unsigned int currentTime;

  while(!quit) {
    currentTime = SDL_GetTicks();
    if(currentTime > lastTime + 10) {

    }
  }
}

//User updatej'
void Game::update() {

}

//End
void Game::end() {

}
