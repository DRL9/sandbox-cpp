#pragma once
#include <iostream>
// 运算符重载实例

class Time {
 private:
  short hours;
  short minutes;
  short seconds;

 public:
  Time(short h = 0, short m = 0, short s = 0);
  Time operator+(const Time&) const;
  Time operator-(const Time&) const;
  Time operator*(double) const;
  //   定义友元函数， 使其满足乘法交换律
  friend Time operator*(double, const Time&);
  friend std::ostream& operator<<(std::ostream& cout, const Time&);
  void show() const;
};