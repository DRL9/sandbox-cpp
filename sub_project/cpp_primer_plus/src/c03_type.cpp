#include <iostream>

int main() {
  using namespace std;

  char a1 = 'a';
  char a2 = 97;  // 与上者等效
  cout << "a1==a2? " << (a1 == a2) << endl;

  int num = 12;
  cout << "12 的十六进制是 ";
  cout << hex;  // hex 可以让数字输出以 16进制 显示
  cout << num << endl;

  cout << "输出 unicode: \u00ff" << endl;

  const double PI = 3.14;  // 常量， 可用来替代 #define
  cout << "PI = " << PI << endl;

  unsigned int x1{312};  // 使用 {} 初始化时，可以检查大数赋值给小的类型，
                         // 比如说， x1 为char时，会编译错误
  long double x2 = 12;
  auto x0 =
      x1 + x2;  // auto 可以自动推断类型, 不同类型的做运算， 会转成相同类型
  cout << "x0=" << x0 << endl;

  return 0;
}