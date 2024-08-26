#pragma once

#include <iostream>
#include <string>
#include <valarray>

using std::istream;
using std::ostream;
using std::string;
using std::valarray;

// 私有继承， 可以把基类的公共方法转成自己的私有方法
class Student : private string, private valarray<double> {
 private:
  typedef valarray<double> ArrayDb;
  ostream& arr_out(ostream&) const;

 public:
  Student() : string("null") {};
  //   该构造函数要显式调用
  explicit Student(const string& n) : string(n) {};
  //   对于列表初始化， 执行的顺序是字段的声明的顺序， 而不是列表中的顺序
  //   对于多重继承， 执行顺序是继承中声明的顺序
  explicit Student(int s) : string("null"), ArrayDb(s) {};
  Student(const string& n, int s) : string(n), ArrayDb(s) {};
  Student(const string& n, const ArrayDb& s) : string(n), ArrayDb(s) {};
  ~Student() {};
  //   暴露出基类的方法
  using ArrayDb::sum;
  double Average() const;
  const string& Name() const;
  double operator[](int i) const;
  friend ostream& operator<<(ostream&, const Student& s);
  friend istream& operator>>(istream&, Student& s);
};