#include "../../include/motor_game/Element.hpp"
#include <iostream>

Element::Element()
	:PrintableElement()
{}

Element::Element(const glm::vec3 &position, const std::string &type)
:PrintableElement(position, type)
{}

void Element::printElement() 
{
	PrintableElement::printElement();
}
void Element::collide(User *hero){}


Element::~Element()
{}




