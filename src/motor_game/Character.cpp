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

void Character::run(const int &axe)
{

		if (axe == 0)
		{
			m_position.x += m_speed;
		}
		if (axe == 1)
		{
			std::cout<<"ON NE PEUT PAS COURIR AU PLAFOND"<<std::endl;
		}
}

void Character::moveLeft()
{
//	std::cout << m_type << " moved to the left." << std::endl;
	m_position.x -= 1;
}

void Character::moveLeft(const int &axe)
{
//	std::cout << m_type << " moved to the left." << std::endl;
	switch ((axe)) {
		case 2:
			m_position.z -= 1;
		default:
			moveLeft();
	}
}

void Character::moveRight()
{
//	std::cout << m_type << " moved to the right." << std::endl;
	m_position.x += 1;
}
void Character::moveRight(const int &axe)
{
//	std::cout << m_type << " moved to the left." << std::endl;
	switch ((axe)) {
		case 2:
			m_position.z += 1;
		default:
			moveRight();
	}
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
	m_position.y -= 1; // ???????
}

void Character::translate(const float &x, const float &z)
{
	glm::mat4 translationMatrix = glm::translate(glm::mat4(1),glm::vec3(-x,0,-z));
	glm::vec4 newPosition = translationMatrix*glm::vec4(m_position,1);
	m_position = glm::vec3(newPosition);
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
