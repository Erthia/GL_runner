#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"
#include "Hero.hpp"

class Obstacle final : public Element
{
  public:
  	/// default constructor of class Obstacle
    Obstacle(); 
    /// constructor with parameters
    /// param type : obstacle by default
    Obstacle(const glm::vec3 &position, const std::string &type = "Obstacle"); 

     /// default destructor of our Floor
    ~Obstacle(); 

     /// \brief method to display the value of Obstacle's attributes
    void printElement() const;

    /// method to determine the behavior of an Obstacle when the player is colliding with it
    void collide(Hero *hero);


};
