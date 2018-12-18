#include "../../include/motor_game/Enemy.hpp"
#include <iostream>
#include <GL/glew.h>

Enemy::Enemy()
	:Character(glm::vec3(0), "Enemy", 0)
{}

Enemy::Enemy(const glm::vec3 &position, const std::string &type, const unsigned int &speed)
:Character(position, type, speed)
{}

Enemy::~Enemy()
{}

void Enemy::printElement() const {
	std::cout << "\nENEMY INFORMATION :" << std::endl;
	Character::printElement();
}

void Enemy::killHero(){}





