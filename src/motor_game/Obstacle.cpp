#include "../../include/motor_game/Obstacle.hpp"
#include <iostream>
#include <GL/glew.h>

Obstacle::Obstacle()
	:Element()
{}

Obstacle::Obstacle(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}

Obstacle::~Obstacle()
{}

void Obstacle::printElement() 
{
	std::cout << "\nOBSTACLE INFORMATION :" << std::endl;
	PrintableElement::printElement();
}



