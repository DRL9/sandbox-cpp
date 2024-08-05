#include <array>
#include <iostream>

using namespace std;
void text_in();
void text_in2();
void text_eof();

int main() {
  array<array<int, 10>, 10> list;
  list[0][1] = 1;
  list[1] = {1, 2};
  list[9] = {2, 3, 5};
  for (int i = 0; i < list.size(); i++) {
    for (int j = 0; j < list[i].size(); j++) {
      cout << list[i][j] << ' ';
    }
    cout << endl;
  }
  cout << "----\n";

  // 不能用 == 比较  C风格的字符串
  char str1[] = "hello";
  char str2[] = "hello";
  cout << boolalpha;
  cout << (str1 == str2) << endl;
  // strcmp, 负值： 左边小于右边（字母顺序）， 0: 相等， 1: 大于
  cout << (strcmp(str1, str2) == 0) << endl;

  // string 可以直接比较
  string str3 = "hello";
  string str4 = "hello";
  cout << (str3 == str4) << endl;
  cout << dec;

  // 暂停一定时间
  clock_t start = clock();
  while (start + 1 * CLOCKS_PER_SEC > clock())
    ;

  // 类型别名
  typedef int id;
  typedef id* id_point;
  id id1 = 1;
  id_point ptr_id = &id1;
  // cout 还是把他当作原来的类型对待
  cout << id1 << "  " << *ptr_id << endl;

  // 基于范围的循环
  int arr2[] = {12, 3, 4};
  // 修改数据
  for (int& item : arr2) {
    item += 1;
  }
  for (int item : arr2) {
    cout << item << "-";
  }
  cout << endl;

  // text_in();
  // text_in2();
  text_eof();
  return 0;
}

void text_in() {
  char c;
  cout << "input text, type '#' to stop";
  cin >> c;  // 按下回车后， 才会停止输入
  int count = 0;
  cout << "start: ";
  while (c != '#') {
    cout << c;  // 空格会被忽略
    cin >> c;
    count++;
  }
  cout << endl;
  cout << "total char: " << count << endl;
}

void text_in2() {
  char c;
  cout << "input text: ";
  cin.get(c);
  while (c != '#') {
    cout << c;
    cin.get(c);  // 空格不会被忽略
  }
  cout << endl;
}

void text_eof() {
  // 模拟文件结尾
  char ch;
  int count = 0;
  cin.get(ch);
  while (!cin.eof()) {
    // istream 有个函数， 可以将 cin 转成 bool, 当读取失败时， 会是 false
    // while (cin) { // 也可以用这个
    cout << ch;
    cin.get(ch);
    count++;
  }
  cout << endl;
  cout << "total char: " << count << endl;
}

void text_eof2() {
  char ch;
  int count = 0;
  while (cin.get(ch)) {
    cout << ch;
    count++;
  }
  cout << endl;
}