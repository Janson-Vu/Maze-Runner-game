#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "MazeRunner.h"
#include "OOPGame.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window =
      new RenderWindow(VideoMode(1000, 600), "Player Movement Test");
  // create player
  Player* _player = new Player(10, 500, 300);
  // initialize position variables
  int _px = _player->getX();
  int _py = _player->getY();
  // initialize boolean variables to test movements have been made
  bool test_up = false;
  bool test_down = false;
  bool test_left = false;
  bool test_right = false;
  // test movement
  while (_window->isOpen()) {
    Event event;
    while (_window->pollEvent(event)) {
      if (event.type == Event::Closed) {
        _window->close();
      }
      // move up
      if (Keyboard::isKeyPressed(Keyboard::Up)) {
        _player->moveUp(_SPEED_);
        if (_px == _player->getX() && _py - _SPEED_ == _player->getY()) {
          std::cout << "Move Up works.\n";
          _px = _player->getX();
          _py = _player->getY();
        } else {
          std::cout << "Move Up does not work.\n";
        }
        test_up = true;
      }
      // move down
      if (Keyboard::isKeyPressed(Keyboard::Down)) {
        _player->moveDown(_SPEED_);
        if (_px == _player->getX() && _py + _SPEED_ == _player->getY()) {
          std::cout << "Move Down works.\n";
          _px = _player->getX();
          _py = _player->getY();
        } else {
          std::cout << "Move Down does not work.\n";
        }
        test_down = true;
      }
      // move left
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
        _player->moveLeft(_SPEED_);
        if (_px - _SPEED_ == _player->getX() && _py == _player->getY()) {
          std::cout << "Move Left works.\n";
          _px = _player->getX();
          _py = _player->getY();
        } else {
          std::cout << "Move Left does not work.\n";
        }
        test_left = true;
      }
      // move right
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
        _player->moveRight(_SPEED_);
        if (_px + _SPEED_ == _player->getX() && _py == _player->getY()) {
          std::cout << "Move Right works.\n";
          _px = _player->getX();
          _py = _player->getY();
        } else {
          std::cout << "Move Right does not work.\n";
        }
        test_right = true;
      }
    }
    _window->clear();
    _player->draw(_window);
    _window->display();
  }
  delete _player;
}