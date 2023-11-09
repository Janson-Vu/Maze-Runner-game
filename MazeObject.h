#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

#include "GameObject.h"

class MazeObject : public GameObject {
 protected:
  int _vertLength;
  int _hortLength;

 public:
  MazeObject(int hortLength, int vertLength, int x, int y) {
    _body = new RectangleShape(Vector2f(hortLength, vertLength));
    _body->setPosition(Vector2f(x, y));
    _body->setFillColor(sf::Color::Transparent);
    _vertLength = vertLength;
    _hortLength = hortLength;
  }

  MazeObject(){};

  void draw(RenderWindow* window) { window->draw(*_body); }

  int getX() { return _body->getPosition().x; }
  int getY() { return _body->getPosition().y; }
  int getVert() { return _vertLength; }
  int getHorzt() { return _hortLength; }

  virtual void ColorTransparent() = 0;
  virtual void ColourCyan() = 0;

  ~MazeObject() { 
    delete _body; 
    std::cout <<" Maze Object is deleted" <<std::endl;
  }
};