#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "games.h"
#include "constants.h"
#include "tools.h"
#include "brick.h"
#include "ball.h"
#include "paddle.h"
#include "message.h"


void Games::case_of_txt_file(std::ifstream& file,
                      std::string& line,
                      const file::Keyword key) {

  switch(key) {
    case file::Keyword::OUTPUT : {
      std::cout << line << std::endl;
      break;
    }

    case file::Keyword::SCORE : {
      std::getline(file, line);
      score = std::stoi(line);
      if (score < 0) {
        message::invalid_score(score);
        correct_initialisation = false;
        return;
      } 
      break;
    }

    case file::Keyword::LIFES : {
      std::getline(file, line);
      lifes = std::stoi(line);
      if (lifes < 0) {
        message::invalid_lives(lifes);
        correct_initialisation = false;
        return;
      }
      break;
    }

    case file::Keyword::PADDLE : {
      std::getline(file, line);
      std::stringstream ss(line);
      double x, y, radius;
      ss >> x >> y >> radius;
      if (radius <= 0) {
        message::invalid_radius(radius);
        correct_initialisation = false;
        return;
      }
      if (y > 0 || -std::abs(y) + radius < 0 || x - radius < 0 || x + radius > cst::arena_size) {
        message::paddle_outside(x, y);
        correct_initialisation = false;
        return;
      }
      break;
    }
    
    case file::Keyword::BRICKS : {
      std::getline(file, line);
      size_t nbr_bricks = static_cast<size_t>(std::stoi(line));

      for (size_t i = 0; i < nbr_bricks; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);

        int type_brick;
        double x, y, size;
        ss >> type_brick >> x >> y >> size;

        Brick* new_brick = nullptr;    
        
        if (type_brick < 0 || type_brick > 2) {
          message::invalid_brick_type(type_brick);
          correct_initialisation = false;
          delete new_brick;
          return;
        }

        if (type_brick == 0) {
          int hit_points;
          ss >> hit_points;
          if (hit_points < 1 || hit_points > 7) {
            message::invalid_hit_points(hit_points);
            correct_initialisation = false;
            delete new_brick;
            return;
          }
          else new_brick = new RainbowBrick(x, y, size, type_brick, hit_points);
        }

        if (type_brick == 1) 
          new_brick = new BallBrick(x, y, size, type_brick);
        if (type_brick == 2) 
          new_brick = new SplitBrick(x, y, size, type_brick);

        if (!new_brick->inside_worlds()) {
          message::brick_outside(x, y);
          correct_initialisation = false;
          return;
        }

        if (!check_collision_brick(new_brick)) {  
          delete new_brick;
          return;
        }
        bricks.push_back(new_brick);
      }
      break;
    }
    
    case file::Keyword::BALLS : {
      std::getline(file, line);
      size_t nbr_balls = static_cast<size_t>(std::stoi(line));

      for (size_t i = 0; i < nbr_balls; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);

        double x, y, vx, vy;
        int rayon;
        ss >> x >> y >> rayon >> vx >> vy;

        if (rayon <= 0) {
          message::invalid_radius(rayon);
          correct_initialisation = false;
          return;
        }

        Ball* new_ball = new Ball(x, y, rayon, vx, vy);
        if (!new_ball->inside_worlds()) {
          message::ball_outside(x, y);
          correct_initialisation = false;
          delete new_ball;
          return;
        }
        if (!check_collision_ball(new_ball)) {  
          delete new_ball;
          return;
        }
        if (new_ball->norm_velocity() > cst::delta_norm_max) {
          message::invalid_delta(vx, vy);
          correct_initialisation = false;
          delete new_ball;
          return;
        }
        balls.push_back(new_ball);
      }
      break;
    }
  }
}

void Games::read_data_from_file(const std::string& filename) {
  std::ifstream file(filename);
  std::string line;

  if (!file) {
    std::cerr << "Error opening file\n";
    correct_initialisation = false;
    return;
  }

  while (std::getline(file, line) && correct_initialisation) {
    if (line.empty()) continue;
    if (line[0] == '#') {
      std::stringstream ss(line);
      std::string diese, keyword;
      file::Keyword key = file::Keyword::UNKNOWN;
      ss >> diese >> keyword;

      auto it = file::keywordMap.find(keyword);
      if (it != file::keywordMap.end()) key = it->second;
      case_of_txt_file(file, line, key);
    }
  }

  if (correct_initialisation) message::success();
  else reset_game();
}

void Games::reset_game() {
  lifes = 0;
  score = 0;
  correct_initialisation = true;
  for (Brick* brick : bricks) {
    delete brick;
  }
  for (Ball* ball : balls) {
    delete ball;
  }
  bricks.clear();
  balls.clear();
}

// --------- function of collision chekcs -------

bool Games::check_collision_brick(const Brick* brick_tested) {
  for (size_t i = 0; i < bricks.size(); ++i) {
    const Brick* other_brick = bricks[i];
    if (brick_tested->intersects(other_brick)) {
      message::collision_bricks(i, bricks.size() - 1);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }

  if (brick_tested->intersects(paddle)) {
    message::collision_paddle_brick(bricks.size() - 1);
    correct_initialisation = false;
    return correct_initialisation;
  }

  for (size_t i = 0; i < balls.size(); ++i) {
    const Ball* ball = balls[i];
    if (brick_tested->intersects(ball)) {
      message::collision_ball_brick(i, bricks.size() - 1);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }
  return correct_initialisation;
}

bool Games::check_collision_ball(const Ball* ball_tested) {
  for (size_t i = 0; i < balls.size(); ++i) {
    const Ball* other_ball = balls[i];
    if (ball_tested->intersects(other_ball)) {
      message::collision_balls(i, balls.size() - 1);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }

  if (ball_tested->intersects(paddle)) {
    message::collision_paddle_ball(balls.size() - 1);
    correct_initialisation = false;
    return correct_initialisation;
  }

  for (size_t i = 0; i < bricks.size(); ++i) {
    const Brick* brick = bricks[i];
    if (ball_tested->intersects(brick)) {
      message::collision_ball_brick(balls.size() - 1, i);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }
  return correct_initialisation;
}

bool Games::check_collision_paddle() {
  for (size_t i = 0; i < bricks.size(); ++i) {
    const Brick* brick = bricks[i];
    if (paddle.intersects(brick)) {
      message::collision_paddle_brick(i);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }

  for (size_t i = 0; i < balls.size(); ++i) {
    const Ball* other_ball = balls[i];
    if (paddle.intersects(other_ball)) {
      message::collision_paddle_ball(i);
      correct_initialisation = false;
      return correct_initialisation;
    }
  }
  return correct_initialisation;
}