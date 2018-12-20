#include "../../include/motor_game/Wall.hpp"
#include <iostream>
#include <GL/glew.h>

Wall::Wall()
	:Element(glm::vec3(0), "Wall")
{}

Wall::Wall(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}


Wall::~Wall()
{}

void Wall::printElement() const
{
	std::cout << "\nWALL INFORMATION :" << std::endl;
	PrintableElement::printElement();
}

void Wall::collide(Hero &hero) {
	std::cout << "Can't walk through walls" << std::endl;
}


