#include <SFML/Graphics.hpp>
#include "game.h"
#include "window.h"
#include "shape.h"
#include "rect.h"
#include "circle_factory.h"

int main() {
  Window & win = Window::getInstance();
  Game game{win.getWidth(), win.getHeight()};

  std::vector<Shape *> shapes = CircleFactory::makeShapes();
  Shape * shape = new Rectangle{0, 60};
  shapes.push_back(shape);

  game.addShapes(shapes);

  game.run();
}
