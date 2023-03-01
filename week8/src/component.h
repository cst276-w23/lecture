#pragma once

class World;
class Entity;
class Graphics;

class InputComponent {
public:
  virtual ~InputComponent() {}
  virtual void update(Entity * entity) = 0;
};

class PhysicsComponent {
public:
  virtual ~PhysicsComponent() {}
  virtual void update(Entity * entity, World * world) = 0;
};

class GraphicsComponent {
public:
  virtual ~GraphicsComponent() {}
  virtual void update(Entity * entity, Graphics * graphics) = 0;
};
