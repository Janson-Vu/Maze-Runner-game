#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;

#include "MazeObject.h"

class Path : public MazeObject {
 public:
  Path(int hortLength, int vertLength, int x, int y)
      : MazeObject(hortLength, vertLength, x, y) {}

  Path(){};

  void ColourCyan() { _body->setFillColor(sf::Color::Cyan); }

  void ColorTransparent() { _body->setFillColor(sf::Color::Transparent); }

  ~Path() {}
};