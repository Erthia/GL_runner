#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "common.hpp"


//class Element;
class PrintableElement
{
  public:

    /// \default constructor of class PrintableElement
    /// \our class PrintableElement is only abstract
    PrintableElement(); 

     /// \constructor with parameters
    /// \param type : a string which will allow us to know what kind of PrintableElement we're dealing with
    PrintableElement(const glm::vec3 &position, const std::string &type); 

    /// \brief method allowing us to know the x, y and z coordinates of our object
  inline
    glm::vec3 getPosition() const
    {
      return m_position;
    }

  /// \brief method allowing us to know the x coordinate of our object
  inline
    float getX() const
      {
        return m_position.x;
      }

    /// \brief method allowing us to know the y coordinate of our object
  inline
    float getY() const
      {
        return m_position.y;
      }

    /// \brief method allowing us to know the z coordinate of our object
  inline
    float getZ() const
      {
        return m_position.z;
      }

  /// \brief method allowing us to know the type of our object
  inline
    std::string getType() const
    {
      return m_type;
    }
    
  /// \brief method to test the value of our object's attributes
  virtual void printElement();



  ~PrintableElement(); /// default destructor


  protected:
  glm::vec3 m_position; /*!< coordinates of the PrintableElement */
  std::string m_type; /*!< type of the PrintableElement */

};
