#include <iostream>
#include <string>

#pragma once


#include "Element.hpp"

class Obstacle : public Element
{
  public:

    Obstacle(); /// default constructor
    Obstacle(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Obstacle(); /// default destructor

    virtual void printElement();


};
