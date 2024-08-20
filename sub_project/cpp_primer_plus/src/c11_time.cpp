#include "c11_time.h"
#include <iomanip>  // 用于格式化
#include <iostream>

using namespace std;

Time Time::operator+(const Time& t) const {
  Time result{};
  short overflow = 0;
  short sum = seconds + t.seconds;
  result.seconds = sum % 60;
  overflow = sum / 60;

  sum = minutes + overflow + t.minutes;
  overflow = sum / 60;
  result.minutes = sum % 60;

  result.hours = hours + overflow + t.hours;
  return result;
}

Time Time::operator-(const Time& t) const {
  Time result;
  short flag = 0;
  short sum = seconds - t.seconds;
  if (sum < 0) {
    result.seconds = sum + 60;
    flag = -1;
  } else {
    result.seconds = sum;
  }

  sum = minutes - t.minutes + flag;
  if (sum < 0) {
    result.minutes = sum + 60;
    flag = -1;
  } else {
    result.minutes = sum;
    flag = 0;
  }
  result.hours = hours - t.hours + flag;
  return result;
}

Time Time::operator*(double t) const {
  Time result;
  int flag = 1;
  if (hours < 0) {
    flag = -1;
  }
  int total = (flag * hours * 3600 + minutes * 60 + seconds) * t;

  result.hours = total / 3600;
  result.minutes = (total - result.hours * 3600) / 60;
  result.seconds = (total - result.hours * 3600 - result.minutes * 60);
  result.hours *= flag;
  return result;
}

// 友元函数不是成员函数， 不用加 Time::
Time operator*(double m, const Time& t) {
  return t * m;
}

// 友元函数可以访问私有成员
ostream& operator<<(ostream& os, const Time& t) {
  os << setw(2) << setfill('0') << right << t.hours << ":";
  os << setw(2) << setfill('0') << right << t.minutes << ":";
  os << setw(2) << setfill('0') << right << t.seconds;
  return os;
}

Time::Time(short h, short m, short s) {
  hours = h;
  minutes = m;
  seconds = s;
}

Time::Time(int total) {
  hours = total / 3600;
  minutes = (total - hours * 3600) / 60;
  seconds = (total - hours * 3600 - minutes * 60);
}
Time::Time(long total) {
  hours = total / 3600;
  minutes = (total - hours * 3600) / 60;
  seconds = (total - hours * 3600 - minutes * 60);
}

Time::operator long() const {
  return hours * 3600 + minutes * 60 + seconds;
}

void Time::show() const {
  cout << setw(2) << setfill('0') << right << hours << ":";
  cout << setw(2) << setfill('0') << right << minutes << ":";
  cout << setw(2) << setfill('0') << right << seconds << endl;
}
