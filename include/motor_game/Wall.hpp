#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"
#include "Hero.hpp"

class Wall : public Element
{
  public:

    Wall(); /// default constructor
    Wall(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Wall(); /// default destructor

    void printElement();
    void collide(Hero *hero);


};
