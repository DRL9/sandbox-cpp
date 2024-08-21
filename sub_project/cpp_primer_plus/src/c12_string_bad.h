#pragma once
#include <iostream>

class StringBad {
 private:
  char* str;
  static int nums;
  int length;

 public:
  StringBad();
  StringBad(const char[]);
  ~StringBad();
  friend std::ostream& operator<<(std::ostream&, const StringBad&);
};