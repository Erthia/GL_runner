#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Character.hpp"

class Hero : public Character
{
 public:
  	/// \default constructor of class Hero
    Hero(); 

    /// \constructor with parameters
    Hero(const glm::vec3 &position, const std::string &type, const unsigned int &speed); 
   
   	/// \brief method to test the value of Hero's attributes
    void printElement() const;

    /// \default destructor of our Hero
    ~Hero(); 

	/// \brief method to increment the score of Hero
	/// \takes a parameter to pass the value to add to the score
	inline void setScore(int const &inScore){
	    m_score += inScore;
	 }

	/// \brief method to retrieve the score of Hero
	inline int getScore() const{
		return m_score;
	}

  	private:
  	unsigned int m_score; /*!< score of Hero */

};
