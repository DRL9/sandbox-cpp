#pragma once

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
  void show() const;
};