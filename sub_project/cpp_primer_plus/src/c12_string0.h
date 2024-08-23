#pragma once
#include <iostream>
namespace STRING {

class String {
 private:
  char* str;
  int len;
  static int nums;

 public:
  String();
  String(const char*);
  String(const String&);  // 复制构造函数
  ~String();
  int length() { return len; };
  static int total_count() { return nums; };
  bool operator>(const String&) const;
  bool operator>=(const String&) const;
  bool operator<(const String&) const;
  bool operator<=(const String&) const;
  bool operator==(const String&) const;
  bool operator!=(const String&) const;
  String& operator=(const String&);
  String& operator=(const char[]);
  // 重载索引运算符
  char operator[](const int);
  friend std::ostream& operator<<(std::ostream& os, const String&);
  friend std::istream& operator>>(std::istream& is, String&);
};
}  // namespace STRING