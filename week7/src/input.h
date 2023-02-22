#pragma once

#include <SFML/Graphics.hpp>
#include "rect.h"

class Command {
public:
  virtual ~Command() {}
  virtual void execute(Rectangle * rect) = 0;
};

class ShakeCommand : public Command {
public:
  ShakeCommand(EventManager * eventManager) : eventManager{eventManager} {}

  virtual void execute(Rectangle * rect) {
    eventManager->notify(EventType::SHAKE);
    rect->shake();
  }

private:
  EventManager * eventManager{};
};

class InputHandler {
public:
  Command * handleInput(const sf::Event & event) {
    if (event.type == sf::Event::KeyPressed) {
      if (event.key.code == sf::Keyboard::Space) {
        return spaceBarCommand;
      }
    }
    return nullptr;
  }

  void setSpaceBarHandler(Command * command) {
    spaceBarCommand = command;
  }

private:
  Command * spaceBarCommand{};
};
