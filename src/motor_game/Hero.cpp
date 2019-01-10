#include "../../include/motor_game/Hero.hpp"
#include <iostream>

Hero::Hero()
	:Character(glm::vec3(0), 0, "Hero"), m_score(0)
{}

Hero::Hero(const glm::vec3 &position, const unsigned int &speed, const std::string &type)
:Character(position, speed, type), m_score(0)
{}

Hero::~Hero()
{

}

void Hero::printElement() const
{
	std::cout << "\nHERO INFORMATION :" << std::endl;
	Character::printElement();
	std::cout << "Score :" << getScore() << std::endl;
}

bool Hero::checkCollision(const Element &b)
{
	if(abs(this->getX()- b.getX()) < 1) 
		if(abs(this->getY()- b.getY()) < 2) /// \our character's heighth is two
			if(abs((this->getZ())- b.getZ()) < 1)
				return true;
	return false;
}


bool Hero::checkCollide(motor_game::Map &map, const char &movement) {

			int x=this->getX();
			int y=this->getY();
			int z=(this->getZ()+1);

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
									map.element(x, y, z)->collision(this);
									if(map.element(x, y, z)->getType() == "Coin")
										this->moveLeft();										
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
									map.element(x, y+1, z)->collision(this);
									if(map.element(x, y+1, z)->getType() == "Coin")
										this->moveLeft();
								}
							}
						}
					}
				return true; 
				}	
				std::cout << "Can move" << std::endl;
				this->moveLeft();
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
									map.element(x, y, z)->collision(this);
									if(map.element(x, y, z)->getType() == "Coin")
										this->moveRight();
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
									map.element(x, y+1, z)->collision(this);
									if(map.element(x, y+1, z)->getType() == "Coin")
										this->moveRight();

								}
							}
						}
					}
				return true; 
				}
				std::cout << "Can move" << std::endl;
				this->moveRight();
				return false;
				break;

			case 'z' :
				// jvoid setEnemy(const Enemy *enemy);ump
				if(map.element(x, y+1, z) != nullptr || map.element(x, y+2, z) != nullptr){
					// check collision from 'below'
					if(map.element(x, y+1, z) != nullptr)	{
						if(abs((this->getX()) - map.element(x, y+1, z)->getX()) < 1) {
							if(abs(this->getY()+1- map.element(x, y+1, z)->getY()) < 2)
							{
								if(abs((this->getZ()+1)- map.element(x, y+1, z)->getZ()) < 1)
								{
									std::cout << "COLLISION JUMP BAS" << std::endl;
									map.element(x, y+1, z)->collision(this);
									if(map.element(x, y+1, z)->getType() == "Coin")
										this->up();

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
									map.element(x, y+2, z)->collision(this);
									if(map.element(x, y+2, z)->getType() == "Coin")
										this->up();
								}
							}
						}
					}
				return true;
				}
				std::cout << "Can jump" << std::endl;				
				this->up();
				return false;
				break;

			case 's' :
				// crawl
				if(map.element(x, y, z) != nullptr)	{
					if(abs((this->getX()) - map.element(x, y, z)->getX()) < 1) {
						if(abs(this->getY()+1- map.element(x, y, z)->getY()) < 2)
						{
							if(abs((this->getZ()+1)- map.element(x, y, z)->getZ()) < 1)
							{
								std::cout << "COLLISION CRAWL BAS" << std::endl;
								map.element(x, y, z)->collision(this);
								if(map.element(x, y, z)->getType() == "Coin")
										this->down();

							}
						}
					}
				return true;
				}
				std::cout << "Can crawl" << std::endl;
				this->down();
				return false;
				break;
			default : return false;
	}
	return false;
}
	
void Hero::run(){
    
    if(m_timeNextMov.size() !=0){
        if(m_timeNextMov.front()<=0){
            switch(m_nextMov.front()){
                case 'u' : m_enemy->up(); break;
                case 'd' : m_enemy->down(); break;
                case 'l' : m_enemy->moveLeft(); break;
                case 'r' : m_enemy->moveRight(); break;
                default : assert(false); break;
            }
            m_timeNextMov.pop_back();
            m_nextMov.pop();
        }
        for(std::list<int>::iterator it = m_timeNextMov.begin() ; it != m_timeNextMov.end(); it++)
            *it-=m_speed;
    }
    
    Character::run();
    m_enemy->run();
}

  
void Hero::up(){
    Character::up();
    m_timeNextMov.push_back(this->getZ() - m_enemy->getZ());
    m_nextMov.push('u');
}

 
void Hero::down(){
    Character::down();
    m_timeNextMov.push_back(this->getZ() - m_enemy->getZ());
    m_nextMov.push('d');
}


void Hero::moveLeft(){
    Character::moveLeft();
    m_timeNextMov.push_back(this->getZ() - m_enemy->getZ());
    m_nextMov.push('l');
}


void Hero::moveRight(){
    Character::moveRight();
    m_timeNextMov.push_back(this->getZ() - m_enemy->getZ());
    m_nextMov.push('r');
}


