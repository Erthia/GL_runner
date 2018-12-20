#include "../../include/motor_game/Character.hpp"
#include <iostream>



Character::Character()
	:PrintableElement(glm::vec3(0), "Character"), m_speed(0)
{}

Character::Character(const glm::vec3 &position, const float &speed, const std::string &type)
:PrintableElement(position, type), m_speed(speed)
{}

Character::~Character()
{}

void Character::printElement() const
{
	PrintableElement::printElement();
	std::cout << "Speed : " << m_speed << std::endl;
}

void Character::run()
{
	//std::cout << m_type << " ran." << std::endl;
	m_position.z += m_speed;
}

void Character::moveLeft()
{
//	std::cout << m_type << " moved to the left." << std::endl;
	m_position.x -= 1;
}

void Character::moveRight()
{
//	std::cout << m_type << " moved to the right." << std::endl;
	m_position.x += 1;
}

void Character::up()
{
	std::cout << m_type << " jumped." << std::endl;
	m_position.y += 1; // ???????
}

// à gérer avec le moteur de rendu et un scale particulier ???????
void Character::down()
{
	std::cout << m_type << " crawled." << std::endl;
	m_position.y -= 0.5; // ???????
}


bool Character::checkCollision(const PrintableElement &b)
{
	if(abs(this->getX()- b.getX()) < 1)
		if(abs(this->getY()- b.getY()) < 2) /// \our character's heighth is two
			if(abs((this->getZ())- b.getZ()) < 1)
				return true;
	return false;

}


// gauche/droite : x, haut : y, profondeur : z
