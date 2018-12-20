#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Character.hpp"

#include "Element.hpp"
#include "Map.hpp"

class Hero : public Character
{
 public:
  	/// default constructor of class Hero
    Hero(); 

    /// constructor with parameters
    Hero(const glm::vec3 &position, const unsigned int &speed, const std::string &type = "Hero"); 
   
   	/// brief method to display the value of Hero's attributes
    void printElement() const;

    /// default destructor of our Hero
    ~Hero(); 

	/// brief method to increment the score of Hero
	/// takes a parameter to pass the value to add to the score
	inline void setScore(int const &inScore){
	    m_score += inScore;
	 }

	/// brief method to retrieve the score of Hero
	inline int getScore() const{
		return m_score;
	}

  /// method called when the hero tries to move
  /// this method checks if there is an element where the Hero wants to move
  /// then uses the collide methods to do something according to what type of element we're dealing with
    bool scanArray(Element* (*list)[50][50], const char &movement);

    bool checkCollide(motor_game::Map &map, const char &movement);

  	private:
  	unsigned int m_score; /*!< score of Hero */

};

