#include <cmath>
#include <iostream>

struct Point {
  double x;
  double y;
};
inline double area(double x, double y) {
  // 内联函数
  // 编译内联函数时， 不会生成函数调用指令， 而是将整个函数块嵌入到调用位置
  // 因此内联函数调用更快， 但是每次调用都会生成同样的机器代码， 故占用更多内存
  // 不能递归
  // 一般用于很短的函数块
  return x * y;
}

void swap(int& a, int& b);

double distance(const Point&, const Point&);

const Point& move(Point&, int distance);

// 默认参数
char* left_n(const char*, int n = 1);

void foo(char*);
void foo(const char*);
void foo();

// 函数模板， 泛型
template <typename T>
void swap2(T& a, T& b);

// 显示具体化 函数模版
template <>
void swap2<Point>(Point&, Point&);

int main() {
  using namespace std;
  cout << area(3, 23) << endl;

  int a = 1;
  int b = 2;
  swap(a, b);
  cout << "a=" << a << ", b=" << b << endl;

  auto p1 = Point{1, 2};
  auto p2 = Point{3, 4};
  auto p3 = p1;
  p3.x = 12;
  move(p3, 12);
  auto distance1 = distance(p1, p2);
  cout << "distance=" << distance1 << endl;
  //   如果入参是不能作为左值的表达式， 且对应的引用形参声明为 const,
  //   那么会创建一个临时变量来存储表达式的值
  cout << "distance2=" << distance(Point{3, 4}, Point{7, 7}) << endl;

  cout << "left_n: " << left_n("hello") << ".\n";
  cout << "left_3: " << left_n("hello", 3) << ".\n";
  cout << "left_12: " << left_n("hello", 12) << ".\n";

  char a1[] = "1";
  const char a2[] = "2";
  foo(a1);
  foo(a2);
  foo();

  double a11 = 1.1;
  double b11 = 2.1;
  swap2(a11, b11);
  cout << "a11=" << a11 << ", b11=" << b11 << endl;
  int a12 = 3;
  int b12 = 10;
  swap2(a12, b12);
  cout << "a12=" << a12 << ", b12=" << b12 << endl;

  swap2(p1, p2);
  return 0;
}

void swap(int& a, int& b) {
  // 左值引用，
  auto temp = a;
  a = b;
  b = temp;
}

double distance(const Point& a, const Point& b) {
  // 尽量声明为 const , 防止修改
  return sqrt(pow((a.x - b.x), 2) + pow((b.y - b.y), 2));
}

const Point& move(Point& p, int distance) {
  p.x += distance;
  // 返回引用, 可避免复制大块内存， 最好使用const 防止返回值被修改
  return p;
}

char* left_n(const char* str, int n) {
  if (n < 0) {
    n = 0;
  }
  char* tmp = new char[n + 1];
  int i;
  for (i = 0; i < n && str[i]; i++) {
    tmp[i] = str[i];
  }
  //   加上结尾
  if (tmp[i - 1]) {
    tmp[i] = '\0';
  }

  return tmp;
}

void foo(char* i) {
  using namespace std;
  cout << "void foo(char* i): " << i << endl;
}

void foo(const char* i) {
  using namespace std;
  cout << "void foo(const char* i): " << i << endl;
}

void foo() {
  using namespace std;
  cout << "void foo() " << endl;
}

template <typename T>
void swap2(T& a, T& b) {
  auto tmp = a;
  a = b;
  b = tmp;
}

template <>
void swap2<Point>(Point& p1, Point& p2) {
  auto x = p1.x;
  auto y = p1.y;
  p1.x = p2.x;
  p1.y = p2.y;
  p2.x = x;
  p2.y = y;
}