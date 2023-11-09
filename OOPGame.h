#pragma once
#include <iostream>

class OOPGame{
  public:
    OOPGame(){}
    virtual void run(){
      std::cout << "Begin running game." << std::endl;
    }
    virtual ~OOPGame(){
      std::cout<<"Game is deleted"<<std::endl;
    }
};
