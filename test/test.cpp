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