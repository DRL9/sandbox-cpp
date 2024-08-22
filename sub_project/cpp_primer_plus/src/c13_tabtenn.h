#pragma once
#include <string>

using std::string;
class TabTennisPlayer {
 private:
  string first_name;
  string last_name;
  bool hasTable;

 public:
  TabTennisPlayer(const string& fn, const string& ln, bool hasTable = false);
  ~TabTennisPlayer();
  bool HasTable() const { return hasTable; };
};

// 继承加上 public, 可以使得 RatedPlayer 赋值给 TabTennisPlayer
class RatedPlayer : public TabTennisPlayer {
 private:
  unsigned int rating;

 public:
  RatedPlayer(unsigned int r,
              const string& fn,
              const string& ln,
              bool hasTable = false);
  RatedPlayer(unsigned int r, const TabTennisPlayer& t);
  ~RatedPlayer();
  unsigned int Ratting() const { return rating; };
};