#pragma once

#include <SFML/Graphics.hpp>
#include "rand.h"
#include "shape.h"

class Rectangle : public Shape {
public:
  Rectangle(float x, float y) : Rectangle{30.0f} {
    rect.setPosition(x, y);
  }

  Rectangle(float width = 10.0f) : rect{sf::Vector2f{width, width}} {
    rect.setFillColor(sf::Color::Red);
  }

  void render(sf::RenderWindow & window) override {
    window.draw(rect);
  }

  void update(float dt) override {
    auto dx = velocity.x*dt;
    auto dy = velocity.y*dt;

    if (timer > 0) {
      constexpr int speed{50};
      dx += rand(-speed, speed)*dt;
      dy += rand(-speed, speed)*dt;
      --timer;
    }

    rect.move(dx, dy);
  }

  void setPosition(float x, float y) override {
    rect.setPosition(x, y);
  }

  void shake() {
    if (timer == 0) {
      timer = 50;
    }
  }

  ~Rectangle() override {}

private:
  sf::RectangleShape rect{};
  sf::Vector2f velocity{};
  int timer{};
};
