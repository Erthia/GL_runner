#include "../../include/motor_game/Coin.hpp"
#include <iostream>
#include <GL/glew.h>

Coin::Coin()
	:Element(glm::vec3(0), "Coin"), m_value(0)
{}

Coin::Coin(const glm::vec3 &position, const unsigned int &value, const std::string &type)
:Element(position, type), m_value(value)
{}

Coin::~Coin()
{}

void Coin::collide(Hero *hero){
	hero->setScore(this->getValue());
	std::cout << "\nTEST COLLIDE DE MON SUPER COIIIIIIN HELLO " << std::endl;
	// delete coin ?????
}

void Coin::printElement() const
{
	std::cout << "\nCOIN INFORMATION :" << std::endl;
	PrintableElement::printElement();
	std::cout << "Value : " << m_value << std::endl;
}



