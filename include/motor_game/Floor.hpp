#pragma once

#include <iostream>
#include <string>
class Element;


// TO ERASE ???? we don't have to check floor collision
class Floor : public Element
{
  public:
  	/// \default constructor of class Floor
    Floor(); 
    Floor(const glm::vec3 &position, const std::string &type = "Floor"); /// constructor with parameters

	/// \brief method to test the value of Floor's attributes
    void printElement() const;

     /// default destructor of our Floor
    ~Floor(); 


};
