#pragma once
#include "tools.h"
#include "brick.h"
#include "ball.h"
#include "paddle.h"

class Games {
private:
  std::vector<Brick*> bricks;
  std::vector<Ball*> balls;
  Paddle paddle;
  int score = 0;
  int lifes = 0;
  bool correct_initialisation = true;

public:
//------------------------ Constructors, Destructors and operators= -----------------------------
  Games(std::vector<Brick*> bricks_, std::vector<Ball*> balls_, Paddle paddle_, int score_, int lives_)
    : bricks(std::move(bricks_)), balls(std::move(balls_)), paddle(std::move(paddle_)), score(score_), lifes(lives_) {}

  Games() = default;

  Games(const Games&) = delete;
  Games& operator=(const Games&) = delete;

  Games(Games&&) = default;
  Games& operator=(Games&&) = default;

  ~Games() { reset_game(); }

  //------------------------ Getters and Setters -----------------------------

  int get_score() const { return score; }
  int get_lives() const { return lifes; }
  bool is_correct_initialisation() const { return correct_initialisation; }
  const Paddle& get_paddle() const { return paddle; }
  const std::vector<Brick*>& get_bricks() const { return bricks; }
  const std::vector<Ball*>& get_balls() const { return balls; }

  void set_score(int new_score) { score = new_score; }
  void set_lives(int new_lives) { lifes = new_lives; }
  void set_paddle(const Paddle& new_paddle) { paddle = new_paddle; }
  void set_bricks(const std::vector<Brick*>& new_bricks) { bricks = new_bricks; }
  void set_balls(const std::vector<Ball*>& new_balls) { balls = new_balls; }

  //------------------------ other methods -----------------------------
public:
  void read_data_from_file(const std::string& filename);
  
private :
  void case_of_txt_file(std::ifstream& file, std::string& line, const file::Keyword key);
  bool check_collision_brick(const Brick* brick_tested);
  bool check_collision_ball(const Ball* ball_tested);
  bool check_collision_paddle();
  void reset_game();
};