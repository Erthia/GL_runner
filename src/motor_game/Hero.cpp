#include "../../include/motor_game/Hero.hpp"
#include <iostream>

Hero::Hero()
	:Character(glm::vec3(0), "Hero", 0), m_score(0)
{}

Hero::Hero(const glm::vec3 &position, const std::string &type, const unsigned int &speed)
:Character(position, type, speed), m_score(0)
{}

Hero::~Hero()
{}

void Hero::printElement() const
{
	std::cout << "\nHERO INFORMATION :" << std::endl;
	Character::printElement();
	std::cout << "Score :" << getScore() << std::endl;
}





