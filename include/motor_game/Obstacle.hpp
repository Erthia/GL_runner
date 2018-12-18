#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"
#include "Hero.hpp"


class Obstacle : public Element
{
  public:

    Obstacle(); /// default constructor
    Obstacle(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Obstacle(); /// default destructor

    void printElement() const;
    void collide(Hero *hero);


};
