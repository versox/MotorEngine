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
  displayMode = SCALED_FULLSCREEN;
  width = 800;
  height = 400;
  updateTime = 10;
}

Game::Game(std::string name) {
  this->name = name;
  displayMode = SCALED_FULLSCREEN;
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
  //Initialize SDL Subsystems

  //Create a window (all window stuff handled in game)
    if(SDL_Init(SDL_INIT_VIDEO)<0){
        std::printf("Unable to initialize window. Error %s\n", SDL_GetError());
    }else{
        window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, displayMode);
        if(window==NULL){
            std::printf("Unable to create window. Error %s\n", SDL_GetError());
        }else{
            surface = SDL_GetWindowSurface(window);
            
        }
    }
  //Load a default scene (Motor Engine Splash Screen)
  //Load sound (don't worry about this yet)
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
        while(SDL_PollEvent(&event)!=0){
            if(event.type == SDL_QUIT){
                quit=true;
            }
        }
     }
  }
  end();
}

//User update
void Game::update() {

}

//End
void Game::end() {
  //Destroy all scenes
  //static scene function
  //Scene::destroy();
    SDL_FreeSurface(image);
  //Destroy the window crap
    SDL_DestroyWindow(window);
    window=NULL;
  //Quit SDL Subsytems
    SDL_Quit();
}
