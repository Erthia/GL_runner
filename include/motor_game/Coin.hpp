#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once


#include "Element.hpp"

class Coin : public Element
{
  public:

    Coin(); /// default constructor
    Coin(const glm::vec3 &position, const std::string &type, const unsigned int &value); /// constructor with parameters

    ~Coin(); /// default destructor

    virtual void printElement();


  protected:
  unsigned int m_value;

};
