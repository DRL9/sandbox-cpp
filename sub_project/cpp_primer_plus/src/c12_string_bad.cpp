#include "./c12_string_bad.h"
#include <cstring>
#include <iostream>

using namespace std;
int StringBad::nums = 0;
StringBad::StringBad() {
  nums++;
  str = new char[4];
  strcpy(str, "c++");
  length = 0;
  cout << nums << ".created: " << str << endl;
}

StringBad::StringBad(const char s[]) {
  length = strlen(s);
  str = new char[length + 1];
  strcpy(str, s);
  nums++;
  cout << nums << ".created: " << str << endl;
}

StringBad::~StringBad() {
  nums--;
  cout << "delete: " << str << " left: " << nums << endl;
  delete[] str;
}

ostream& operator<<(ostream& os, const StringBad& s) {
  os << s.str;
  return os;
}