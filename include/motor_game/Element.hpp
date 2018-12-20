#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "PrintableElement.hpp"
class Hero;

class Element : public PrintableElement
{
  public:
  	/// default constructor of class Element
  	/// our class Element is only abstract
    Element(); 

    /// constructor with parameters
    /// param type : a string which will allow us to know what kind of Element we're dealing with
    Element(const glm::vec3 &position, const std::string &type); 

    /// brief method to display the value of Element's attributes
    virtual void printElement() const;

    /// method to determine the behavior of an End when the player is colliding with it
    virtual void collide(Hero &hero);

    /// brief method to implement the polymorphism of the collide method for different inherited Element classes
    inline void collision(Hero &hero)
    {
      this->collide(hero);
    }

    /// default destructor of our Element
    ~Element(); 

};
