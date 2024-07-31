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

  cout << endl;  // endl 除了换行外， 还会刷新输出
  return 0;
}