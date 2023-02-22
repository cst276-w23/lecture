#pragma once

#include <vector>
#include "shape.h"
#include "circle.h"

class CircleFactory {
public:
  static Shape * makeShape(float x, float y) {
    return new Circle{x, y};
  }

  static std::vector<Shape *> makeShapes(size_t amount = 10) {
    std::vector<Shape *> shapes{};
    for (size_t i{}; i < amount; ++i) {
      shapes.push_back(CircleFactory::makeShape(i*30, 0));
    }
    return shapes;
  }
};
