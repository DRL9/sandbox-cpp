#include <iostream>
#include "./c12_string_bad.h"

using namespace std;
void call_me1(StringBad& s) {
  cout << "call1: " << s << endl;
}

void call_me2(StringBad s) {
  // 这个按值传递， 也就是会生成一个副本， 那么有两个指针指向内部的 str
  // 当函数调用结束时， 调用 s 的析构函数， 那么调用了一次 delete[] str
  // 然后main结束时， 又会调用一次 delete[] str
  cout << "call2: " << s << endl;
}

int main() {
  StringBad s1{"hello"};
  // 这个也会调用 delete[] str 两次， 因为赋值语句默认时复制值
  // StringBad s11 = s1;
  call_me1(s1);

  StringBad s2{"world"};
  call_me2(s2);
  cout << "s2: " << s2 << endl;  // s2.str 已经被释放了

  auto s3 = s1;  // 会调用复制构造函数
  s3 = s2;       // 调用复制语句

  cout << "end" << endl;

  return 0;
}
