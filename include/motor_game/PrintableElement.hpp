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

    /// \brief default constructor of class PrintableElement
    /// \brief our class PrintableElement is only abstract
    PrintableElement(); 

     /// \brief constructor with parameters
    /// \param type : a string which will allow us to know what kind of PrintableElement we're dealing with
    PrintableElement(const glm::vec3 &position, const std::string &type); 

  /// \brief method allowing us to know the x, y and z coordinates of our object
  inline glm::vec3 getPosition() const {
      return m_position;
  }
  
  /// \brief setter of position
  inline void setPosition(glm::vec3 pos){
      m_position=pos;
  }

  /// \brief method allowing us to know the x coordinate of PrintableElement
  inline float getX() const {
      return m_position.x;
  }

  /// \brief method allowing us to know the y coordinate of PrintableElement
  inline float getY() const {
      return m_position.y;
  }

  /// \brief method allowing us to know the z coordinate of PrintableElement
  inline float getZ() const {
      return m_position.z;
    }

  /// \brief method allowing us to know the type of PrintableElement
  inline std::string getType() const {
      return m_type;
  }
    
  /// \brief method to test the value of PrintableElement's attributes
  virtual void printElement() const;


  /// \brief default destructor of our PrintableElement 
  ~PrintableElement(); 


  protected:
  glm::vec3 m_position; /*!< coordinates of the PrintableElement */
  std::string m_type; /*!< type of the PrintableElement */

};
