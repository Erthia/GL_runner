#include "../../include/motor_game/PrintableElement.hpp"
#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "common.hpp"

PrintableElement::PrintableElement()
	//:m_position(glm::vec3(0), m_type("Unknown"))
{}

PrintableElement::PrintableElement(const glm::vec3 &position, const std::string &type)
:m_position(position), m_type(type)
{}

PrintableElement::~PrintableElement()
{}

void PrintableElement::printElement()
  {
    std::cout << "Position :" << getPosition() <<std::endl;
    std::cout << "Type :" << getType() <<std::endl;
  }



