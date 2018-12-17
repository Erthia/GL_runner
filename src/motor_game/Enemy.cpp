#include "../../include/motor_game/Enemy.hpp"
#include <iostream>
#include <GL/glew.h>

Enemy::Enemy()
	:Character()
{}

Enemy::Enemy(const glm::vec3 &position, const std::string &type, const unsigned int &speed)
:Character(position, type, speed)
{}

Enemy::~Enemy()
{}

void Enemy::printElement() 
{
	std::cout << "\nENEMY INFORMATION :" << std::endl;
	Character::printElement();
}

void Enemy::killHero(){}





