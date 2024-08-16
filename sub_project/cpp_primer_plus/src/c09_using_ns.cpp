#include "./c09_using_ns.h"
#include <iostream>

namespace jack {
// 重新导出其他名称空间的成员
using std::cout;

int pos = 3;

void hello() {
  using namespace std;
  cout << "jack::hello(), pos: " << pos << endl;
  cout << "book_size: " << foo::book_size << endl;
}
}  // namespace jack
