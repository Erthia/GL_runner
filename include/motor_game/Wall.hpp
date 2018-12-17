#include <iostream>
#include <string>
#include <GL/glew.h>



#pragma once

class Wall : public Element
{
  public:

    Wall(); /// default constructor
    Wall(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Wall(); /// default destructor

    virtual void printElement();


};
