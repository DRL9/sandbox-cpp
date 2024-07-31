#include <cmath>
#include <iostream>

// c++ 头文件有不用 .h 的替代, 比如说 cmath 替代 math.h

int main() {
  using namespace std;

  cout << "input a number: ";
  double num;
  cin >> num;
  double result = sqrt(num);
  cout << "sqrt(" << num << ") is " << result;
  cout << endl;
  return 0;
}