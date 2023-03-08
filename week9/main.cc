#include <iostream>
#include <memory>

struct Thing {
  int x{42};

  Thing() {
    std::cout << "ctor\n";
  }

  ~Thing() {
    std::cout << "dtor\n";
  }
};

void foo(const std::shared_ptr<Thing> & thing) {

}

int main() {
  std::shared_ptr<Thing> thing = std::make_shared<Thing>();
  foo(thing);
}