#include <iostream>

enum Option {
  option1 = 1,
  option2,
  option3,
  quit
};

int main() {
  int choice{};
  while (choice != Option::quit) {
    std::cout
      << "1. Option one\n"
      << "2. Option two\n"
      << "3. Option three\n"
      << "4. Quit\n"
      << "\nEnter a choice: ";
    std::cin >> choice;
  }
}