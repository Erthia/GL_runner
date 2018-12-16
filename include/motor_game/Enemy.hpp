#include <iostream>
#include <string>
#include <GL/glew.h>



#pragma once

class Enemy : public Character
{
  public:

    Enemy(); /// default constructor
    Enemy(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters
    void killHero();
   

    virtual void printElement();
    ~Enemy(); /// default destructor


  protected:


};
