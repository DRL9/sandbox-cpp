#include <iostream>
#include "./c12_string0.h"

using namespace std;
using namespace STRING;

int main() {
  String name;
  cout << "your name: ";
  cin >> name;
  const int ArSize = 3;
  cout << name << ", enter " << ArSize << " short saying";
  String sayings[ArSize];
  int i;
  for (i = 0; i < ArSize; i++) {
    cout << i << ": ";
    cin >> sayings[i];
  }
  int total = i;

  cout << "your saying: \n";
  for (int i = 0; i < total; i++) {
    cout << i << ": " << sayings[i] << "\n";
  }

  cout << "end" << endl;
  return 0;
}