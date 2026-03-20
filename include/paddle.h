#pragma once
#include "tools.h"

Class Paddle {
private:
  Circle<double> c;

public:
  Paddle(Circle<double> c_) : c(std::move(c_)) {}
  Paddle(const Paddle&) = default;
  Paddle(double x, double y, double r) : c(Vec2<double>(x, y), r) {}
  Paddle() : c(Circle<double>()) {}
};

