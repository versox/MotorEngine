#ifndef SCENE_SWITCHER_H
#define SCENE_SWITCHER_H

#include <vector>
#include "Game.h"
#include "Sprite.h"
#include "Object.h"
#include "Scene.h"

class SceneSwitcher : public Object {
public:
  SceneSwitcher(Sprite* sprite, int x, int y, int w, int h, std::vector<Scene*> scenes, Game* game);
  virtual ~SceneSwitcher();

  void switchScene();
private:
  Game* game;
  std::vector<Scene*> scenes;
  unsigned int currentScene;
};

#endif
