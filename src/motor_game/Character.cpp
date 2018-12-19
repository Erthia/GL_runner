#include "../../include/motor_game/Character.hpp"
#include <iostream>



Character::Character()
	:PrintableElement(glm::vec3(0), "Character"), m_speed(0)
{}

Character::Character(const glm::vec3 &position, const unsigned int &speed, const std::string &type)
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
	std::cout << m_type << " ran." << std::endl;
	m_position.z += m_speed; //???????
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
	    	//(*it).collide(this); /// \problem : parameter must be a user and not a character 
	    	std::cout << "ok" << std::endl;
	    }
	    	
	}

}

/*void Character::scanVec(std::vector<std::vector<std::vector<Element>>> &vecList, const char &movement) {
		std::cout << "NON AU DEPLACEMENT A DROITE" << std::endl;
	}*/

bool Character::scanArray(Element (*list)[50][50], const char &movement) {

		/*list[x][y][z].printElement();
		this->printElement();

		if(checkCollision(list[x][y][z]) == true)
				std::cout << "HALLELUJAH" << std::endl;
		else std::cout << "LA MOOOOOOOORT PUTAIIN" << std::endl;*/
			int x=this->getX();
			int y=this->getY();
			int z=this->getZ()+1;
			PrintableElement tmpElt;

		switch(movement) {
			case 'q' :
			x-=1;
			tmpElt = list[x][y][z];
			if(abs((this->getX()-1) - tmpElt.getX()) < 1) {
				if(abs(this->getY()- tmpElt.getY()) < 2) /// \our character's heighth is two
				{
					if(abs((this->getZ()+1)- tmpElt.getZ()) < 1)
					{
						std::cout << "HALLELUJAH" << std::endl;
						return true;
					}}}
			else {
				std::cout << "BOOOOOUH" << std::endl;
				return false;
			}
			break;
			/*
			if(checkCollisionMovement(list[x-1][y][z+1], movement) == true)
				std::cout << "Collision scanArray !" << std::endl;*/
			case 'd' :
			x+=1;
				tmpElt = list[x][y][z];
				if(abs((this->getX()+1) - tmpElt.getX()) < 1) {
					if(abs(this->getY()- tmpElt.getY()) < 2) /// \our character's heighth is two
					{
						if(abs((this->getZ()+1)- tmpElt.getZ()) < 1)
						{
							std::cout << "HALLELUJAH" << std::endl;
							return true;
						}}}
				else {
					std::cout << "BOOOOOUH" << std::endl;
					return false;
				}
				break;
			
		}
		return false;

		//list[x][y][z+1]
		//std::cout << "NON AU DEPLACEMENT A DROITE" << std::endl;
	}

// gauche/droite : x, haut : y, profondeur : z
