#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <fstream>
#include <iostream>
#include <random>
#include <string>

#include "Door.h"
#include "Key.h"
#include "OOPGame.h"
#include "Path.h"
#include "Player.h"
#include "PlayerMovement.h"

const int _NUM_PATHS_ = 30;

class MazeRunner : public OOPGame {
 private:
  RenderWindow* _window;
  Player* _player;
  MazeObject** _path;
  Key* _key;
  int _keyPath, _doorPath;
  Door* _door;
  bool _isGotKey;
  bool _isDoorOpen;
  bool _isWin;
  int _size1, _size2;
  Text* _text;
  Font _font;

  // function to get random value in the range [0...29] (total paths = 30)
  // -> randomly decide which path the door and the key are on
  int randomPath() {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 29);
    int pathNum = dis(gen);
    return pathNum;
  }

 public:
  MazeRunner(int size1, int size2, std::string title) {
    _window = new RenderWindow(VideoMode(size1, size2), title);

    _path = new MazeObject*[_NUM_PATHS_];
    // create maze
    // (horizontal, vertical, x of top left, y of top left)
    _path[0] = new Path(50, size2, 0, 0);
    _path[1] = new Path(100, 50, 50, size2 - 50);
    _path[2] = new Path(50, 150, 100, 450);
    _path[3] = new Path(100, 50, 50, 0);
    _path[4] = new Path(50, 350, 100, 50);
    _path[5] = new Path(400, 100, 150, 300);
    _path[6] = new Path(100, 200, 200, 100);
    _path[7] = new Path(200, 100, 200, 0);
    _path[8] = new Path(50, 150, 350, 100);
    _path[9] = new Path(100, 200, 200, 400);
    _path[10] = new Path(100, 50, 300, size2 - 50);
    _path[11] = new Path(100, 100, 350, size2 - 150);
    _path[12] = new Path(150, 50, 400, size2 - 200);
    _path[13] = new Path(100, 100, 350, size2 - 300);
    _path[14] = new Path(50, 150, 500, 150);
    _path[15] = new Path(50, 150, 500, size2 - 150);
    _path[16] = new Path(250, 50, 550, size2 - 50);
    _path[17] = new Path(50, 100, 600, size2 - 150);
    _path[18] = new Path(50, 50, 650, size2 - 150);
    _path[19] = new Path(50, 150, 750, size2 - 200);
    _path[20] = new Path(200, 100, 600, size2 - 300);
    _path[21] = new Path(30, 200, 600, 200);
    _path[22] = new Path(50, 50, 700, 250);
    _path[23] = new Path(100, 50, 700, 200);
    _path[24] = new Path(200, 50, 700, 150);
    _path[25] = new Path(150, 50, 700, 100);
    _path[26] = new Path(300, 100, 500, 0);
    _path[27] = new Path(50, 350, 850, 200);
    _path[28] = new Path(150, 50, 850, size2 - 50);
    _path[29] = new Path(50, 750, size1 - 50, 0);

    _player = new Player(10, 10, 10);

    // get random path for ddor and key
    _keyPath = randomPath();
    _doorPath = randomPath();

    // dev mode to test where the key and the door are
    std::cout << _keyPath << " " << _doorPath << std::endl;

    // intitialize key and door to the random path got from the randomPath
    // function
    _key = new Key(30, 30, _path[_keyPath]->getX(), _path[_keyPath]->getY());
    _door =
        new Door(50, 50, _path[_doorPath]->getX(), _path[_doorPath]->getY());

    // load font
    if (!_font.loadFromFile("font.ttf")) {
      std::cout << "Cannot load font." << std::endl;
      exit(0);
    }
    // set text to display when player has reached a game milestone (find key,
    // open door)
    _text = new Text[2];
    for (int i = 0; i < 3; i++) {
      _text[i].setFont(_font);
      _text[i].setFillColor(Color::Red);
      if (i == 1) {
        _text[i].setCharacterSize(30);
      } else {
        _text[i].setCharacterSize(10);
      }

      _text[i].setPosition(10, 10 + 100 * i);
    }

    // initialize game milestone
    _isGotKey = false;
    _isDoorOpen = false;
    _isWin = false;

    // keeping window dimension
    _size1 = size1;
    _size2 = size2;
  }
  MazeRunner() {
    MazeRunner(800, 1000, "Maze Runner");
    _player = new Player(10, 10, 10);
    _size1 = 0;
    _size2 = 0;
  }

  // function to change the visibility of game objects (path, door, key)
  void visibility(int pathNum) {
    for (int i = 0; i < _NUM_PATHS_; i++) {
      // check if player is on the path that has the key
      if (pathNum == _keyPath) {
        _key->ColorGreen();
      }  // else {
      //   _key->ColorTransparent();
      // }

      // check if player is on the path that has the door
      if (pathNum == _doorPath) {
        _door->ColorBlue();
      }

      // check if player is on the path given in the argument
      if (pathNum == i) {
        _path[i]->ColourCyan();
      }  // else {
      //   _path[i]->ColorTransparent();
      // } // uncomment to keep the player guessing the shape of the maze
    }
  }

  void run() {
    while (_window->isOpen()) {
      Event event;

      while (_window->pollEvent(event)) {
        if (event.type == Event::Closed) {
          _window->close();
        }

        _window->clear();

        // draw the paths (intitially transparent)
        for (int i = 0; i < _NUM_PATHS_; i++) {
          _path[i]->draw(_window);
        }

        // draw the key (intitally transparent)
        _key->draw(_window);

        // draw the door (intitally transparent)
        _door->draw(_window);

        // draw player
        _player->draw(_window);

        //  control logic of movement of player in the maze
        int px = _player->getX();
        int py = _player->getY();

        int* array = new int[4];
        for (int i = 0; i < _NUM_PATHS_; i++) {
          // if on path i
          if (px >= _path[i]->getX() &&
              px <= _path[i]->getX() + _path[i]->getHorzt() &&
              py >= _path[i]->getY() &&
              py <= _path[i]->getY() + _path[i]->getVert()) {
            visibility(i);

            // 0 if on a path, -1 if on no path
            int pxPosition[4] = {px - 10, px, px + 10, px};
            int pyPosition[4] = {py, py - 10, py, py + 10};

            for (int aa = 0; aa < 4; aa++) {
              // if new position is still on path i
              for (int j = 0; j < _NUM_PATHS_; j++) {
                // if new position is on a diff path
                if (pxPosition[aa] >= _path[j]->getX() &&
                    pxPosition[aa] <= _path[j]->getX() + _path[j]->getHorzt() &&
                    pyPosition[aa] >= _path[j]->getY() &&
                    pyPosition[aa] <= _path[j]->getY() + _path[j]->getVert()) {
                  array[aa] = 0;
                  break;
                }
                // if new position is not on any path
                if (j == _NUM_PATHS_ - 1) {
                  array[aa] = -1;
                }
              }
            }
          }
        }

        // move the player based on the logic above
        
        _player->move(_player, array);

        // clear the array after the movement
        delete[] array;

        // display message while playing to inform player
        _text[0].setString(
            "You have found the key to unlock the door. Now you have to find "
            "the door.");
        _text[1].setString("You have beaten our maze!!");

        // check if player has collected the key or not
        if (!_isGotKey) {  // if player has not found key
          if (_player -> CollectKey(_key)) {
            _isGotKey = true;
            _window->draw(_text[0]);
            _key->ColorTransparent();
          }
        } else {  // if player has found key
          _window->draw(_text[0]);
          _key->ColorTransparent();
        }

        // check if player is at the door area
        if (!_isDoorOpen) {  // if milestone of opening the door not reached
          if (_player -> openDoor(
                  _door)) {  // check if player has opened the door
            _isDoorOpen = true;
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
          _window->draw(_text[1]);
        }

        // save the key status to the playerSaveHistory.txt by pressing S on
        // keyboard
        if (Keyboard::isKeyPressed(Keyboard::S)) {
          std::ofstream recentMove;
          recentMove.open("playerSaveHistory.txt", std::ofstream::trunc);
          recentMove << px << std::endl << py << std::endl;
          recentMove << _isGotKey << std::endl;
          recentMove.close();
        }

        // shortcut to close the game window (aka end the game)
        if (Keyboard::isKeyPressed(Keyboard::Q)) {
          _window->close();
        }

        _window->display();
      }
    }
  }

  ~MazeRunner() {
    for (int i = 0; i < _NUM_PATHS_; i++) {
      delete _path[i];
    }
    delete[] _path;
    delete _player;
    delete _door;
    delete _key;
    delete[] _text;
    delete _window;

    std::cout<<"Maze Runner is deleted"<<std::endl;
  }
};