#pragma once

#include <memory>
#include <vector>
#include "shape.h"
#include "circle.h"

using container = std::vector<std::unique_ptr<Shape> >;

class CircleFactory {
public:
  static std::unique_ptr<Shape> makeShape(float x, float y) {
    return std::make_unique<Circle>(x, y);
  }

  static container makeShapes(size_t amount = 10) {
    container shapes{};
    for (size_t i{}; i < amount; ++i) {
      shapes.push_back(CircleFactory::makeShape(i*30, 0));
    }
    return shapes;
  }
};
