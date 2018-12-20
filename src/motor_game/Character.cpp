#include "../../include/motor_game/Character.hpp"
#include <iostream>



Character::Character()
	:PrintableElement(glm::vec3(0), "Character"), m_speed(0)
{}

Character::Character(const glm::vec3 &position, const unsigned int &speed, const std::string &type)
:PrintableElement(position, type), m_speed(speed)
{}

/*Character::~Character()
{}*/

void Character::printElement() const
{
	PrintableElement::printElement();
	std::cout << "Speed : " << m_speed << std::endl;
}

void Character::run()
{
	std::cout << m_type << " ran." << std::endl;
	m_position.z += m_speed; //???????
}

void Character::moveLeft()
{
	this->run();
	std::cout << m_type << " moved to the left." << std::endl;
	m_position.x -= 1;
}

void Character::moveRight()
{
	this->run();
	std::cout << m_type << " moved to the right." << std::endl;
	m_position.x += 1;
}

void Character::up()
{
	this->run();
	std::cout << m_type << " jumped." << std::endl;
	m_position.y += 1; // ???????
	this->run();
}

// à gérer avec le moteur de rendu et un scale particulier ??????? 
void Character::down()
{
	this->run();
	std::cout << m_type << " crawled." << std::endl;
	m_position.y -= 0.5; // ???????
}


// A VOIR EN FONCTION DE LA GESTION DES ENNEMIS : si on l'utilise, transformer les autre en virtual
void Character::move(const char &movement)
{
	switch(movement)
	{
		case 'q' :
			this->moveLeft();
			break;
		case 'd' :
			this->moveRight();
			break;
		case 'z' :
			this->up();
			break;
		case 's' :
			this->down();
		default :
		break;

	}
}

// gauche/droite : x, haut : y, profondeur : z
