#pragma once

#include <SFML/Graphics.hpp>

class Graphics {
public:
  sf::RenderWindow window;

  Graphics() : window{sf::VideoMode{800, 600}, "Game"} {}

  void render(const sf::Drawable & drawable) {
    window.draw(drawable);
  }
};