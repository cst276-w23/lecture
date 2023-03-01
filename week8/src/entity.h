#pragma once

class World;
class Graphics;

#include "component.h"

class Entity {
public:
  float velocityX{};
  float velocityY{};
  float x{};
  float y{};

  Entity(InputComponent * inputComponent,
         PhysicsComponent * physicsComponent,
         GraphicsComponent * graphicsComponent)
  : inputComponent{inputComponent},
    physicsComponent{physicsComponent},
    graphicsComponent{graphicsComponent}
  {}

  void update(World * world, Graphics * graphics) {
    inputComponent->update(this);
    physicsComponent->update(this, world);
    graphicsComponent->update(this, graphics);
  }

private:
  InputComponent * inputComponent;
  PhysicsComponent * physicsComponent;
  GraphicsComponent * graphicsComponent;
};
