#include <exception>
#include <iostream>
#include "./c15_error.h"

using namespace std;

int main() {
  try {
    throw greater_error("too large");
  } catch (const greater_error& e) {
    std::cerr << e.what() << '\n';
  } catch (const exception& e) {
    std::cerr << e.what() << '\n';
  }

  return 0;
}