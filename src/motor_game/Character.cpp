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
	PrintableElement::printElement();
	std::cout << "Speed : " << m_speed << std::endl;
}


void Character::moveLeft()
{
	std::cout << m_type << " moved to the left." << std::endl;
	m_position.y -= 1;
}

void Character::moveRight()
{
	std::cout << m_type << " moved to the right." << std::endl;
	m_position.y += 1;
}

void Character::jump()
{
	std::cout << m_type << " jumped." << std::endl;
	m_position.z += 1; /// ???????
}


bool Character::checkCollision(const PrintableElement &a, const PrintableElement &b){
	if(abs(a.getX()- b.getX()) < 2) /// \2 is for size(a) + size(b), here we have two cubes with size of 1*1
		if(abs(a.getY()- b.getY()) < 2)
			if(abs(a.getX()- b.getX()) < 2)
				return true;
	return false;
}




// gauche/droite : x, haut : y, profondeur : z
