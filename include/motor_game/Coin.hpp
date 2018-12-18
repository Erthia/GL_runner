#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>


#include "Element.hpp"
#include "Hero.hpp"

class Coin : public Element
{
  public:

    Coin(); /// default constructor
    Coin(const glm::vec3 &position, const std::string &type, const unsigned int &value); /// constructor with parameters
    inline
    const int getScore(){
    	return m_value;
    }
    ~Coin(); /// default destructor

	void printElement();
	void collide(Hero *hero);


  protected:
  unsigned int m_value;

};
