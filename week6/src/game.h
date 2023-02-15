#include <SFML/Graphics.hpp>
#include <vector>
#include "shape.h"

class Game {
public:
  Game(unsigned int width = 800, unsigned int height = 600) : window{sf::VideoMode{width, height}, "Game"} {}

  ~Game() {
    for (auto shape : shapes) {
      delete shape;
    }
  }

  void run() {
    sf::Clock clock;
    sf::Time t{sf::Time::Zero};
    sf::Time dt{sf::seconds(1.0f / 60.0f)};

    while (window.isOpen()) {
      processEvents();
      t += clock.restart();

      while (t > dt) {
        t -= dt;
        processEvents();
        update(dt);
      }

      render();
    }
  }

  void addShape(Shape * shape) {
    shapes.push_back(shape);
  }

  void addShapes(const std::vector<Shape *> & shapes) {
    for (auto shape : shapes) {
      addShape(shape);
    }
  }

private:
  void render() {
    window.clear();

    for (auto & shape : shapes) {
      shape->render(window);
    }

    window.display();
  }

  void processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }
  }

  void update(sf::Time dt) {
    float t = dt.asSeconds();
    for (auto & shape : shapes) {
      shape->update(t);
    }
  }

  sf::RenderWindow window{};
  std::vector<Shape *> shapes{};
};
