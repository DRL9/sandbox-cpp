#include <iostream>
#include "./c12_string0.h"

using namespace std;
using namespace STRING;

int main() {
  String name;
  cout << "your name: ";
  cin >> name;
  const int ArSize = 3;
  cout << name << ", enter " << ArSize << " short saying";
  String sayings[ArSize];
  int i;
  for (i = 0; i < ArSize; i++) {
    cout << i << ": ";
    cin >> sayings[i];
  }
  int total = i;

  cout << "your saying: \n";
  for (int i = 0; i < total; i++) {
    cout << i << ": " << sayings[i] << "\n";
  }

  String* s1 = new String("hello world");
  cout << "s1: " << *s1 << " \n[1]:" << (*s1)[1] << endl;
  delete s1;  // 调用析构函数

  char* buffer = new char[100];
  String* p1 = new (buffer) String("good job");
  cout << "p1: " << *p1 << endl;
  delete[] buffer;  // 不会调用 p1 指向的 String 析构函数
  // 报错因为指向的内存 buffer 被释放了
  // delete p1;
  cout << "end" << endl;
  return 0;
}