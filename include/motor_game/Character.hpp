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
    void run();
    void up();
    void down();
    void moveLeft();
    void moveRight();
    bool checkCollisionMovement(const PrintableElement &b, const char &movement);
    bool checkCollision(const PrintableElement &b);
    // checkpossiblecollision() méthode check mouvement
    
    virtual void printElement();

    ~Character(); /// default destructor


  protected:
  unsigned int m_speed;

};
