#include "../../include/motor_game/Floor.hpp"
#include <iostream>
#include <GL/glew.h>

Floor::Floor()
	:Element()
{}

Floor::Floor(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}

Floor::~Floor()
{}

void Floor::printElement() 
{
	std::cout << "\nFLOOR INFORMATION :" << std::endl;
	Element::printElement();
}



