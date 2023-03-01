#pragma once

#include <vector>
#include "graphics.h"
#include "entity.h"
#include "player.h"

class World {
private:
  Graphics graphics;
  std::vector<Entity *> entities;

public:
  World() {
    Entity * player = createPlayer();
    entities.push_back(player);
  }

  void run() {
    while (graphics.window.isOpen()) {
      processGlobalEvents();

      graphics.window.clear();
      for (auto & entity : entities) {
        // the Entity update now handles (delegates) rendering, input, updating, etc
        entity->update(this, &graphics);
      }
      graphics.window.display();
    }
  }

private:
  void processGlobalEvents() {
    sf::Event event;
    while (graphics.window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        graphics.window.close();
        break;
      }
    }
  }
};
