#include <iostream>
#include <string>
#include <GL/glew.h>



#pragma once

class Floor : public Element
{
  public:

    Floor(); /// default constructor
    Floor(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~Floor(); /// default destructor

    virtual void printElement();


};
