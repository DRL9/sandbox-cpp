#include <cctype>
#include <fstream>
#include <iostream>

int main(int argc, char* argv[]) {
  using namespace std;

  if (argc < 2) {
    cout << "please input file path.\n";
    return 1;
  }
  char* filepath = argv[1];
  ifstream infile;
  infile.open(filepath);
  if (!infile.is_open()) {
    cout << "打开文件失败" << endl;
    return 1;
  }
  char ch;
  int count = 0;
  while (infile >> ch) {
    // 不会包含换行符等空白字符
    count++;
  }
  cout << "total char: " << count << endl;

  return 0;
}