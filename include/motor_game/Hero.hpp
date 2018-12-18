#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Character.hpp"

class Hero : public Character
{
  public:

    Hero(); /// default constructor
    Hero(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters



    
    virtual void printElement();
    ~Hero(); /// default destructor

        inline
  	void setScore(int const &inScore)
	  {
	    m_score += inScore;
	  }
	 inline
	int getScore() const
	 {
	   return m_score;
	}

  	private:
  	unsigned int m_score;

};
