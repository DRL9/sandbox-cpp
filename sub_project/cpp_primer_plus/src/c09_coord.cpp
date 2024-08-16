#include "./c09_coord.h"
#include <iostream>

// 外部可访问， 其他文件通过 extern int ONE 进行引用声明
int ONE = 1;

// 只能文件内访问
static int TWO = 2;

// 只有文件内可访问
const int THREE = 3;
// 可以在外部文件访问
extern const int THREE_ = 33;

void printPoint() {
  using namespace std;
  cout << "printPoint, DISTANCE: " << DISTANCE << endl;

  // 静态持续变量， 生命周期内一直占用内存
  // 作用域为函数内部
  static auto p1 = Polar{12, 34};
  cout << "polar1, angle: " << p1.angle << ", distance: " << p1.distance
       << endl;
  cout << "two: " << TWO << endl;
  cout << "three: " << THREE << endl;
}
