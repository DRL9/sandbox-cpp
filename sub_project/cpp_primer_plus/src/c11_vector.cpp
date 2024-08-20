#include "./c11_vector.h"
#include <iostream>

namespace VECTOR {
using namespace std;

Vector::Vector(double a1, double a2, Mode m) {
  mode = m;
  if (mode == RECT) {
    x = a1;
    y = a2;
  } else {
    angle = a1;
    length = a2;
  }
}

Vector Vector::operator+(const Vector& v) const {
  return Vector(x + v.x, y + v.y, mode);
}
Vector Vector::operator-(const Vector& v) const {
  return Vector(x - v.x, y - v.y, mode);
}
Vector Vector::operator-() const {
  return Vector(-x, -y, mode);
}

ostream& operator<<(ostream& os, const Vector::Mode& mode) {
  switch (mode) {
    case Vector::RECT:
      os << "RECT";
      break;
    case Vector::POLAR:
      os << "POLAR";
      break;
    default:
      break;
  }
  return os;
}

ostream& operator<<(ostream& os, const Vector& v) {
  os << v.mode << "(" << v.x << ", " << v.y << ")";
  return os;
}
}  // namespace VECTOR
