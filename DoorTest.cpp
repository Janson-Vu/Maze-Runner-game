#include <SFML/Graphics.hpp>
#include <iostream>

#include "MazeRunner.h"
#include "OOPGame.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window = new RenderWindow(VideoMode(1000, 600), "Door Test");
  // test case for getting door locations
  // test case 1
  Door* _door1 = new Door(50, 50, 10, 10);
  _door1->ColorBlue();
  if (_door1->getX() == 10 && _door1->getY() == 10) {
    std::cout << "Test 1 passed.\n";
  } else {
    std::cout << "Test 1 failed.\n";
  }

  // test case 2
  Door* _door2 = new Door(50, 50, 1000, 600);
  _door2->ColorBlue();
  if (_door2->getX() == 1000 && _door2->getY() == 600) {
    std::cout << "Test 2 passed.\n";
  } else {
    std::cout << "Test 2 failed.\n";
  }
  delete _door1;
  delete _door2;
  delete _window;
}