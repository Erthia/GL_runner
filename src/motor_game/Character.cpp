#include "../../include/motor_game/Character.hpp"
#include <iostream>

Character::Character()
	:PrintableElement()
{}

Character::Character(const glm::vec3 &position, const std::string &type, const unsigned int &speed)
:PrintableElement(position, type), m_speed(speed)
{}

Character::~Character()
{}

void Character::printElement() 
{
	std::cout << "\nCHARACTER INFORMATION :" << std::endl;
	PrintableElement::printElement();
	std::cout << "Speed : " << m_speed << std::endl;
}


void Character::moveLeft()
{
	m_position.y += 1;
}

void Character::moveRight()
{
	m_position.y -= 1;
}

void Character::jump()
{
	m_position.y += 1; /// ???????
}

bool Character::checkCollision(){}





