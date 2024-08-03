#include <array>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>

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

  char name2[32];  // 数组大小一定要够
  //   复制需要用到 copy
  strcpy(name2, name);
  strcat(name2, ", good morning");  // 拼接
  cout << name2 << endl;

  // 字符串
  string str3 = "hello中";
  cout << "字节数: " << str3.size() << endl;

  // 原始字符串, 会不转义字符
  string str4 = R"(Lily say: "how are you"\n)";
  cout << str4 << endl;

  struct book {
    string name;
    int price;
  };
  auto book1 = book{"How to success.", 100};
  cout << "name: " << book1.name << ", price: " << book1.price << endl;

  // 其成员占用同一内存空间， 内存大小为最大的数据类型， 主要用来节省空间
  union unit {
    int int_val;
    long long_val;
  };

  auto unit1 = unit{
      1,
  };
  unit1.long_val = 2;  // int_val 的值会消失
  cout << "unit size: " << sizeof(unit) << ", val:" << unit1.int_val << "|"
       << unit1.long_val << endl;

  // 枚举
  // 默认从0 算起
  enum Color { Red, Green, Blue = 100, Yellow };
  cout << "red: " << Color::Red << ",Yellow: " << Color::Yellow << endl;

  // 指针
  book* ptr1 = &book1;
  cout << "book1'address: " << ptr1 << endl;
  cout << "book'price:" << ptr1->price << ", name:" << (*ptr1).name << endl;

  // 在堆上分配内存
  book* book2 = new book{"Cookbook", 1222};
  cout << "指针大小： " << sizeof(book2) << ", 数据大小：" << sizeof(*book2)
       << endl;
  // new 需要对应 delete 释放内存
  delete book2;

  //  创建动态数组
  long* ptr2 = new long[12];
  ptr2[0] = 1;
  ptr2[1] = 12;
  //   指针指向数字的第一个元素
  cout << "0: " << ptr2[0] << ", 0: " << *ptr2 << endl;
  ptr2++;
  cout << "1: " << ptr2[0] << endl;
  //   需要减回去才能释放
  ptr2--;
  delete[] ptr2;

  // 其它数组
  //   可以动态指定大小
  int size1 = 10;
  //   储存在堆中
  vector<int> v1(size1);
  v1[0] = 12;
  cout << "vector[1]: " << v1[0] << endl;

  // 储存在栈上
  array<int, 10> a2 = {1, 2};
  cout << "array[1]: " << a2[0] << endl;
  //   a2.at(100); // 数组越界会中断程序
  return 0;
}