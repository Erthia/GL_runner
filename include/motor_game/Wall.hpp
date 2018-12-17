#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once

#include "Element.hpp"

class Wall : public Element
{
  public:

    Wall(); /// default constructor
    Wall(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Wall(); /// default destructor

    void printElement();
    void collide(User *hero);


};
