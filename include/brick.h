#pragma once
#include "tools.h"

class Ball;
class Paddle;

class Brick {
protected:
  Square<double> square;
  int type;

public:
  // ------------------------- Constructors, Destructors and operators= -----------------------------
  Brick(Square<double> s_, int type_) : square(std::move(s_)), type(type_) {}
  Brick(const Brick&) = default;
  Brick(double x_, double y_, double size_, int type_) : square(Vec2<double>(x_, y_), size_), type(type_) {}
  Brick() : square(Square<double>()), type(0) {}

  //------------------------- Getters and Setters -----------------------------
  const Square<double>& get_square() const { return square; }
  int get_type() const { return type; }

  void set_square(const Square<double>& new_square) { square = new_square; }
  void set_type(int new_type) { type = new_type; }

  //------------------------- other methods -----------------------------
  virtual bool intersects(const Brick* other) const;
  virtual bool intersects(const Paddle& paddle) const;
  virtual bool intersects(const Ball* ball) const;
  virtual bool inside_worlds() { return square.inside_worlds(); }
};

class RainbowBrick : public Brick {
private:
  int hit_points = 1;
public:
//------------------------- Constructors, Destructors and operators= -----------------------------
  RainbowBrick(Square<double> square_, int type_, int hit_points_) : Brick(std::move(square_), type_), hit_points(hit_points_) {}
  RainbowBrick(const RainbowBrick&) = default;
  RainbowBrick(double x_, double y_, double size_, int type_, int hit_points_) : Brick(x_, y_, size_, type_), hit_points(hit_points_) {}
  RainbowBrick() = default;

  //------------------------- Getters and Setters -----------------------------
  int get_hit_points() const { return hit_points; }
  void set_hit_points(int new_hit_points) { hit_points = new_hit_points; }
};

class BallBrick : public Brick {
public:
//------------------------- Constructors, Destructors and operators= -----------------------------
  BallBrick(Square<double> square_, int type_) : Brick(std::move(square_), type_) {}
  BallBrick(const BallBrick&) = default;
  BallBrick(double x_, double y_, double size_, int type_) : Brick(x_, y_, size_, type_) {}
  BallBrick() : Brick() {}
};

class SplitBrick : public Brick {
public:
//------------------------- Constructors, Destructors and operators= -----------------------------
  SplitBrick(Square<double> square_, int type_) : Brick(std::move(square_), type_) {}
  SplitBrick(const SplitBrick&) = default;
  SplitBrick(double x_, double y_, double size_, int type_) : Brick(x_, y_, size_, type_) {}
  SplitBrick() : Brick() {}
};