#include "Scene.h"

Scene::Scene(SDL_Window * window) {
  this->window = window;
  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if(renderer == NULL) {
    std::cout << SDL_GetError();
    SDL_Quit();
  }

}

Scene::~Scene() {

}

void Scene::init() {

}

void Scene::setScene() {

}

void Scene::update() {

}

void Scene::addObject() {

}

void Scene::removeObject() {
  
}
