#include <iostream>
#include <vector>

using namespace std;
void print_item(int i) {
  cout << i << "-";
}

bool compare(int a, int b) {
  return a > b;
}

int main() {
  vector<int> v1;
  cout << "v1.size: " << v1.size() << endl;
  cout << "v1.capacity: " << v1.capacity() << endl;
  for (int i = 0; i < 30; i++) {
    v1.push_back(i);
  }
  cout << "v1.size: " << v1.size() << endl;
  cout << "v1.capacity: " << v1.capacity() << endl;
  v1.pop_back();
  cout << "v1.size: " << v1.size() << endl;
  cout << "v1.capacity: " << v1.capacity() << endl;
  v1.shrink_to_fit();
  cout << "v1.capacity: " << v1.capacity() << endl;

  // 索引
  cout << "v1[0]: " << v1[0] << endl;
  auto it = v1.begin();  // 指向第一个元素的迭代器
  cout << *it++ << endl;
  cout << *it << endl;

  for (int item : v1) {
    // 遍历
    cout << item << "-";
  }
  cout << endl;

  // 删除指定区间的值
  v1.erase(v1.begin() + 10, v1.begin() + 13);
  for (int item : v1) {
    cout << item << "-";
  }
  cout << endl;

  vector<int> v2{100, 101};
  //   交换内容
  v1.swap(v2);
  cout << "v1: ";
  for (int item : v1) {
    cout << item << "-";
  }
  cout << endl;
  cout << v1.capacity() << endl;
  cout << "v2: ";
  for (int item : v2) {
    cout << item << "-";
  }
  cout << endl;
  cout << v2.capacity() << endl;

  // 随机打散
  random_shuffle(v2.begin(), v2.end());
  for_each(v2.begin(), v2.end(), print_item);
  cout << endl;
  //   排序
  sort(v2.begin(), v2.end());
  for_each(v2.begin(), v2.end(), print_item);
  cout << endl;
  //   逆序
  sort(v2.begin(), v2.end(), compare);
  for_each(v2.begin(), v2.end(), print_item);
  cout << endl;
  return 0;
}