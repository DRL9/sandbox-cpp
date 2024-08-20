#include "./c11_vector.h"

int main() {
  using namespace VECTOR;
  using namespace std;
  Vector v1 = Vector(1, 1, Vector::RECT);
  cout << v1 << endl;
  Vector v2{3, 4};
  cout << -v2 << endl;
  cout << v1 + v2 << endl;
  return 0;
}