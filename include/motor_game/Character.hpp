#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once

#include "PrintableElement.hpp"

class Character : public PrintableElement
{
  public:

    Character(); /// default constructor
    Character(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters
    void jump();
    void moveLeft();
    void moveRight();
    bool checkCollision(const PrintableElement &a, const PrintableElement &b);
    
    virtual void printElement();

    ~Character(); /// default destructor


  protected:
  unsigned int m_speed;

};
