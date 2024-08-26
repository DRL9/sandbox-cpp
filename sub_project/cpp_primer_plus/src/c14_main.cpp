#include <iostream>
#include "c14_student.h"

int main() {
  using namespace std;
  Student s1{"Mary", {1.2, 3.4}};
  cout << s1 << endl;
  cout << "average: " << s1.Average() << endl;
  cout << "sum: " << s1.sum() << endl;
  return 0;
}