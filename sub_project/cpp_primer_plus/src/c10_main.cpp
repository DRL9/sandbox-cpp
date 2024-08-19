// 对象和类
#include <iostream>
#include "./c10_stock.h"
int main() {
  using namespace std;
  // 调用默认构造函数
  Stock micro;
  micro.acquire("microsoft", 23, 4.5);
  micro.show();

  Stock goog = Stock("goog", 1, 1);
  goog.buy(10, 23);
  goog.show();

  const Stock meta{"meta", 10, 10.3};
  //   声明为 const 的， 不能调用非 const 方法
  //   meta.buy(1, 2);
  meta.show();

  // 调用只有一个参数，2个默认值的那个构造器， 因为只有一个参数， 可以省略 {}
  Stock tcl = (const string) "tcl";
  tcl.show();

  Stock* nvida = new Stock("nvida", 23, 455);
  nvida->show();
  delete nvida;

  tcl.greater(meta).show();
  cout << "---" << endl;
  Stock stock[4] = {Stock("s1", 3, 3.1), Stock("s2", 12, 3), Stock("s3", 13, 4),
                    Stock("s4", 3, 4)};

  for (int i = 0; i < 4; i++) {
    const Stock* top = &stock[i];
    for (int j = i; j < 4; j++) {
      //  & 运算符的优先级没有 -> 高
      top = &top->greater(stock[j]);
    }
    top->show();
  }

  cout << "----" << endl;
  return 0;
}
