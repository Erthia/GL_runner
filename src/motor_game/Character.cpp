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

void Character::run()
{
	std::cout << m_type << " ran." << std::endl;
	m_position.z += m_speed; /// ???????
}

void Character::moveLeft()
{
	std::cout << m_type << " moved to the left." << std::endl;
	m_position.x -= 1;
}

void Character::moveRight()
{
	std::cout << m_type << " moved to the right." << std::endl;
	m_position.x += 1;
}

void Character::up()
{
	std::cout << m_type << " jumped." << std::endl;
	m_position.y += 1; /// ???????
}

/// à gérer avec le moteur de rendu et un scale particulier ??????? 
void Character::down()
{
	std::cout << m_type << " crawled." << std::endl;
	m_position.y -= 0.5; /// ???????
}


bool Character::checkCollision(const PrintableElement &b)
{
	if(abs(this->getX()- b.getX()) < 1) 
		if(abs(this->getY()- b.getY()) < 2) /// \our character's heighth is two
			if(abs((this->getZ()+1)- b.getZ()) < 1)
				return true;
	return false;
}

bool Character::checkCollisionMovement(const PrintableElement &b, const char &movement){
	switch(movement) {
		case 'q' : 
			if(abs((this->getX()-1) - b.getX()) < 1) 
				if(abs(this->getY()- b.getY()) < 2) /// \our character's heighth is two
					if(abs((this->getZ()+1)- b.getZ()) < 1)
						return true;
			return false;
			break;
		case 'd' : 
			if(abs((this->getX()+1) - b.getX()) < 1) 
				if(abs(this->getY()- b.getY()) < 2) /// \our character's heighth is two
					if(abs((this->getZ()+1)- b.getZ()) < 1)
						return true;
			return false;
			break;
		case 'z' :
			if(abs(this->getX() - b.getX()) < 1) 
				if(abs((this->getY()+1)- b.getY()) < 2) /// \our character's heighth is two
					if(abs((this->getZ()+1)- b.getZ()) < 1)
						return true;
			return false;

		case 's' :
			if(abs(this->getX() - b.getX()) < 1) 
				if(abs(this->getY()- b.getY()) < 1) /// \our character's heighth is two
					if(abs((this->getZ()+1)- b.getZ()) < 1)
						return true;
			return false;
			break;


	}
		return false;
}

void Character::scanList(std::list<Element> &list, const char &movement){
	std::list<Element>::iterator it;
	for (std::list<Element>::iterator it = list.begin(); it != list.end(); ++it){
	    if(checkCollisionMovement(*it, movement) == true || checkCollision(*it) == true){
	    	//return &(*it); appelle collide(this, *it, movement) de *it
	    	*it.collide(this);
	    	std::cout << "ok" << std::endl;
	    }
	    	
	}
}





// gauche/droite : x, haut : y, profondeur : z
