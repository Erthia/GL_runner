#include "../../include/motor_game/Obstacle.hpp"
#include <iostream>
#include <GL/glew.h>

Obstacle::Obstacle()
	:Element(glm::vec3(0), "Ostacle")
{}

Obstacle::Obstacle(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}

Obstacle::~Obstacle()
{}

void Obstacle::printElement() const
{
	std::cout << "\nOBSTACLE INFORMATION :" << std::endl;
	PrintableElement::printElement();
}

void Obstacle::collide(Hero *hero){
	std::cout << "Can't walk through obstacle, you're DEAD" << std::endl;
	delete hero;
	//delete hero;
}





