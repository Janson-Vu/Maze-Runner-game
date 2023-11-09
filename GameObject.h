#pragma once
#include <SFML/Graphics.hpp>
using namespace sf;
#include <iostream>

class GameObject {
 protected:
  Shape* _body;

 public:
  GameObject() {}
  virtual void draw(RenderWindow* window) = 0;
  virtual int getX() = 0;
  virtual int getY() = 0;
  virtual ~GameObject(){
    //std::cout<<"Game object is deleted\n";
  };
};