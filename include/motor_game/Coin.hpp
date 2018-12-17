#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once


#include "Element.hpp"
#include "User.hpp"

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
	void collide(User *hero);


  protected:
  unsigned int m_value;

};
