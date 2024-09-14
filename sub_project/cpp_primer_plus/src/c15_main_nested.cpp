#include <iostream>
#include "./c15_nested_class.h"

using namespace std;
int main() {
  Queue<int> queue;
  cout << boolalpha;
  cout << queue.isEmpty() << endl;
  queue.enqueue(12);
  queue.enqueue(122);
  queue.enqueue(123);
  int a1 = 1;
  queue.enqueue(a1);
  a1 = 2;
  int b1 = 1111;
  queue.dequeue(b1);
  cout << "a1: " << a1 << " b1: " << b1 << endl;

  cout << queue.isEmpty() << endl;
  return 0;
}