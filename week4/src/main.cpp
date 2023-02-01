#include <SFML/Graphics.hpp>
#include "rand.h"
#include "window.h"
#include "shape.h"
#include "circle_factory.h"

void render(sf::RenderWindow & window, const container & shapes) {
  // always clear!
  window.clear();

  // drawing happens here (off-screen)
  for (auto & shape : shapes) {
    shape->render(window);
  }

  // swap the display buffer (double-buffering)
  window.display();
}

void processEvents(sf::RenderWindow & window, const container & shapes) {
  sf::Event event;
  while (window.pollEvent(event)) {
    if (event.type == sf::Event::Closed) {
      window.close();
    } else if (event.type == sf::Event::Resized) {
      Window & win = Window::getInstance();
      win.setWidth(event.size.width);
      win.setHeight(event.size.height);
    }
  }
}

void update(sf::Time dt, const container & shapes) {
  float t = dt.asSeconds();
  for (auto & shape : shapes) {
    shape->update(t);
  }
}

int main() {
  Window & win = Window::getInstance();

  sf::RenderWindow window{sf::VideoMode{win.getWidth(), win.getHeight()}, "In-Class"};

  container shapes = CircleFactory::makeShapes();
  // add another shape if we want
  shapes.push_back(CircleFactory::makeShape(0, 30));

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
}
