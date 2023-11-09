#include <SFML/Graphics.hpp>

#include "MazeRunner.h"
#include "OOPGame.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window = new RenderWindow(VideoMode(1000, 600), "Path Test");
  // create paths for testing
  // test case 1
  Path* _path1 = new Path(1000, 100, 0, 0);
  _path1->ColourCyan();
  if (_path1->getHorzt() == 1000 && _path1->getVert() == 100 &&
      _path1->getX() == 0 && _path1->getY() == 0) {
    std::cout << "Test 1 passed.\n";
  } else {
    std::cout << "Test 1 failed.\n";
  }

  // test case 2
  Path* _path2 = new Path(50, 300, 900, 50);
  _path2->ColourCyan();
  if (_path2->getHorzt() == 50 && _path2->getVert() == 300 &&
      _path2->getX() == 900 && _path2->getY() == 50) {
    std::cout << "Test 2 passed.\n";
  } else {
    std::cout << "Test 2 failed.\n";
  }
  delete _path1;
  delete _path2;

  delete _window;
}