#include <iostream>
#include <string>

class Animal {
protected:
  std::string name{"animal"};

public:
  Animal() = default;
  Animal(const std::string & name) : name{name} {}
  virtual void speak() = 0;
};

class Dog : public Animal {
public:
  Dog() : Animal{"Dog"} {}
  Dog(const std::string & name) : Animal{name} {}

  void speak() {
    std::cout << name << " is saying woof!\n";
  }
};

class Pug : public Dog {
public:
  Pug() : Dog{"Pug"} {}

  void speak() {
    std::cout << name << " is saying nothing!\n";
  }
};

int main() {
  Dog animal{};
  Pug dog{};
  animal.speak();

  Animal & myDog = dog;
  // Animal * myDog = &dog;
  myDog.speak();
}