#include "Game.h"
#include <Sound.cpp>
//Constructors
Game::Game() {
  name = "Generic Motor Engine Game";
  displayMode = FIXED_WINDOW;
  width = 640;
  height = 360;
  updateTime = 10;
  gameMode = SPLASH;
  init();
}

Game::Game(std::string name) {
  this->name = name;
  displayMode = FIXED_WINDOW;
  width = 640;
  height = 360;
  updateTime = 10;
  gameMode = SPLASH;
  init();
}

Game::Game(std::string name, DisplayMode displayMode) {
  this->name = name;
  this->displayMode = displayMode;
  width = 640;
  height = 360;
  updateTime = 10;
  gameMode = SPLASH;
  init();
}

Game::Game(std::string name, DisplayMode displayMode, int width, int height) {
  this->name = name;
  this->displayMode = displayMode;
  this->width = width;
  this->height = height;
  updateTime = 10;
  gameMode = SPLASH;
  init();
}

Game::Game(std::string name, DisplayMode displayMode, int width, int height, int updateTime) {
  this->name = name;
  this->displayMode = displayMode;
  this->width = width;
  this->height = height;
  this->updateTime = updateTime;
  gameMode = SPLASH;
  init();
}

//Destructor
Game::~Game() {
  end();
}

//Initialize
void Game::init() {
  //Initialize main SDL system and
  //create a window (all window stuff handled in game)
  if(SDL_Init(SDL_INIT_VIDEO)<0){
      std::printf("Unable to initialize window. Error %s\n", SDL_GetError());
  } else {
      switch(displayMode) {
        case SCALED_FULLSCREEN:
          window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_FULLSCREEN_DESKTOP);
          SDL_GetWindowSize(window, &width, &height);
          break;
        case FIXED_WINDOW:
          window = SDL_CreateWindow(name.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL);
          break;
      }
      if(window==NULL){
          std::printf("Unable to create window. Error %s\n", SDL_GetError());
      }
  }
  //Initialize external SDL Subsystems
  if(IMG_Init(IMG_INIT_PNG)<0) {
    std::cout << "Failed to init png" << std::endl;
  }
  //Sound
  //Mix_OpenAudio
 
  if( Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, 2, 4096 ) < 0 ){
         std::cout << "Mix OpenAudio error" << std::endl;
  }
 
 
 
  
  //Setup the renderer
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    std::cout << SDL_GetError();
    SDL_Quit();
  }
  //Set a white background color
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  //Load a default scene (Motor Engine Splash Screen)
  splashScene = createScene();
  Sprite* splashImageSprite = createSprite("asset/splash.png", 1);
  Object* splashImageObject = createObject(splashImageSprite, getWidth() / 2, getHeight() / 2, getWidth(), getHeight());
  splashScene->addObject(splashImageObject);
  setScene(splashScene);
  //Load sound (don't worry about this yet)
}

//Game loop
void Game::loop() {
  unsigned int lastTime = 0;
  unsigned int currentTime;
  unsigned int splashTime = 500;

  while(gameMode != QUIT) {
    currentTime = SDL_GetTicks();
    if(currentTime > lastTime + 10) {
      switch(gameMode) {
        case SPLASH:
          if(splashTime > 0) {
            if(eventHandler.handle(splashScene)) {
              gameMode = QUIT;
            }
            splashScene->render(renderer);
            splashTime--;
          } else {
            gameMode = GAME;
            std::cout << "Game!" << std::endl;
          }
          break;
        case GAME:
          if(eventHandler.handle(currentScene)) {
            gameMode = QUIT;
          }
          currentScene->render(renderer);
          break;
        case QUIT:
          break;
      }
    }
  }
  end();
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
    //Quit Sound
    //Mix_Closeaudio
    
    Mix_CloseAudio();
    
    
    
  //Quit SDL Subsytems
    SDL_Quit();
}

// API
void Game::startGame() {
  loop();
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

Object* Game::createObject(Sprite* sprite, int xPos, int yPos, int w, int h) {
  return new Object(sprite, xPos, yPos, w, h);
}

SDL_Window* Game::getWindow(){
    return window;
}
