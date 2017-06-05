#include "Scene.h"

Scene::Scene(SDL_Window * window) {
  this->window = window;
}

Scene::~Scene() {
  SDL_DestoryRenderer(renderer);
}

void Scene::init() {
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    std::cout << SDL_GetError();
    SDL_Quit();
  }
}

void Scene::update() {

}

void Scene::addObject(Object* object) {
  gameObjects.push_back(object);
}
