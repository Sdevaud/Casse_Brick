#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm.h>
#include <vector>
#include <array>

#include "graph.h"
#include "Vec2.h"
#include "save.h"
#include "readfromfile.h"



int main(int argc, char* argv[])
{

  int score;
  int lifes;
  std::array<double, 3> paddles;
  std::vector<std::vector<double>> bricks;
  std::vector<std::array<double, 5>> balls;

  if (argc < 2) {
    std::cout << "Usage: " << argv[0] << " fichier\n";
    return 1;
  }

  std::string filename = argv[1];

  test_read_data(filename, bricks, paddles, balls, lifes, score);


  return 0;
}
