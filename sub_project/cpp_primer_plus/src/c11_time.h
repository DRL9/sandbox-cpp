#pragma once
#include <iostream>
// 运算符重载实例

class Time {
 private:
  short hours;
  short minutes;
  short seconds;

 public:
  Time(int);
  explicit Time(long);  // 必须显示的类型转换
  Time(short h = 0, short m = 0, short s = 0);
  Time operator+(const Time&) const;
  Time operator-(const Time&) const;
  Time operator*(double) const;
  operator long() const;  // 用于类型转换, 转成 long
  void show() const;
  //   定义友元函数， 使其满足乘法交换律
  friend Time operator*(double, const Time&);
  friend std::ostream& operator<<(std::ostream& cout, const Time&);
};