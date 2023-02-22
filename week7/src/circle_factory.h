#pragma once

#include <vector>
#include "shape.h"
#include "circle.h"
#include "scareable.h"
#include "rand.h"

class CircleFactory {
public:
  static Shape * makeShape(float x, float y) {
    auto r = rand(0, 10);
    Shape * shape = new Circle{x, y};
    return r % 2 == 0 ? shape : new Scareable{shape};
  }

  static std::vector<Shape *> makeShapes(size_t amount = 10) {
    std::vector<Shape *> shapes{};
    for (size_t i{}; i < amount; ++i) {
      shapes.push_back(CircleFactory::makeShape(i*30, 100));
    }
    return shapes;
  }
};
