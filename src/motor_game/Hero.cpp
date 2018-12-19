#include "../../include/motor_game/Hero.hpp"
#include <iostream>

Hero::Hero()
	:Character(glm::vec3(0), 0, "Hero"), m_score(0)
{}

Hero::Hero(const glm::vec3 &position, const unsigned int &speed, const std::string &type)
:Character(position, speed, type), m_score(0)
{}

Hero::~Hero()
{}

void Hero::printElement() const
{
	std::cout << "\nHERO INFORMATION :" << std::endl;
	Character::printElement();
	std::cout << "Score :" << getScore() << std::endl;
}

bool Hero::scanArray(Element (*list)[50][50], const char &movement) {

		/*list[x][y][z].printElement();
		this->printElement();

		if(checkCollision(list[x][y][z]) == true)
				std::cout << "HALLELUJAH" << std::endl;
		else std::cout << "LA MOOOOOOOORT PUTAIIN" << std::endl;*/
			int x=this->getX();
			int y=this->getY();
			int z=this->getZ()+1;
			PrintableElement tmpElt;
			Hero tmpChar = *this;
			list[x-1][y][z].collide(tmpChar);

		switch(movement) {
			case 'q' :
			x-=1;
			tmpElt = list[x][y][z];
			list[x][y][z].printElement();
			if(abs((this->getX()-1) - tmpElt.getX()) < 1) {
				if(abs(this->getY()- tmpElt.getY()) < 2) /// \our character's heighth is two
				{
					if(abs((this->getZ()+1)- tmpElt.getZ()) < 1)
					{
						std::cout << "HALLELUJAH" << std::endl;
						list[x][y][z].collide(tmpChar);
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





