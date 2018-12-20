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

bool Hero::scanArray(Element* (*list)[50][50], const char &movement) {

		
			int x=this->getX();
			int y=this->getY();
			int z=(this->getZ()+1);
			Element* tmpElt;
			Element* tmpElt2; // second obj to test when the hero jumps (from above)
			Hero tmpChar = *this;

		switch(movement) {

			case 'q' :
				x-=1;
				tmpElt = list[x][y][z];
				if(tmpElt != NULL)	{
					if(abs((this->getX()-1) - tmpElt->getX()) < 1) {
						if(abs(this->getY()- tmpElt->getY()) < 2)
						{
							if(abs((this->getZ()+1)- tmpElt->getZ()) < 1)
							{
								std::cout << "HALLELUJAH LEFT" << std::endl;
								//list[x][y][z]->collision(tmpChar);
								return true; 
							}
						}
					}
				}
				tmpElt2 = list[x][y+1][z];
				if(tmpElt2 != NULL)	{
					if(abs((this->getX()-1) - tmpElt2->getX()) < 1) {
						if(abs(this->getY()- tmpElt2->getY()) < 2)
						{
							if(abs((this->getZ()+1)- tmpElt2->getZ()) < 1)
							{
								std::cout << "COLLIDE LEFT" << std::endl;
								list[x][y+1][z]->collision(tmpChar);
								return true; 
							}
						}
					}
				}
				std::cout << "Can move" << std::endl;
				return false;
				break;

			case 'd' :
				x+=1;
				tmpElt = list[x][y][z];
				if(tmpElt != NULL)	{
					if(abs((this->getX()+1) - tmpElt->getX()) < 1) {
						if(abs(this->getY()- tmpElt->getY()) < 2)
						{
							if(abs((this->getZ()+1)- tmpElt->getZ()) < 1)
							{
								std::cout << "HALLELUJAH BELOW" << std::endl;
								list[x][y][z]->collision(tmpChar);
								return true; 
							}
						}
					}
				}
				tmpElt2 = list[x][y+1][z];
				if(tmpElt2 != NULL)	{
					if(abs((this->getX()+1) - tmpElt2->getX()) < 1) {
						if(abs(this->getY()- tmpElt2->getY()) < 2)
						{
							if(abs((this->getZ()+1)- tmpElt2->getZ()) < 1)
							{
								std::cout << "COLLIDE FROM ABOVE" << std::endl;
								list[x][y+1][z]->collision(tmpChar);
								return true; 
							}
						}
					}
				}
				std::cout << "Can move" << std::endl;
				return false;
				break;

			case 'z' :
				tmpElt = list[x][y+1][z];
				tmpElt2 = list[x][y+2][z];

				// check collision from 'below'
				if(tmpElt != NULL)	{
					if(abs((this->getX()) - tmpElt->getX()) < 1) {
						if((abs((this->getY()+1) - tmpElt->getY()) < 2))/// \our character's heighth is two
						{
							if(abs((this->getZ()+1)- tmpElt->getZ()) < 1)
							{
								std::cout << "Can't jump" << std::endl;
								//list[x][y][z]->collision(tmpChar);
								return true;

							}
						}
					}
				}
				// check ollision from 'above'
				if(tmpElt2 != NULL)	{
					if(abs((this->getX()) - tmpElt2->getX()) < 1) {
						if((abs((this->getY()+1) - tmpElt2->getY()) < 2))
						{
							if(abs((this->getZ()+1)- tmpElt2->getZ()) < 1)
							{
								std::cout << "Can't jump" << std::endl;
								return true;

							}
						}
					}
				}

				std::cout << "Can jump" << std::endl;
				return false;
				break;

			case 's' :
				tmpElt = list[x][y][z];
				if(tmpElt != NULL)	
				{
					//std::cout << " x : " << tmpElt->getX() << std::endl;
					//std::cout << " y : " << tmpElt->getY() << std::endl;
					//std::cout << " z : " << tmpElt->getZ() << std::endl;
					
					//list[x+1][y][z]->collision(tmpChar);
					//tmpElt->description();
					
					if(abs((this->getX()) - tmpElt->getX()) < 1) {
						if(abs(this->getY()- tmpElt->getY()) < 2) 
						{
							if(abs((this->getZ()+1)- tmpElt->getZ()) < 1)
							{
								std::cout << "Can't crawl" << std::endl;
								//list[x][y][z]->description();
								//list[x][y][z]->collision(tmpChar);
								return true;
							}
						}
					}
						
							return true;						
				}
				std::cout << "Can crawl" << std::endl;
				return false;
				break;
			
		}
		return false;
	}

bool Hero::checkCollide(motor_game::Map &map, const char &movement) {

			int x=this->getX();
			int y=this->getY();
			int z=(this->getZ()+1);
			Hero tmpChar = *this;

		switch(movement) {
			// move to the left
			case 'q' :
				x-=1;
				// we have to think about the fact that the hero is of height 2, so we have to check the collision from the lowest and highest y coordinates of our hero in case he collides two elements at the same time
				if(map.element(x, y, z) != nullptr || map.element(x, y+1, z) != nullptr){

					// test lowest y coordinate
					if(map.element(x, y, z) != nullptr)	{
						if(abs((this->getX()-1) - map.element(x, y, z)->getX()) < 1) {
							if(abs(this->getY()- map.element(x, y, z)->getY()) < 2)
							{
								if(abs((this->getZ()+1)- map.element(x, y, z)->getZ()) < 1)
								{
									std::cout << "COLLISION LEFT BAS" << std::endl;
									map.element(x, y, z)->collision(tmpChar);
								}
							}
						}
					}
					// test highest y coordinate
					if(map.element(x, y+1, z) != nullptr)	{
						if(abs((this->getX()-1) - map.element(x, y+1, z)->getX()) < 1) {
							if(abs(this->getY()- map.element(x, y+1, z)->getY()) < 2)
							{
								if(abs((this->getZ()+1)- map.element(x, y+1, z)->getZ()) < 1)
								{
									std::cout << "COLLISION LEFT HAUT" << std::endl;
									map.element(x, y+1, z)->collision(tmpChar);

								}
							}
						}
					}
				return true; 
			}
				std::cout << "Can move" << std::endl;
				return false;
				break;

			case 'd' :
				// move to the right
				x+=1;
				if(map.element(x, y, z) != nullptr || map.element(x, y+1, z) != nullptr){
					if(map.element(x, y, z) != nullptr)	{
						if(abs((this->getX()+1) - map.element(x, y, z)->getX()) < 1) {
							if(abs(this->getY()- map.element(x, y, z)->getY()) < 2)
							{
								if(abs((this->getZ()+1)- map.element(x, y, z)->getZ()) < 1)
								{
									std::cout << "COLLISION RIGHT BAS" << std::endl;
									map.element(x, y, z)->collision(tmpChar);
								}
							}
						}
					}
					if(map.element(x, y+1, z) != nullptr)	{
						if(abs((this->getX()+1) - map.element(x, y+1, z)->getX()) < 1) {
							if(abs(this->getY()- map.element(x, y+1, z)->getY()) < 2)
							{
								if(abs((this->getZ()+1)- map.element(x, y+1, z)->getZ()) < 1)
								{
									std::cout << "COLLISION RIGHT HAUT" << std::endl;
									map.element(x, y+1, z)->collision(tmpChar);

								}
							}
						}
					}
				return true; 
			}
				std::cout << "Can move" << std::endl;
				return false;
				break;

			case 'z' :
					if(map.element(x, y+1, z) != nullptr || map.element(x, y+2, z) != nullptr){
						// check collision from 'below'
						if(map.element(x, y+1, z) != nullptr)	{
							if(abs((this->getX()) - map.element(x, y+1, z)->getX()) < 1) {
								if(abs(this->getY()+1- map.element(x, y+1, z)->getY()) < 2)
								{
									if(abs((this->getZ()+1)- map.element(x, y+1, z)->getZ()) < 1)
									{
										std::cout << "COLLISION JUMP BAS" << std::endl;
										map.element(x, y+1, z)->collision(tmpChar);

									}
								}
							}
						}
						// check collision from 'above'
						if(map.element(x, y+2, z) != nullptr)	{
							if(abs((this->getX()) - map.element(x, y+2, z)->getX()) < 1) {
								if(abs(this->getY()+2- map.element(x, y+2, z)->getY()) < 2)
								{
									if(abs((this->getZ()+1)- map.element(x, y+2, z)->getZ()) < 1)
									{
										std::cout << "COLLISION JUMP HAUT" << std::endl;
										map.element(x, y+2, z)->collision(tmpChar);
									}
								}
							}
						}
						return true;
					}
					std::cout << "Can jump" << std::endl;
					return false;
					break;

			
		}
		return false;
	}



