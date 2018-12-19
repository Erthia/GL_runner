#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Element;
class Hero;

class Coin : public Element
{
  public:
    /// \default constructor of class Coin
    Coin();

    /// \constructor with parameters
    /// \param value to give each Coin a number to increment the hero's score
    Coin(const glm::vec3 &position, const unsigned int &value, const std::string &type="Coin");

    /// \brief method to retrieve the value of the Coin
    inline const int getValue() const {
    	return m_value;
    }

    /// \default destructor of our Coin
    ~Coin(); 

  /// \brief method to display the value of Coin's attributes
	void printElement() const;

  /// \method to check the specific behavior if the player collides with a Coin
  /// \takes an Hero instance as parameter and increments their score with the value of the Coin
	void collide(Hero &hero);

  private:
  unsigned int m_value; /*!< value of the Coin */

};
