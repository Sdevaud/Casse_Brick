#pragma once
#include "tools.h"

class Brick;
class Paddle;

class Ball {
private:
  Circle<double> circle;
  Vec2<double> velocity;
  int rayon;

public:
//------------------------- Constructors, Destructors and operators= -----------------------------
  Ball(Circle<double> circle_, Vec2<double> velocity_)
    : circle(std::move(circle_)), velocity(std::move(velocity_)) {}

  Ball(const Ball&) = default;
  Ball(double x_, double y_, double r_, double vx_, double vy_)
    : circle(Vec2<double>(x_, y_), r_), velocity(Vec2<double>(vx_, vy_)) {}
  Ball() : circle(Circle<double>()), velocity(Vec2<double>()) {}

  //------------------------- Getters and Setters -----------------------------
  const Circle<double>& get_circle() const { return circle; }
  const Vec2<double>& get_velocity() const { return velocity; }

  void set_circle(const Circle<double>& new_circle) { circle = new_circle; }
  void set_velocity(const Vec2<double>& new_velocity) { velocity = new_velocity; }

  //------------------------- other methods -----------------------------
  bool inside_worlds() { return circle.inside_worlds(); }
  double norm_velocity() const { return velocity.norm(); }
  bool intersects(const Brick* brick) const ;
  bool intersects(const Paddle& paddle) const;
  bool intersects(const Ball* ball) const;

  // ------------------------- operators -----------------------------

};