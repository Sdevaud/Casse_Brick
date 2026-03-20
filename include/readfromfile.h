#pragma once
#include <unordered_map>
#include <vector>
#include <string>
#include <array>

enum class Keyword {
  OUTPUT,
  SCORE,
  LIVES,
  PADDLE,
  BRICKS,
  BALLS,
  UNKNOWN
};

inline std::unordered_map<std::string, Keyword> keywordMap = {
  {"output:", Keyword::OUTPUT},
  {"score", Keyword::SCORE},
  {"lives", Keyword::LIVES},
  {"paddle", Keyword::PADDLE},
  {"bricks", Keyword::BRICKS},
  {"balls", Keyword::BALLS},
  {"unknow", Keyword::UNKNOWN}
};

void test_read_data(std::string filename,
                    std::vector<std::vector<double>>& bricks, 
                    std::array<double, 3>& paddles, 
                    std::vector<std::array<double, 5>>& balls, 
                    int& lifes, 
                    int& score);

void case_of_txt_file(std::ifstream& file,
                      std::string& line,
                      Keyword key,
                      std::vector<std::vector<double>>& bricks,
                      std::array<double, 3>& paddles,
                      std::vector<std::array<double, 5>>& balls,
                      int& lifes,
                      int& score,
                      bool& correct_file);