#pragma once

#include <string>

using std::string;
class Stock {
  // 构造器, 带都默认初始值
  // 默认是私有的
 private:
  string company;
  // 持仓
  long shares;
  double share_val;
  double total_val;
  void set_total() { total_val = share_val * shares; };
  enum egg { Small, Large };
  // 下面 Small, Large 会被认为是
  //   enum egg1 { Small, Large };
  // 应用使用该方式
  enum class egg2 { Small, Large };

 public:
  Stock(const string& company, long n = 0, double price = 0);
  //   默认构造函数
  Stock(){};
  //   析构函数
  ~Stock();
  void acquire(const string& company, long num, double price);
  void buy(long num, double price);
  void sell(long num, double price);
  void show() const;  // const 表明该方法的调用不会变更对象状态
  void update(double price);

  const Stock& greater(const Stock& s) const;
};