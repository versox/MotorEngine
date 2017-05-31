#include "Game.h"

//SetupGame
void Game::setupGame(Game& g) {
  g.init();
  g.main();
  g.loop();
}

//Constructors
Game::Game() {
  name = "Generic Motor Engine Game";
  displayMode = FIXED_WINDOW;
  width = 800;
  height = 400;
}

Game::Game(std::string name) {
  this->name = name;
  displayMode = FIXED_WINDOW;
  width = 800;
  height = 400;
}

Game::Game(std::string name, DisplayMode displayMode) {
  this->name = name;
  this->displayMode = displayMode;
  width = 800;
  height = 400;
}

Game::Game(std::string name, DisplayMode displayMode, int width, int height) {
  this->name = name;
  this->displayMode = displayMode;
  this->width = width;
  this->height = height;
}

//Destructor
Game::~Game() {

}

//Initialize
void Game::init() {

}

//User init
void Game::main();

//Game loop
void Game::loop() {

}

//User updatej'
void Game::update() {

}

//End
void Game::end() {

}
