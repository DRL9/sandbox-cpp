#include "c13_brass.h"

int main() {
  Brass b1{"John", 100.1};
  BrassPlus bp1("Mary", 100.2);
  b1.viewAcct();
  bp1.viewAcct();

  b1.withdraw(12);
  bp1.withdraw(12);

  // 向上强制转换
  Brass& b2 = bp1;
  b2.withdraw(10);  // 使用的是 BrassPlus 的版本
  Brass* b3 = &bp1;
  b3->withdraw(40);  // 使用的是 BrassPlus 的版本，
                     // 因为指针指向的数据，实际类型是 BrassPlus
  b3->viewAcct();  // 使用的是 Brass 的版本, 因为 viewAcct 不是虚函数

  Brass b4 = bp1;  // 只复制了 Brass 需要的字段的内存空间
  b4.withdraw(8);
  b4.viewAcct();  // 使用 Brass 版本

  // 向下强制转换
  BrassPlus& bp2 = (BrassPlus&)b2;
  bp2.viewAcct();

  BrassPlus* bp3 = (BrassPlus*)b3;
  bp3->viewAcct();
  string a = "";
  return 0;
}
