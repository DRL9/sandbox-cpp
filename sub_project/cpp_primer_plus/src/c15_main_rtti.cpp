#include <iostream>

using namespace std;

class Grand {
 public:
  virtual void foo() { cout << "grand" << endl; }
};
class Parent : public Grand {
 public:
  virtual void foo() { cout << "parent" << endl; }
};

class Child : public Parent {
 private:
  int field;

 public:
  virtual void foo() { cout << field << "child" << endl; }
  void bar() { cout << field << "child bar\n"; }
};

void change(const int* a) {
  int* ptr;
  ptr = const_cast<int*>(a);
  *ptr = 112;
}

int main() {
  Grand g;
  g.foo();
  Parent p;
  p.foo();
  Grand p1 = p;
  p1.foo();
  Grand* p2 = &p;
  p2->foo();
  Grand& p3 = p;
  p3.foo();

  cout << "---\n";
  Grand* g1 = new Grand;
  Grand* g2 = new Parent;
  Grand* g3 = new Child;
  g1->foo();
  g2->foo();
  g3->foo();

  cout << "---\n";
  Parent* p11 = (Parent*)g2;
  p11->foo();

  // 可以转换成功， 但是子类多出来的字段， 都会是默认值
  Child* c11 = (Child*)g2;
  c11->foo();  // parent
  c11->bar();

  cout << "---\n";
  cout << boolalpha;
  //   如果不能安全转换， 那么会是空指针
  Child* c111 = dynamic_cast<Child*>(g2);
  cout << (c111 == nullptr) << endl;

  try {
    Child& c12 = dynamic_cast<Child&>(p1);
    // 引用转换失败， 会直接抛异常
    c12.bar();
  } catch (const std::exception& e) {
    cout << "fail" << endl;
  }

  cout << (typeid(Child) == typeid(*g3)) << endl;

  cout << "---\n";

  int a1 = 12;
  const int a2 = 102;
  change(&a1);
  change(&a2);
  cout << a1 << endl;
  //   const_cast 用于 const 的结果是未定义的
  cout << a2 << endl;

  return 0;
}