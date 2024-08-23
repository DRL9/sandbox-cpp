#pragma once
#include <string>

using std::string;

class Brass {
 private:
  string name;
  double balance;

 public:
  Brass(const string& name, double balance);
  virtual ~Brass();
  double Balance() const { return balance; };
  string Name() const { return name; };
  virtual bool withdraw(double balance);
  virtual void viewAcct() const;
};

class BrassPlus : public Brass {
 private:
  double owesBank;

 public:
  BrassPlus(const string& name, double balance);
  ~BrassPlus();
  bool withdraw(double balance);
  void viewAcct() const;
};