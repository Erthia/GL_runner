#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once


#include "PrintableElement.hpp"

class Element : public PrintableElement
{
  public:

    Element(); /// default constructor
    Element(const glm::vec3 &position, const std::string &type); /// constructor with parameters
    virtual void printElement();
    ~Element(); /// default destructor


  protected:

};
