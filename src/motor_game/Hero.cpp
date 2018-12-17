#include "../../include/motor_game/Hero.hpp"
#include <iostream>

Hero::Hero()
	:Character()
{}

Hero::Hero(const glm::vec3 &position, const std::string &type, const unsigned int &speed)
:Character(position, type, speed)
{}

Hero::~Hero()
{}

void Hero::printElement() 
{
	std::cout << "\nHERO INFORMATION :" << std::endl;
	Character::printElement();
}





