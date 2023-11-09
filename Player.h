#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <fstream>
#include <iostream>
#include <string>

#include "GameObject.h"

// speed of the arrow keys
const int _SPEED_ = 10;

class Player : public GameObject {
 protected:
  CircleShape* _body;

  private:
  int _px;
  int _py;
  std::ofstream _moveRecord;
  std::ofstream _recentMove;
  std::string _latestMove;
  bool _hasKey;

 public:
  Player() {}
  Player(int radius, int x, int y) {
    _body = new CircleShape();
    _body->setFillColor(sf::Color::Magenta);
    _body->setOrigin(radius / 2, radius / 2);
    _body->setRadius(radius);
    _body->setPosition(x, y);

    _moveRecord.open("player_moves.txt", std::ios_base::app);
  }

  void draw(RenderWindow* window) { window->draw(*_body); }

  void moveUp(int speed) { _body->move(0, -_SPEED_); }
  void moveDown(int speed) { _body->move(0, _SPEED_); }
  void moveRight(int speed) { _body->move(_SPEED_, 0); }
  void moveLeft(int speed) { _body->move(-_SPEED_, 0); }
  int getX() { return _body->getPosition().x; }
  int getY() { return _body->getPosition().y; }

  void move(Player* player, int* array) {
    if (Keyboard::isKeyPressed(Keyboard::Up)) {
      if (array[1] == -1) {
        return;
      }
      player->moveUp(_SPEED_);
      // record player movement into player_moves.txt file
      _moveRecord << "Player entered UP" << std::endl;
    }
    if (Keyboard::isKeyPressed(Keyboard::Down)) {
      if (array[3] == -1) {
        return;
      }
      player->moveDown(_SPEED_);
      // record player movement into player_moves.txt file
      _moveRecord << "Player entered DOWN" << std::endl;
    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
      if (array[2] == -1) {
        return;
      }
      player->moveRight(_SPEED_);
      // record player movement into player_moves.txt file
      _moveRecord << "Player entered RIGHT" << std::endl;
    }
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
      if (array[0] == -1) {
        return;
      }
      player->moveLeft(_SPEED_);
      // record player movement into text files
      _moveRecord << "Player entered LEFT" << std::endl;
    }
  }

  bool CollectKey(Key* key) {
    // check if player is in the area to take the key
    _px = this -> getX();
    _py = this -> getY();
    if (_px >= key->getX() && _px <= key->getX() + key->getHorzt() &&
        _py >= key->getY() && _py <= key->getY() + key->getVert()) {
      // gotta press space to get the key
      if (Keyboard::isKeyPressed(Keyboard::Space)) {
        return true;
      }
    }
    return false;
  };

  bool openDoor(Door* door) {

    _px = this -> getX();
    _py = this -> getY();
    // check if player is in the area to take the key
    if (_px >= door->getX() && _px <= door->getX() + door->getHorzt() &&
        _py >= door->getY() && _py <= door->getY() + door->getVert()) {
      // gotta press space to open the door
      if (Keyboard::isKeyPressed(Keyboard::Space)) {
        return true;
      }
    }
    return false;
  };
  ~Player(){
    delete _body;
    std::cout <<"Player body is deleted." <<std::endl;
  };
};
