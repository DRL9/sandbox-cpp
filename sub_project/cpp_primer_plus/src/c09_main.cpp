#include <iostream>
#include "./c09_coord.h"
#include "./c09_using_ns.h"

// 引用声明, 定义在其他 cpp 文件中， 需要将对应的cpp编译链接进来
extern int ONE;
extern const int THREE_;

struct Book {
  char title[100];
  mutable double price;
};

int main() {
  using namespace std;

  //   因为 include 了头文件， 所以可以访问里面的静态变量
  DISTANCE = 1112;
  cout << "static distance is: " << DISTANCE << endl;
  printPoint();
  printOne();
  const int ONE = 11;
  //   使用 :: 引用到外部作用域的变量
  cout << "outer: " << ::ONE << " inner:" << ONE << endl;

  const auto book = Book{"Can I use?", 12};
  //  因为声明 const , 所以 book 的成员也是不可变的
  //   strcpy(book.title, "sd");
  //   因为 price 是 mutable , 所以该字段又是可以修改
  book.price = 12;
  cout << "three_: " << THREE_ << endl;

  // new 动态分配
  Book* b1 = new Book{"title", 12.3};
  delete b1;

  using jack::hello;
  using jack::pos;
  jack::foo::book_size = 12;
  pos = 2;
  hello();

  cout << "end" << endl;

  return 0;
}

void printOne() {
  using namespace std;
  cout << ONE << endl;
}

void once() {}