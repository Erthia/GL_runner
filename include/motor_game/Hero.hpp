#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once

#include "Character.hpp"

class Hero : public Character
{
  public:

    Hero(); /// default constructor
    Hero(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters
    
    virtual void printElement();
    ~Hero(); /// default destructor


  protected:

};
