#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <unordered_map>

#include "readfromfile.h"
#include "message.h"

void case_of_txt_file(std::ifstream& file,
                      std::string& line,
                      Keyword key,
                      std::vector<std::vector<double>>& bricks,
                      std::array<double, 3>& paddles,
                      std::vector<std::array<double, 5>>& balls,
                      int& lifes,
                      int& score,
                      bool& correct_file) {

  switch(key) {
    case Keyword::OUTPUT : {
      std::cout << line << std::endl;
      break;
    }

    case Keyword::SCORE : {
      std::getline(file, line);
      score = std::stoi(line);
      if (score < 0) {
        message::invalid_score(score);
        correct_file = false;
      } 
      break;
    }

    case Keyword::LIVES : {
      std::getline(file, line);
      lifes = std::stoi(line);
      if (lifes < 0) {
        message::invalid_lives(lifes);
        correct_file = false;
      } 
      break;
    }

    case Keyword::PADDLE : {
      std::getline(file, line);
      std::stringstream ss(line);
      for (size_t i = 0; i < 3; ++i) ss >> paddles[i];
      break;
    }
    
    case Keyword::BRICKS : {
      std::getline(file, line);
      size_t nbr_bricks = static_cast<size_t>(std::stoi(line));

      for (size_t i = 0; i < nbr_bricks; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);

        std::vector<double> brick;
        double value;
        while (ss >> value) brick.push_back(value);
        bricks.push_back(brick);
      }
      break;
    }
    
    case Keyword::BALLS : {
      std::getline(file, line);
      size_t nbr_balls = static_cast<size_t>(std::stoi(line));

      for (size_t i = 0; i < nbr_balls; ++i) {
        std::getline(file, line);
        std::stringstream ss(line);

        std::array<double, 5> ball;
        for (size_t j = 0; j < 5; ++j) ss >> ball[j];
        balls.push_back(ball);
      }
      break;
    }
  }
}

void test_read_data(std::string filename,
                    std::vector<std::vector<double>>& bricks,
                    std::array<double, 3>& paddles,
                    std::vector<std::array<double, 5>>& balls, 
                    int& lifes, 
                    int& score) {

  std::ifstream file(filename);
  std::string line;
  bool correct_file = true;

  if (!file) {
    std::cerr << "Error opening file\n";
    exit(EXIT_FAILURE);
  }

  while (std::getline(file, line)) {
    if (line.empty()) continue;
    if (line[0] == '#') {
      std::stringstream ss(line);
      std::string diese, keyword;
      Keyword key = Keyword::UNKNOWN;
      ss >> diese >> keyword;

      auto it = keywordMap.find(keyword);
      if (it != keywordMap.end()) key = it->second;
      case_of_txt_file(file, line, key, bricks, paddles, balls, lifes, score, correct_file);
    }
  }
}
