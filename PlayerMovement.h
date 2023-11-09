#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#include <fstream>
#include <iostream>

#include "Door.h"
#include "Key.h"
#include "Player.h"

class PlayerMovement : public Player {
 private:
  int _px;
  int _py;
  std::ofstream _moveRecord;
  std::ofstream _recentMove;
  std::string _latestMove;
  bool _hasKey;

 public:
  PlayerMovement(int x, int y) {
    _px = x;
    _py = y;
    // record all the moves entered into a text file
    _moveRecord.open("player_moves.txt", std::ios_base::app);
  }

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

  ~PlayerMovement() {
    // close the text file when game window is closed
    _moveRecord.close();
    //delete _body;
  }
};