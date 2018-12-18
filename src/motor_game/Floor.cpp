#include "../../include/motor_game/Floor.hpp"
#include <iostream>
#include <GL/glew.h>

Floor::Floor()
	:Element(glm::vec3(0), "Floor")
{}

Floor::Floor(const glm::vec3 &position, const std::string &type)
:Element(position, type)
{}

Floor::~Floor()
{}

void Floor::printElement() const
{
	std::cout << "\nFLOOR INFORMATION :" << std::endl;
	PrintableElement::printElement();
}



