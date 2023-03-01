#include <iostream>

void foo() {
  std::cout << "bar\n";
}

void bar(size_t times, void (*fn)()) {
  for (size_t i{}; i < times; ++i) {
    fn();
  }
}

template <typename F>
void bar2(size_t times, F fn) {
  for (size_t i{}; i < times; ++i) {
    fn();
  }
}

int main() {
  void (*p)() = foo;
  bar(5, p);
  bar(3, foo);

  int x{42};

  bar2(5, [=]() {
    std::cout << "hi from lambda, " << x << '\n';
  });
}