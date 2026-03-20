#pragma once
#include "tools.h"

class Ball {
private:
  Circle<double> c;
  Vec2<double> v;

public:
  Ball(Circle<double> c_, Vec2<double> v_)
    : c(std::move(c_)), v(std::move(v_)) {}

  Ball(const Ball&) = default;
  Ball(double x, double y, double r, double vx, double vy)
    : c(Vec2<double>(x, y), r), v(Vec2<double>(vx, vy)) {}
  Ball() : c(Circle<double>()), v(Vec2<double>()) {}
};