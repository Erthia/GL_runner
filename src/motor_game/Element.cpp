#include "../../include/motor_game/Element.hpp"
#include <iostream>

Element::Element()
	:PrintableElement()
{}

Element::Element(const glm::vec3 &position, const std::string &type)
:PrintableElement(position, type)
{}


Element::~Element()
{}

void Element::printElement() const {
	std::cout << "\nELEMENT INFORMATION :" << std::endl;
	PrintableElement::printElement();

}

