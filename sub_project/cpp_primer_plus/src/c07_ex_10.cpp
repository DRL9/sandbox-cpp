#include <iostream>

typedef double (*fn[3])(double, double);

double calculate(double x, double y, fn);
double add(double, double);
double times(double, double);

int main() {
  using namespace std;
  fn list = {add, times, add};
  double result = calculate(1, 2, list);
  cout << "result: " << result << endl;
  return 0;
}

double add(double x, double y) {
  return x + y;
}
double times(double x, double y) {
  return x * y;
}

double calculate(double x, double y, fn func) {
  double result = 0;
  for (int i = 0; i < 3; i++) {
    result += func[i](x, y);
  }

  return result;
}