#include "brick.h"
#include "ball.h"
#include "paddle.h"

bool Brick::intersects(const Brick* other) const {
  return ::intersects(square, other->square);
}

bool Brick::intersects(const Paddle& paddle) const {
  return ::intersects(square, paddle.get_circle());
}

bool Brick::intersects(const Ball* ball) const {
  return ::intersects(square, ball->get_circle());
}