#include "SceneSwitcher.h"

SceneSwitcher::SceneSwitcher(Sprite* sprite, int x, int y, int w, int h, std::vector<Scene*> scenes, Game* game) : Object(sprite, x, y, w, h) {
  this->game = game;
  this->scenes = scenes;
  currentScene = 0;
}

SceneSwitcher::~SceneSwitcher() {

}

void SceneSwitcher::switchScene() {
  currentScene++;
  if(currentScene >= scenes.size()) {
    currentScene = 0;
  }
  game->setScene(scenes[currentScene]);
}
