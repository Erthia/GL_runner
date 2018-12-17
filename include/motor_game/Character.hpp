#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <list>

#pragma once

#include "PrintableElement.hpp"
#include "Element.hpp"

class Character : public PrintableElement
{
  public:

    Character(); /// default constructor
    Character(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters
    void run();
    void up();
    void down();
    void moveLeft();
    void moveRight();
    bool checkCollisionMovement(const PrintableElement &b, const char &movement);
    bool checkCollision(const PrintableElement &b);
    //const Element* scanList(const std::list<Element> &list, const char &movement);
    void scanList(std::list<Element> &list, const char &movement);
    
    virtual void printElement();

    ~Character(); /// default destructor


  protected:
  unsigned int m_speed;

};
