#pragma once

#include "shape.h"

#include <iostream>

class Scareable : public Shape {
public:
  Scareable(Shape * s) : shape{s} {}

  void onNotify(EventType eventType) override {
    if (eventType == EventType::SHAKE) {
      shape->move(0, -20);
    }
  }

  void render(sf::RenderWindow & window) override {
    shape->render(window);
  }

  void update(float dt) override {
    shape->update(dt);
  }

  void setPosition(float x, float y) override {
    shape->setPosition(x, y);
  }

  void move(float dx, float dy) override {
    shape->move(dx, dy);
  }

protected:
  Shape * shape{};
};
