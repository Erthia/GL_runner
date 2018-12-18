#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>


#include "PrintableElement.hpp"

class Element : public PrintableElement
{
  public:
  	/// \default constructor of class Element
  	/// \our class Element is only abstract
    Element(); 

    /// \constructor with parameters
    /// \param type : a string which will allow us to know what kind of Element we're dealing with
    Element(const glm::vec3 &position, const std::string &type); 


    /// \default destructor of our Element
    ~Element(); 


  protected:

};
