#pragma once

#include <memory>
#include "shape.h"
#include "circle.h"

class CircleFactory {
public:
  static std::unique_ptr<Shape> makeShape(float x, float y) {
    return std::make_unique<Circle>(x, y);
  }
};
