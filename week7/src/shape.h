#pragma once

#include <SFML/Graphics.hpp>

class Shape {
public:
  virtual void render(sf::RenderWindow & window) = 0;
  virtual void update(float dt) = 0;
  virtual void setPosition(float x, float y) = 0;
  virtual ~Shape() {}
};
