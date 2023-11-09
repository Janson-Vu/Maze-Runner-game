#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "MazeRunner.h"
#include "OOPGame.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window = new RenderWindow(VideoMode(1000, 600), "Player Test");
  // test case for getting locations
  // test case 1
  Player* _player1 = new Player(10, 10, 10);
  if (_player1->getX() == 10 && _player1->getY() == 10) {
    std::cout << "Test 1 passed.\n";
  } else {
    std::cout << "Test 1 failed.\n";
  }
  delete _player1;
  // test case 2
  Player* _player2 = new Player(10, 900, 25);
  if (_player2->getX() == 900 && _player2->getY() == 25) {
    std::cout << "Test 2 passed.\n";
  } else {
    std::cout << "Test 2 failed.\n";
  }
  delete _player2;
  delete _window;
}