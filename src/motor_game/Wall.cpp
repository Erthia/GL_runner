#include "../../include/motor_game/Wall.hpp"
#include <iostream>
#include <GL/glew.h>

Wall::Wall()
	:Element()
{}

Wall::Wall(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}


Wall::~Wall()
{}

void Wall::printElement() 
{
	std::cout << "\nWALL INFORMATION :" << std::endl;
	Element::printElement();
}

void Wall::collide(User &hero){
	std::cout << "Can't walk through walls" << std::endl;
}


