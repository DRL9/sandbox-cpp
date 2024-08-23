#include "c13_brass.h"
#include <iostream>

using namespace std;

Brass::Brass(const string& n, double b) : name(n), balance(b) {
  cout << "constructor Brass" << endl;
}

Brass::~Brass() {
  cout << "~Brass" << endl;
}

bool Brass::withdraw(double b) {
  cout << "Brass::withdraw " << b << endl;
  if (b > balance) {
    return false;
  }

  balance -= b;
  return true;
}

void Brass::viewAcct() const {
  cout << "Brass::viewAcct. name: " << name << ", balance: " << balance << endl;
}

string Brass::toString() const {
  return "Brass::toString";
}

BrassPlus::BrassPlus(const string& n, double b) : Brass(n, b) {
  owesBank = 0;
  cout << "constructor BrassPlus" << endl;
}

BrassPlus::~BrassPlus() {
  cout << "~BrassPlus" << endl;
}

// 重载
bool BrassPlus::withdraw(double b) {
  cout << "BrassPlus::withdraw " << b << endl;
  if (Balance() < b) {
    Brass::withdraw(Balance());
    owesBank -= b;
  } else {
    Brass::withdraw(b);
  }
  return true;
}

void BrassPlus::viewAcct() const {
  cout << "BrassPlus::viewAcct. name: " << Name() << ", balance: " << Balance()
       << ", OweBank: " << owesBank << endl;
}

string BrassPlus::toString() const {
  return "BrassPlus::toString";
}