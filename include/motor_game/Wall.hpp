#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"
#include "Hero.hpp"

class Wall : public Element
{
  public:
  	/// \default constructor of class Wall
    Wall();

    /// \constructor with parameters
    Wall(const glm::vec3 &position, const std::string &type);

    /// default destructor of our Wall
    ~Wall(); 

    /// \brief method to test the value of Wall's attributes
    void printElement() const;

    /// \method to check the specific behavior if the player collides with a Coin
  	/// \takes an Hero instance as parameter. the hero doesn't die if they touches a wall, it just prevents them from moving where the wall is.
    void collide(Hero *hero);


};
