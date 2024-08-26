#include "./c14_student.h"
#include <iostream>

using namespace std;

// this 即是 string 又是 valarray<double>
const string& Student::Name() const {
  return (const string&)*this;
}

double Student::Average() const {
  // 因为 string 和 valarray<double> 都有 size, 所以使用作用域限定符
  if (ArrayDb::size() == 0) {
    return 0;
  }
  return sum() / ArrayDb::size();
}

ostream& Student::arr_out(ostream& os) const {
  for (int i = 0; i < ArrayDb::size(); i++) {
    os << ArrayDb::operator[](i);
    if (i < ArrayDb::size() - 1) {
      os << ", ";
    }
  }
  return os;
}

double Student::operator[](int i) const {
  return ArrayDb::operator[](i);
}

istream& operator>>(istream& is, Student& stu) {
  is >> (string&)stu;
  return is;
}

ostream& operator<<(ostream& os, const Student& stu) {
  // 强制转换成基类， 防止递归调用该重载运算符
  os << "name: " << (const string&)stu << "\n";
  os << "scores: ";
  stu.arr_out(os);
  return os;
}