#pragma once
#include <gtkmm.h>
#include <map>
#include "type.h"

int test_window(int argc, char* argv[]);

class DisplayGame : public Gtk::Window {

public:
  DisplayGame() = default;
  ~DisplayGame() = default;

private:
  Gtk::Box main_box, button_box, infos_box, menu_box, game_box;
  std::map<graphical::ButtonId, Gtk::Button> buttons;
  std::map<graphical::InfoId, Gtk::Label> infos;

  void button_clicked(graphical::ButtonId id);
  void save_button_clicked();
  void exit_button_clicked();
  void Open_button_clicked();
  void Restart_button_clicked();
  void Start_button_clicked();
  void Step_button_clicked();
  void Stop_button_clicked();

  void set_info();

};