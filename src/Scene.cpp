#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::update() {

}

void Scene::render(SDL_Renderer* renderer) {
  SDL_RenderClear(renderer);
  for(unsigned int i = 0; i < gameObjects.size(); i++) {
    SDL_Texture* texture = gameObjects[i]->getSprite()->getTexture();
    SDL_Rect rect {
      0, 0, 640, 360
    };
    SDL_RenderCopy(renderer, texture, NULL, &rect);
  }
  SDL_RenderPresent(renderer);
}

void Scene::addObject(Object* object) {
  gameObjects.push_back(object);
}
