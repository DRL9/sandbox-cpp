// 使用类
#include <iostream>
#include "./c11_time.h"

int main() {
  using namespace std;
  Time t1{2, 30, 8};
  t1.show();
  Time t2{3, 42, 57};
  t2.show();
  Time t3 = t1 + t2;
  t3.show();
  Time t4 = t3 - t2;
  t4.show();
  Time t5 = t1 - Time{2, 31, 9};
  t5.show();
  Time t6 = t5 * 2.1;
  t6.show();
  Time t7 = 2.1 * t5;
  cout << t7 << endl;

  Time t8 = 3801;  // 自动类型转换
  cout << t8 << endl;

  Time t9 = (Time)3605l;  // 显式类型转换
  cout << t9 << endl;

  long ts1 = t9;
  cout << ts1 << endl;

  return 0;
}