#pragma once

#include <SFML/Graphics.hpp>

class Command {
public:
  virtual ~Command() {}
  virtual void execute(Rectangle * rect) = 0;
};

class ShakeCommand : public Command {
public:
  virtual void execute(Rectangle * rect) {
    rect->shake();
  }
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
