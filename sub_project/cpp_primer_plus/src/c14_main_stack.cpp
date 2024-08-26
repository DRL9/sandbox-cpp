#include <iostream>
#include "c14_stack.h"

int main() {
  using namespace std;
  Stack<int> s1{10};
  s1.push(12);
  s1.push(123);
  int b;
  s1.pop(b);
  cout << boolalpha;
  cout << s1.is_full() << endl;
  cout << b << endl;

  return 0;
}
