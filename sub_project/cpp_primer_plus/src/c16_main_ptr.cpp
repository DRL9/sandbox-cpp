#include <iostream>
#include <memory>

using namespace std;
class Foo {
 private:
  int* data;

 public:
  Foo() {
    cout << "ctor" << endl;
    data = new int;
    *data = 12;
  }
  Foo(const Foo& f) {
    cout << "copy ctor" << endl;
    data = new int;
    *data = *f.data;
  }
  ~Foo() {
    cout << "~" << endl;
    delete data;
  }
  void foo() { cout << *data << "\n"; }
};

int main() {
  {
    // 会自动调用析构函数
    unique_ptr<Foo> ptr1{new Foo};
    ptr1->foo();  // 被当作指针
    // auto ptr11 = ptr1; // 该指针不能赋值
    auto ptr2 = *ptr1;
    ptr2.foo();
  }
  cout << "---\n";
  {
    // 引用计数
    shared_ptr<Foo> ptr1{new Foo};
    ptr1->foo();
    cout << "count: " << ptr1.use_count() << endl;
    auto ptr2 = ptr1;
    cout << "count: " << ptr1.use_count() << endl;
    ptr2->foo();
  }

  cout << "end" << endl;

  return 0;
}