#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#include "MazeObject.h"

class Door : public MazeObject {
 public:
  Door(int hortLength, int vertLength, int x, int y)
      : MazeObject(hortLength, vertLength, x, y) {}

  Door(){};

  void ColorTransparent() { _body->setFillColor(Color::Transparent); }
  void ColourCyan() { _body->setFillColor(sf::Color::Cyan); }


  void ColorBlue() { _body->setFillColor(Color::Blue); }

  ~Door() {
    std::cout <<"Door is deleted" <<std::endl;
  }
};