#include <SFML/Graphics.hpp>
#include "game.h"
#include "config.h"
#include "shape.h"
#include "rect.h"
#include "circle_factory.h"

int main() {
  Config & config = Config::getInstance();
  Game game{config.getWidth(), config.getHeight()};

  std::vector<Shape *> shapes = CircleFactory::makeShapes();
  Rectangle * rect = new Rectangle{100, 100};
  shapes.push_back(rect);

  game.addShapes(shapes);

  game.setActor(rect);

  game.run();
}
