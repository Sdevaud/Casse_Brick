#include <iostream>
#include "class.h"
#include "graph.h"
#include "Vec2.h"
#include "save.h"

void test_Vec2 {

  Vec2<double> test1(5, 2);
  Vec2<double> test2(10, 3);
  Vec2<double> test3(test1);
  Vec2<double> test4(test1 - (double)1e-4);
  Vec2<double> test5 = test1 - (double)1e-8;

  std::cout << test1 + test2 << std::endl;
  std::cout << (test1 == test3) << std::endl;
  std::cout << (test1 == test4) << std::endl;
  std::cout << (test1 == test5) << std::endl;
}

class HelloWorld : public Gtk::Window
{

public:
  HelloWorld();
  ~HelloWorld() override;

protected:
  //Signal handlers:
  void on_button_clicked();

  //Member widgets:
  Gtk::Button m_button;
};

HelloWorld::HelloWorld()
: m_button("Hello World")   // creates a new button with label "Hello World".
{
  // Sets the margin around the button.
  m_button.set_margin(200);

  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
  m_button.signal_clicked().connect(sigc::mem_fun(*this,
              &HelloWorld::on_button_clicked));

  // This packs the button into the Window (a container).
  set_child(m_button);
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::on_button_clicked()
{
  std::cout << "Hello World" << std::endl;
}