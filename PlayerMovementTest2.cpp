#include <SFML/Graphics.hpp>
#include <iostream>

#include "GameObject.h"
#include "MazeRunner.h"
#include "OOPGame.h"
#include "Player.h"
#include "PlayerMovement.h"

using namespace sf;

int main() {
  // draw window for displaying
  RenderWindow* _window =
      new RenderWindow(VideoMode(1000, 600), "Player Movement Test 2");
  // create player
  Player* _player = new Player(10, 100, 500);
  // create key at specified location
  Key* _key = new Key(30, 30, 100, 500);
  _key->ColorGreen();
  // create door at specified location
  Door* _door = new Door(50, 50, 200, 400);
  _door->ColorBlue();
  // create boolean variables for storing whether the key has been taken, the
  // door is opened
  bool _isGotKey = false;
  bool _isDoorOpen = false;
  bool _isWin = false;
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
      }
      // move down
      if (Keyboard::isKeyPressed(Keyboard::Down)) {
        _player->moveDown(_SPEED_);
      }
      // move left
      if (Keyboard::isKeyPressed(Keyboard::Left)) {
        _player->moveLeft(_SPEED_);
      }
      // move right
      if (Keyboard::isKeyPressed(Keyboard::Right)) {
        _player->moveRight(_SPEED_);
      }
    }
    bool print_key_message = false;
    bool print_win_message = false;

    PlayerMovement movement(_player->getX(), _player->getY());
    // check if player has collected the key or not
    if (!_isGotKey) {  // if player has not found key
      if (movement.CollectKey(_key)) {
        _isGotKey = true;
        if (!print_key_message) {
          // std::cout << "You have found the key. Now find the door.\n";
          print_key_message = true;
        }

        _key->ColorTransparent();
      }
    } else {  // if player has found key
      if (!print_key_message) {
        // std::cout << "You have found the key. Now find the door.\n";
        print_key_message = true;
      }
      _key->ColorTransparent();
    }

    // check if player is at the door area
    if (!_isDoorOpen) {  // if milestone of opening the door not reached
      if (movement.openDoor(_door)) {  // check if player has opened the door
        _isDoorOpen = true;
        _door->ColorTransparent();
      }
    } else {  // else milestone of opening the door not reached
      _isDoorOpen = false;
    }

    // check if player has won
    if (_isGotKey && _isDoorOpen) {
      _isWin = true;
      event.type = Event::Closed;
    }

    if (_isWin) {  // if milestone of winning reached -> print out message
      if (!print_win_message) {
        // std::cout << "You win!";
        print_win_message = true;
      }
    }

    _window->clear();
    _key->draw(_window);
    _door->draw(_window);
    _player->draw(_window);
    _window->display();
  }

  if (_isGotKey) std::cout << "You have found the key. Now find the door.\n";
  if (_isWin) std::cout << "You open the door! \n";

  delete _player;
  delete _door;
  delete _key;
  delete _window;

  return 0;
}