#pragma once
#include "tools.h"

class Games {
private:
  std::vector<Brick*> bricks;
  std::vector<Ball> balls;
  Paddle paddle;
  int score;
  int lives;

  public:
    Games(std::vector<Brick*> bricks_, std::vector<Ball> balls_, Paddle paddle_, int score_, int lives_)
      : bricks(std::move(bricks_)), balls(std::move(balls_)), paddle(std::move(paddle_)), score(score_), lives(lives_) {}

    Games() : bricks(), balls(), paddle(), score(0), lives(0) {}

    Games(const Games&) = delete;
    Games& operator=(const Games&) = delete;

    Games(Games&&) = default;
    Games& operator=(Games&&) = default;

    ~Games() {
      for (Brick* brick : bricks) {
        delete brick;
      }
    }
};