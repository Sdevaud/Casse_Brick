#include <iostream>
#include <gtkmm.h>
#include "gui.h"


DisplayGame::DisplayGame() : save("save"), exit("exit") {

  save.set_margin(300);
  exit.set_margin(100);

  save.signal_clicked().connect(sigc::mem_fun(*this,
              &DisplayGame::save_button_clicked));

  exit.signal_clicked().connect(sigc::mem_fun(*this,
            &DisplayGame::exit_button_clicked));

  set_child(save);
  set_child(exit);
}

DisplayGame::~DisplayGame() {}

void DisplayGame::save_button_clicked() {
  std::cout << "Save button clicked" << std::endl;
}

void DisplayGame::exit_button_clicked() {
  std::cout << "Exit button clicked" << std::endl;
}

int test_window(int argc, char* argv[]) {
  auto app = Gtk::Application::create("org.test.gtk");
  return app->make_window_and_run<DisplayGame>(argc, argv);
}