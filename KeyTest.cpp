#include <SFML/Graphics.hpp>
#include <iostream>

#include "MazeRunner.h"
#include "OOPGame.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window = new RenderWindow(VideoMode(1000, 600), "Key Test");
  // test case for getting key locations
  // test case 1
  Key* _key1 = new Key(30, 30, 10, 10);
  _key1->ColorGreen();
  if (_key1->getX() == 10 && _key1->getY() == 10) {
    std::cout << "Test 1 passed.\n";
  } else {
    std::cout << "Test 1 failed.\n";
  }
  // test case 2
  Key* _key2 = new Key(30, 30, 1000, 600);
  _key2->ColorGreen();
  if (_key2->getX() == 1000 && _key2->getY() == 600) {
    std::cout << "Test 2 passed.\n";
  } else {
    std::cout << "Test 2 failed.\n";
  }
  delete _key1;
  delete _key2;
  delete _window;
}