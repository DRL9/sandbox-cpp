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

  Stack<const char*> s2{12};
  s2.push("hello");
  s2.push("world");
  const char* b2;
  s2.pop(b2);
  cout << s2.is_full() << endl;
  cout << b2 << endl;
  return 0;
}
