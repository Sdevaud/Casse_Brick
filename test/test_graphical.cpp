#include <iostream>
#include <gtkmm.h>
#include "test_graphical.h"


DisplayGame::DisplayGame() {

  infos.emplace(graphical::InfoId::Infos, Gtk::Label("Infos :"));
  infos.emplace(graphical::InfoId::Score, Gtk::Label("Score :"));
  infos.emplace(graphical::InfoId::Lives, Gtk::Label("Lives :"));
  infos.emplace(graphical::InfoId::Bricks, Gtk::Label("Bricks :"));
  infos.emplace(graphical::InfoId::Balls, Gtk::Label("Balls :"));

  buttons.emplace(graphical::ButtonId::Save, Gtk::Button("Save"));
  buttons.emplace(graphical::ButtonId::Exit, Gtk::Button("Exit"));
  buttons.emplace(graphical::ButtonId::Open, Gtk::Button("Open"));
  buttons.emplace(graphical::ButtonId::Restart, Gtk::Button("Restart"));
  buttons.emplace(graphical::ButtonId::Start, Gtk::Button("Start"));
  buttons.emplace(graphical::ButtonId::Step, Gtk::Button("Step"));
  buttons.emplace(graphical::ButtonId::Stop, Gtk::Button("Stop"));

  main_box = Gtk::Box(Gtk::Orientation::HORIZONTAL);
  button_box = Gtk::Box(Gtk::Orientation::VERTICAL);
  infos_box = Gtk::Box(Gtk::Orientation::VERTICAL);
  menu_box = Gtk::Box(Gtk::Orientation::VERTICAL);

  for (auto& [id, button] : buttons) {
    if (id == graphical::ButtonId::Stop) continue;
    button.signal_clicked().connect(
      sigc::bind(sigc::mem_fun(*this, &DisplayGame::button_clicked), id));
    button_box.append(button);
  }

  for (auto& [id, label] : infos) {
    infos_box.append(label);
  }

  set_title("Brick Breaker");
  menu_box.append(button_box);
  menu_box.append(infos_box);
  main_box.append(menu_box);
  main_box.append(game_box);
  set_child(main_box);
}

void DisplayGame::button_clicked(graphical::ButtonId id) {
  switch (id) {
    case graphical::ButtonId::Save : save_button_clicked(); break;
    case graphical::ButtonId::Exit : exit_button_clicked(); break;
    case graphical::ButtonId::Open : Open_button_clicked(); break;
    case graphical::ButtonId::Restart : Restart_button_clicked(); break;
    case graphical::ButtonId::Start : Start_button_clicked(); break;
    case graphical::ButtonId::Step : Step_button_clicked(); break;
    case graphical::ButtonId::Stop : Stop_button_clicked(); break;
    default: break;
  }
}

void DisplayGame::save_button_clicked() {
  std::cout << "Save button clicked" << std::endl;
}

void DisplayGame::exit_button_clicked() {
  std::cout << "Exit button clicked" << std::endl;
}

void DisplayGame::Open_button_clicked() {
  std::cout << "Open button clicked" << std::endl;
}

void DisplayGame::Restart_button_clicked() {
  std::cout << "Restart button clicked" << std::endl;
}

void DisplayGame::Start_button_clicked() {
  std::cout << "Start button clicked" << std::endl;
}

void DisplayGame::Step_button_clicked() {
  std::cout << "Step button clicked" << std::endl;
}

void DisplayGame::Stop_button_clicked() {
  std::cout << "Stop button clicked" << std::endl;
}     

int test_window(int argc, char* argv[]) {
  auto app = Gtk::Application::create("org.test.gtk");
  return app->make_window_and_run<DisplayGame>(argc, argv);
}

void DisplayGame::set_info() {}
