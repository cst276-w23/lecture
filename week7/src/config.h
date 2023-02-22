#pragma once

class Config {
public:
  static Config & getInstance() {
    static Config instance{};
    return instance;
  }

  unsigned int getWidth() const {
    return width;
  }

  unsigned int getHeight() const {
    return height;
  }

  void setWidth(unsigned int newWidth) {
    width = newWidth;
  }

  void setHeight(unsigned int newHeight) {
    height = newHeight;
  }

private:
  Config() {}
  ~Config() {}

  unsigned int width{1000};
  unsigned int height{600};
};
