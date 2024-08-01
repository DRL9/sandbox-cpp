#include <cstring>
#include <iostream>

int main() {
  using namespace std;
  // 字符数组
  char str1[] = {'h', 'i', '\0', '1'};  // 以\0作为字符串结尾
  cout << str1 << endl;
  char str2[20] = "hello world";  // "" 会自动加上 \0
  cout << str2 << " , strlen: " << strlen(str2)
       << ", 字符串结尾==\0: " << (str2[strlen(str2)] == '\0') << endl;

  char name[12];
  cout << "Your name: ";
  cin.getline(name, 10);  // 最多读 10 个字节
  cout << name << endl;

  return 0;
}