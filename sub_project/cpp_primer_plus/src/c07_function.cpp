#include <array>
#include <iostream>

double sum_arr(double arr[], int size);

int fill_arr(double arr[], int limit);
void show_arr(const double arr[], int size);

int sum_arr2(int arr[][4], int size);

int count_char(const char* str, char ch);

void fill(std::array<double, 5> da);

void estimate(double (*pf)(double[], int));

int main() {
  using namespace std;
  const int Size1 = 10;
  double arr1[Size1] = {1, 2, 3};
  double a1 = 1;
  cout << "sum1: " << sum_arr(arr1, Size1) << endl;
  cout << "sum2: " << sum_arr(&a1, 1) << endl;

  double arr2[10];
  int size2 = fill_arr(arr2, 10);
  show_arr(arr2, size2);

  int a2 = 1;
  const int* p1 = &a2;  // *p1 = 2 非法, 改变指针指向的内存非法
  int* const p2 = &a2;  // p2 = &a1 非法， 给指针变量重新赋值非法
  const int* const p3 = &a2;
  cout << *p1 << *p2 << *p3 << endl;

  cout << "count: " << count_char("hello", 'l') << endl;

  array<double, 5> arr;
  fill(arr);

  estimate(sum_arr);
  return 0;
}

double sum_arr(double arr[], int size) {
  // c++ 将数组当作是指针
  double sum = 0;
  for (int i = 0; i < size; i++) {
    sum += arr[i];
  }
  return sum;
}

int fill_arr(double arr[], int limit) {
  using namespace std;
  int i;
  double temp;
  cout << "输入数字， 负数终止" << endl;
  for (i = 0; i < limit; i++) {
    cin >> temp;
    if (!cin) {
      cin.clear();
      cout << "请输入正确的数字\n";
      continue;
    }
    if (temp < 0) {
      break;
    }
    arr[i] = temp;
  }
  return i;
}
void show_arr(const double arr[], int size) {
  // const 表示不允许修改 arr 的值， 比如 arr[0]=1 非法
  using namespace std;
  cout << "[";
  for (int i = 0; i < size; i++) {
    cout << arr[i];
    if (i < size - 1) {
      cout << ", ";
    }
  }
  cout << "]" << endl;
}

int sum_arr2(int arr[][4], int size) {
  // 二维数组作为入参
  int result = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < 4; j++) {
      result += arr[i][j];
    }
  }
  return result;
}

int count_char(const char* str, char ch) {
  int count = 0;
  while (*str) {
    // 处理string的标准方式， \0 会是 false, 从而终止
    if (*str == ch) {
      count++;
    }
    str++;
  }
  return count;
}

void fill(std::array<double, 5> da) {
  for (int i = 0; i < da.size(); i++) {
    da[i] = i;
  }
}

void estimate(double (*func)(double[], int)) {
  // 函数指针
  using namespace std;
  double list1[2] = {1.1, 2.3};
  double list2[2] = {1, 2};
  int result = func(list1, 2);
  result += (*func)(list2, 2);  // 两种使用指针的方式都可以
  cout << "result: " << result << endl;
}