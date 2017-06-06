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
  //Initialize external SDL Subsystems
  if(IMG_Init(IMG_INIT_PNG)<0) {
    std::cout << "Failed to init png" << std::endl;
  }
  //Initialize main SDL system and
  //create a window (all window stuff handled in game)
  if(SDL_Init(SDL_INIT_VIDEO)<0){
      std::printf("Unable to initialize window. Error %s\n", SDL_GetError());
  } else {
      switch(displayMode) {
        case SCALED_FULLSCREEN:
          window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
          /*int* width, height;
          SDL_GetWindowSize(window, width, height);
          this->width = *width;
          this->height = *height;*/
          break;
        case FIXED_WINDOW:
          window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
          break;
      }
      if(window==NULL){
          std::printf("Unable to create window. Error %s\n", SDL_GetError());
      }
  }
  //Setup the renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    std::cout << SDL_GetError();
    SDL_Quit();
  }
  //Load a default scene (Motor Engine Splash Screen)
  Scene* splash = createScene();
  Sprite* splashImageSprite = createSprite("asset/splash.png", 1);
  Object* splashImageObject = createObject(splashImageSprite);
  splash->addObject(splashImageObject);
  setScene(splash);
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

  /*while(!quit) {
    currentTime = SDL_GetTicks();
    if(currentTime > lastTime + 10) {
        while(SDL_PollEvent(&event)!=0){
            if(event.type == SDL_QUIT){
                quit=true;
            }
        }
     }
  }*/
  end();
}

//User update
void Game::update() {

}

SDL_Window* Game::getWindow(){
    return window;
}

//End
void Game::end() {
  //Destroy all scenes
  //static scene function
  //Scene::destroy();
  SDL_DestroyRenderer(renderer);
  //Destroy the window crap
    SDL_DestroyWindow(window);
    window=NULL;
  //Quit SDL Subsytems
    SDL_Quit();
}

Scene* Game::createScene() {
  return new Scene();
}

void Game::setScene(Scene* scene) {
  currentScene = scene;
}

Sprite* Game::createSprite(std::string path, double scale) {
  Sprite* s = new Sprite(path, scale);
  s->setup(renderer);
  return s;
}

Object* Game::createObject(Sprite* sprite) {
  return new Object(sprite);
}
