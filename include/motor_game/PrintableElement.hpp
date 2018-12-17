#include <iostream>
#include <string>
#include <GL/glew.h>


#pragma once

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



  virtual void printElement(),



    ~PrintableElement(); /// default destructor


  protected:

  std::string m_type;
  glm::vec3 m_position;
};
