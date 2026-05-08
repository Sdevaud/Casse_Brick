#pragma once

int test_window(int argc, char* argv[]);

class DisplayGame : public Gtk::Window {

public:
  DisplayGame();
  ~DisplayGame() override;

protected:
  void on_button_clicked();

  Gtk::Button save;
  Gtk::Button exit;
};