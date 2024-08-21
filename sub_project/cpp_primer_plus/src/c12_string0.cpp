#include "./c12_string0.h"
#include <iostream>
namespace STRING {
using namespace std;
int String::nums = 0;

String::String() {
  nums++;
  str = new char[1];
  str[0] = '\0';
  len = 0;
}
String::String(const char* s) {
  len = strlen(s);
  nums++;
  str = new char[len + 1];
  strcpy(str, s);
}

String::String(const String& s) {
  len = s.len;
  nums++;
  str = new char[len + 1];
  strcpy(str, s.str);
}
String::~String() {
  cout << "delete: " << str << endl;
  len = 0;
  nums--;
  delete[] str;
}

bool String::operator>(const String& s) const {
  for (int i = 0; i < len && i < s.len; i++) {
    if (str[i] > s.str[i]) {
      return true;
    } else if (str[i] < s.str[i]) {
      return false;
    }
  }
  return len < s.len;
}

String& String::operator=(const char s[]) {
  delete[] str;
  str = new char[strlen(s) + 1];
  strcpy(str, s);
  return *this;
}

ostream& operator<<(ostream& os, const String& s) {
  os << s.str;
  return os;
}

istream& operator>>(istream& is, String& s) {
  char tmp[100];
  is >> tmp;
  // 注意不是 s.str
  s = tmp;
  return is;
}

}  // namespace STRING