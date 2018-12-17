#include "../../include/motor_game/Coin.hpp"
#include <iostream>
#include <GL/glew.h>

Coin::Coin()
	:Element(), m_value(0)
{}

Coin::Coin(const glm::vec3 &position, const std::string &type, const unsigned int &value)
:Element(position, type), m_value(value)
{}

Coin::~Coin()
{}

void Coin::collide(User &hero){
	hero.setScore(this->getScore());
	// delete coin ?????
}

void Coin::printElement() 
{
	std::cout << "\nCOIN INFORMATION :" << std::endl;
	Element::printElement();
	std::cout << "Value : " << m_value << std::endl;
}



