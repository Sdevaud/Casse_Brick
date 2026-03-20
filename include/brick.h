#pragma once
#include "tools.h"

class Brick {
protected:
  Square<double> s;
  int type;

public:
  Brick(Square<double> s_, int type_) : s(std::move(s_)), type(type_) {}
  Brick(const Brick&) = default;
  Brick(double x, double y, double size, int type) : s(Vec2<double>(x, y), size), type(type) {}
  Brick() : s(Square<double>()), type(0) {}
};

class RainbowBrick : public Brick {
private:
  int hit_points;
public:
  RainbowBrick(Square<double> s_, int type_, int hit_points_) : Brick(std::move(s_), type_), hit_points(hit_points_) {}
  RainbowBrick(const RainbowBrick&) = default;
  RainbowBrick(double x, double y, double size, int type, int hit_points) : Brick(Vec2<double>(x, y), size, type), hit_points(hit_points) {}
  RainbowBrick() : Brick(), hit_points(0) {}
};

class BallBrick : public Brick {
public:
  BallBrick(Square<double> s_, int type_) : Brick(std::move(s_), type_) {}
  BallBrick(const BallBrick&) = default;
  BallBrick(double x, double y, double size, int type) : Brick(Vec2<double>(x, y), size, type) {}
  BallBrick() : Brick() {}
};

class SplitBrick : public Brick {
public:
  SplitBrick(Square<double> s_, int type_) : Brick(std::move(s_), type_) {}
  SplitBrick(const SplitBrick&) = default;
  SplitBrick(double x, double y, double size, int type) : Brick(Vec2<double>(x, y), size, type) {}
  SplitBrick() : Brick() {}
};