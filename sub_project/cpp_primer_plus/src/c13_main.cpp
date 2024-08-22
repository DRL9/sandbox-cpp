#include <iostream>
#include "./c13_tabtenn.h"

int main() {
  using namespace std;
  RatedPlayer r1 = RatedPlayer(12, "Mark", "Json", true);
  TabTennisPlayer t1{"Marry", "Jim", false};
  TabTennisPlayer& t2 = r1;
  cout << boolalpha;
  cout << r1.Ratting() << endl;
  cout << t1.HasTable() << endl;
  cout << t2.HasTable() << endl;

  return 0;
}