#pragma once

#include <SFML/Graphics.hpp>

class Rectangle : public Shape {
public:
  Rectangle(float x, float y) : Rectangle{15.0f} {
    rect.setPosition(x, y);
  }

  Rectangle(float width = 10.0f) : rect{sf::Vector2f{width, width}} {
    rect.setFillColor(sf::Color::Red);
  }

  void render(sf::RenderWindow & window) override {
    window.draw(rect);
  }

  void update(float dt) override {
    rect.move(velocity.x*dt, velocity.y*dt);
  }

  void setPosition(float x, float y) override {
    rect.setPosition(x, y);
  }

  ~Rectangle() override {}

private:
  sf::RectangleShape rect{};
  sf::Vector2f velocity{};
};
