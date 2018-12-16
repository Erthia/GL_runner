#include "../../include/motor_game/Character.hpp"
#include <iostream>
#include <GL/glew.h>

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
	std::cout << "speed : " << m_speed << std::endl;
}


void Character::moveLeft()
{
	_position.y += 1;
}

void Character::moveRight()
{
	_position.y -= 1;
}

void Character::jump()
{
	_position.y += 1; /// ???????
}

bool Character::checkCollision(){}





