#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "common.hpp"

#pragma once

class Element; 
class PrintableElement
{
  public:

    PrintableElement(); /// default constructor
    PrintableElement(const glm::vec3 &position, const std::string &type); /// constructor with parameters
    inline
    glm::vec3 getPosition() const
    {
      return m_position;
    }

    inline
    std::string getType() const
    {
      return m_type;
    }

  virtual void printElement();



    ~PrintableElement(); /// default destructor


  protected:
  glm::vec3 m_position;
  std::string m_type;

};
