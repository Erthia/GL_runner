#include <iostream>
#include <string>
#include <GL/glew.h>



#pragma once

class Element : public PrintableElement
{
  public:

    Element(); /// default constructor
    Element(const glm::vec3 &position, const std::string &type); /// constructor with parameters

    ~PrintableElement(); /// default destructor


  protected:

};
