#include <cctype>
#include <fstream>
#include <iostream>
#include <string>

int main() {
  using namespace std;
  //   字符判断， 真为 1
  cout << isalpha('a') << endl;
  cout << isdigit('1') << endl;
  cout << isupper('A') << endl;

  // 文件 I/O
  ofstream outfile;
  outfile.open("./build/out");
  //   跟 cout 一样的用法
  outfile << "hello" << endl;
  outfile << hex;
  outfile << '0x' << 249043 << endl;

  ifstream infile;
  infile.open("src/c02_basic.cpp");
  if (!infile.is_open()) {
    cout << "file not exist" << endl;
    return 1;
  }
  //   跟 cin 一样使用
  string content;
  while (infile.good()) {
    infile >> content;  // 遇到空白符就终止
    for (int i = 0; i < content.size(); i++) {
      char ch = content[i];
      if (isalpha(ch)) {
        content[i] = toupper(ch);
      }
    }
    outfile << content;
  }

  outfile << endl;

  infile.close();
  outfile.close();
  return 0;
}