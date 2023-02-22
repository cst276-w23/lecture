#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>

class Circle : public Shape {
public:
  Circle(float x, float y) : Circle{15.0f} {
    circle.setPosition(x, y);
  }

  Circle(float radius = 5.0f) : circle{radius, 20} {
    circle.setFillColor(sf::Color::Cyan);
  }

  void render(sf::RenderWindow & window) override {
    window.draw(circle);
  }

  void update(float dt) override {
  }

  void setPosition(float x, float y) override {
    circle.setPosition(x, y);
  }

  void move(float dx, float dy) override {
    circle.move(dx, dy);
  }

  ~Circle() override {}

private:
  sf::CircleShape circle{};
};
