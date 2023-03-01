#pragma once

#include <SFML/Graphics.hpp>
#include "entity.h"
#include "graphics.h"
#include "component.h"

class PlayerInputComponent : public InputComponent {
public:
  void update(Entity * entity) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
      entity->velocityX = -10;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
      entity->velocityX = 10;
    } else {
      entity->velocityX = 0;
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
      entity->velocityY = -10;
    } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
      entity->velocityY = 10;
    } else {
      entity->velocityY = 0;
    }
  }
};

class PlayerPhysicsComponent : public PhysicsComponent {
public:
  void update(Entity * entity, World * world) override {
    const float t = 0.01;
    entity->x += entity->velocityX*t;
    entity->y += entity->velocityY*t;
  }
};

class PlayerGraphicsComponent : public GraphicsComponent {
public:
  sf::CircleShape shape{15};

  void update(Entity * entity, Graphics * graphics) override {
    shape.setPosition(entity->x, entity->y);
    graphics->render(shape);
  }
};

Entity * createPlayer() {
  return new Entity(
    new PlayerInputComponent{},
    new PlayerPhysicsComponent{},
    new PlayerGraphicsComponent{}
  );
}
