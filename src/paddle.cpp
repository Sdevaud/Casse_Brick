#include "brick.h"
#include "ball.h"
#include "paddle.h"
#include "tools.h"

bool Paddle::intersects(const Brick* brick) const {
  return ::intersects(circle, brick->get_square());
}

bool Paddle::intersects(const Ball* ball) const {
  return ::intersects(circle, ball->get_circle());
}