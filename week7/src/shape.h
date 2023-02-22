#pragma once

#include <SFML/Graphics.hpp>
#include "event_manager.h"

class Shape : public Listener {
public:
  virtual void render(sf::RenderWindow & window) = 0;
  virtual void update(float dt) = 0;
  virtual void setPosition(float x, float y) = 0;
  virtual void move(float dx, float dy) = 0;
  virtual ~Shape() {}
};
