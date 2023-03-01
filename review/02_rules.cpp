#include <iostream>
#include <cstring>

struct Point {
  int x;
  int y;

  Point() = default;

  Point(int hypotenuse) {
    // logic here
  }

  Point(int x, int y) : x{x}, y{y} {}

  void print() {
    std::cout << x << ' ' << y << '\n';
  }
};

Point p{};
Point p{2, 3};

// Rule of Three: https://en.cppreference.com/w/cpp/language/rule_of_three
struct String {
  char * str;
  size_t len;

  String() = default;

  String(const char * str) {
    len = std::strlen(str);
    this->str = new char[len + 1]{};
    std::strcpy(this->str, str);
  }

  ~String() {
    delete[] str;
    str = nullptr;
    len = 0;
  }

  String(const String & other) : String{other.str} {}

  String & operator=(const String & other) {
    if (this == &other) {
      return *this;
    }

    // dtor
    delete[] str;

    // ctor
    len = other.len;
    str = new char[len + 1]{};
    std::strcpy(str, other.str);

    return *this;
  }
};

int main() {
  String name1{"bob"};

  String name2{};
  name2 = name1; // syntactic sugar
  name2.operator=(name1);

  std::cout << name1.str << '\n';
}