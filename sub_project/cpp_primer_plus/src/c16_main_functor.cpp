#include <iostream>

using namespace std;
class Foo {
 public:
  //  重载()运算符
  double operator()(double);
};

int main() {
  Foo foo;
  cout << foo(10) << endl;
  return 0;
}

double Foo::operator()(double a) {
  return a * 2;
}