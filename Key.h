#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

#include "MazeObject.h"

class Key : public MazeObject {
 public:
  Key(int hortLength, int vertLength, int x, int y)
      : MazeObject(hortLength, vertLength, x, y) {}

  Key() {}

  void ColorTransparent() { _body->setFillColor(Color::Transparent); }

  void ColorGreen() { _body->setFillColor(Color::Green); }
  void ColourCyan() { _body->setFillColor(sf::Color::Cyan); }


  ~Key() { std::cout << "Key is deleted" << std::endl; }
};