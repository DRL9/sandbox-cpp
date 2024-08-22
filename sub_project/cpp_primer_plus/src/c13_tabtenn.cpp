#include "./c13_tabtenn.h"
#include <iostream>

using namespace std;
TabTennisPlayer::TabTennisPlayer(const string& fn,
                                 const string& ln,
                                 bool hasTable)
    // 成员初始化列表
    : first_name(fn), last_name(ln), hasTable(hasTable) {
  cout << "constructor TabTennisPlayer" << endl;
}

TabTennisPlayer::~TabTennisPlayer() {
  cout << "~TabTennisPlayer" << endl;
}

RatedPlayer::RatedPlayer(unsigned int r,
                         const string& fn,
                         const string& ln,
                         bool hasTable)
    : TabTennisPlayer(fn, ln, hasTable), rating(r) {
  cout << "constructor RatedPlayer" << endl;
}
RatedPlayer::~RatedPlayer() {
  cout << "~RatedPlayer" << endl;
}