#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

 #include "Character.hpp"
#include "Hero.hpp"

class Enemy : public Character
{
  public:
 	/// default constructor of class Enemy
    Enemy();

	/// constructor with parameters
    /// param type : enemy by default
    Enemy(const glm::vec3 &position, const float &speed, const std::string &type="Enemy"); /// constructor with parameters

    // A VOIR SI ON GARDE : fonction appelée dans la fonction collide ???
    void killHero();

    /// method to determine the behavior of an Enemy when the player is colliding with it
    void collide(Hero &hero);

    /// brief method to display the value of Enemy's attributes
    void printElement() const;

	/// default destructor of our Enemy
    ~Enemy();


  protected:


};
