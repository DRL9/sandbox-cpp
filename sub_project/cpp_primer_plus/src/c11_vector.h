#pragma once
#include <iostream>
namespace VECTOR {

class Vector {
 public:
  enum Mode { RECT, POLAR };

 private:
  double x;
  double y;
  double angle;
  double length;
  Mode mode;

 public:
  Vector(){};
  Vector(double, double, Mode = RECT);
  double x_val() const { return x; }
  double y_val() const { return y; }
  double angle_val() const { return angle; }
  double length_val() const { return length; }
  void set_rect_mode() { mode = RECT; }
  void set_polar_mode() { mode = POLAR; }

  Vector operator+(const Vector&) const;
  Vector operator-(const Vector&) const;
  //   反向
  Vector operator-() const;
  Vector operator*(double) const;

  friend Vector operator*(double, const Vector&);
  friend std::ostream& operator<<(std::ostream&, const Vector&);
};
}  // namespace VECTOR