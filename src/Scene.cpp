#include "Scene.h"

Scene::Scene() {

}

Scene::~Scene() {

}

void Scene::update() {

}

void Scene::render(SDL_Renderer* renderer) {

}

void Scene::addObject(Object* object) {
  gameObjects.push_back(object);
}
