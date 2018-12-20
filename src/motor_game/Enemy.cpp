#include "../../include/motor_game/Enemy.hpp"
#include <iostream>
#include <GL/glew.h>

Enemy::Enemy()
	:Character(glm::vec3(0), 0, "Enemy")
{}

Enemy::Enemy(const glm::vec3 &position, const unsigned int &speed, const std::string &type)
:Character(position, speed, type)
{}

Enemy::~Enemy()
{
	
}

void Enemy::printElement() const {
	std::cout << "\nENEMY INFORMATION :" << std::endl;
	Character::printElement();
}

void Enemy::killHero(){}





