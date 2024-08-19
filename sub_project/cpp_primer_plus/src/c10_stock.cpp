#include "./c10_stock.h"
#include <iostream>
// 实现成员函数
void Stock::acquire(const string& co, long num, double price) {
  // 可以直接访问类字段
  company = co;
  shares = num;
  share_val = price;
  set_total();
}

void Stock::buy(long num, double price) {
  shares += num;
  share_val = price;
  set_total();
}

void Stock::sell(long num, double price) {
  shares -= num;
  share_val = price;
  set_total();
}

void Stock::show() const {
  using namespace std;
  cout << "company: " << company << "\n"
       << "shares: " << shares << "\n"
       << "prices: " << share_val << "\n"
       << "total: " << total_val << endl;
}
// 实现构造器
Stock::Stock(const string& com, long num, double p) {
  company = com;
  shares = num;
  share_val = p;
  set_total();
}

Stock::~Stock() {
  using namespace std;
  cout << company << " end" << endl;
}

const Stock& Stock::greater(const Stock& s) const {
  if (s.total_val > total_val) {
    return s;
  }
  return *this;
}