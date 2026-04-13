#include <iostream>
#include <string>

#include "ball.h"
#include "brick.h"
#include "paddle.h"
#include "tools.h"

bool Ball::intersects(const Brick* brick) const {
  return ::intersects(circle, brick->get_square());
}

bool Ball::intersects(const Paddle& paddle) const {
  return ::intersects(circle, paddle.get_circle());
}

bool Ball::intersects(const Ball* ball) const {
  return ::intersects(circle, ball->get_circle());
}