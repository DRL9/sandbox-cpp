#include <iostream>
#include "./c10_stack.h"

int main() {
  using namespace std;
  Stack stack;
  stack.push(1);
  cout << boolalpha;
  cout << stack.is_empty() << endl;
  Item item;
  stack.pop(item);
  cout << stack.is_empty() << endl;
  return 0;
}