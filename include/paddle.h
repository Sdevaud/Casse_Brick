#pragma once
#include "tools.h"

class Brick;
class Ball;

class Paddle {
private:
  Circle<double> circle;

public:
//------------------------- Constructors, Destructors and operators= -----------------------------
  Paddle(Circle<double> circle_) : circle(std::move(circle_)) {}
  Paddle(const Paddle&) = default;
  Paddle(double x, double y, double r) : circle(Vec2<double>(x, y), r) {}
  Paddle() : circle(Circle<double>()) {}

  //------------------------- Getters and Setters -----------------------------
  const Circle<double>& get_circle() const { return circle; }
  void set_circle(const Circle<double>& new_circle) { circle = new_circle; }

  //------------------------- other methods -----------------------------
  bool intersects(const Brick* brick) const;
  bool intersects(const Ball* ball) const;
};

