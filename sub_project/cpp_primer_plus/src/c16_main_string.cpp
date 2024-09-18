#include <iostream>
#include <string>

int main() {
  using std::boolalpha;
  using std::cout;
  using std::endl;
  using std::string;
  string s1{"hello"};
  cout << s1 << endl;
  auto s2 = string(4, '$');  // 重复字符
  cout << s2 << endl;

  char c1 = s1[1];  // 索引
  cout << c1 << endl;

  auto s3 = s1 + s2;
  cout << s3 << endl;
  s3 += "world";
  cout << s3 << endl;
  auto s4 = string(s3, 1, 6);  // 构建子串
  cout << s4 << endl;

  auto s5 = string("hello world hello", 3);  // 取前面3个字符
  cout << s5 << endl;

  cout << boolalpha;
  string s6 = "O Romeo, Romeo! Wherefore art thou Romeo?";
  cout << "第一个索引" << s6.find("Ro") << endl;
  cout << s6.find_first_not_of("O") << endl;
  cout << s6.find_last_of("Romeo") << endl;
  cout << "size: " << s6.size() << endl;
  cout << "capacity: " << s6.capacity() << endl;
  auto ptr_6 = &s6;
  s6 += "hello world";
  cout << "capacity: " << s6.capacity() << endl;
  cout << (ptr_6 == &s6) << endl;

  return 0;
}