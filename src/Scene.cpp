#include "Scene.h"

Scene::Scene(SDL_Renderer* Renderer, int width, int height) {
    renderer = Renderer;
    w= width;
    h= height;
    screen = {
      0, 0, width, height
    };
}

Scene::~Scene() {

}

void Scene::update() {
  for(unsigned int i = 0; i < gameObjects.size(); i++) {
    gameObjects[i]->update();
  }
}

void Scene::render() {
  SDL_RenderClear(renderer);
  if(imageBackground) {
    SDL_RenderCopy(renderer, background->getTexture(), NULL, &screen);
  }
  for(unsigned int i = 0; i < gameObjects.size(); i++) {
    SDL_Texture* texture = gameObjects[i]->getSprite()->getTexture();
    SDL_Rect rect = gameObjects[i]->renderBox();
    /*SDL_Rect rect {
      0, 0, 640, 360
    };*/
    SDL_RenderCopy(renderer, texture, NULL, &rect);
  }
  SDL_RenderPresent(renderer);
}

void Scene::setBackground(Sprite* backGroundSprite){
  background = backGroundSprite;
  imageBackground = true;
}

void Scene::setBackground(int r, int g, int b, int a){
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    imageBackground = false;
}

void Scene::addObject(Object* object) {
  gameObjects.push_back(object);
}
