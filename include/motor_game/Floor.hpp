#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"


// TO ERASE ???? we don't have to check floor collision
class Floor : public Element
{
  public:
  	/// default constructor of class Floor
    Floor(); 


    Floor(const glm::vec3 &position, const std::string &type = "Floor");

	/// brief method to display the value of Floor's attributes
    void printElement() const;

     /// default destructor of our Floor
    ~Floor(); 

// TO ADD :  collide ??

};
