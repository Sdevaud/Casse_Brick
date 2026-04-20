#include <iostream>
#include <gtkmm/application.h>
#include <gtkmm.h>
#include <vector>
#include <array>

#include "graph.h"
#include "games.h"



int main(int argc, char* argv[])
{
  Games game;

  // test only the initilisation mode if a file is provided as an argument, otherwise enter interactive mode
  if (argc == 2) {
    std::cout << "launch init mode" << std::endl;
    std::string filename = argv[1];
    game.read_data_from_file(filename);
    return 0;
  }

  do {
    std::cout << "Enter the name of the file to read (or 'exit' to quit): \n";
    std::string filename;
    std::getline(std::cin, filename);

    if (filename == "exit") {
      break;
    }

    game.read_data_from_file(filename);

    if (!game.is_correct_initialisation()) {
      std::cout << "Error in file reading. Please try again.\n";
    }
  } while (!game.is_correct_initialisation());

  return 0;
}
