#include <SFML/Graphics.hpp>
#include "rand.h"
#include "window.h"
#include "shape.h"
#include "circle_factory.h"

void render(sf::RenderWindow & window, const std::vector<Shape *> & shapes) {
  // always clear!
  window.clear();

  // drawing happens here (off-screen)
  for (auto & shape : shapes) {
    shape->render(window);
  }

  // swap the display buffer (double-buffering)
  window.display();
}

void processEvents(sf::RenderWindow & window, std::vector<Shape *> & shapes) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    }
  }
}

void update(sf::Time dt, const std::vector<Shape *> & shapes) {
  float t = dt.asSeconds();
  for (auto & shape : shapes) {
    shape->update(t);
  }
}

int main() {
  Window & win = Window::getInstance();

  sf::RenderWindow window{sf::VideoMode{win.getWidth(), win.getHeight()}, "In-Class"};

  std::vector<Shape *> shapes = CircleFactory::makeShapes();
  // add another shape if we want
  Shape * shape = CircleFactory::makeShape(0, 60);
  shapes.push_back(shape);

  // for info on game loops:
  //   https://subscription.packtpub.com/book/game+development/9781849696845/1/ch01lvl1sec11/game-loops-and-frames
  sf::Clock clock;

  sf::Time t{sf::Time::Zero}; // time
  sf::Time dt{sf::seconds(1.0f / 60.0f)}; // delta time (fixed to 60fps)

  while (window.isOpen()) {
    processEvents(window, shapes);
    t += clock.restart();

    while (t > dt) {
      t -= dt;
      processEvents(window, shapes);
      update(dt, shapes);
    }

    render(window, shapes);
  }

  for (Shape * shape : shapes) {
    delete shape;
  }
}
