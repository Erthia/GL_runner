#include <iostream>
#include <string>
#include <GL/glew.h>



#pragma once

class Character : public PrintableElement
{
  public:

    Character(); /// default constructor
    Character(const glm::vec3 &position, const std::string &type, const unsigned int &speed); /// constructor with parameters
    void jump();
    void moveLeft();
    void moveRight();
    bool checkCollision();
    
    virtual void printElement();

    ~Character(); /// default destructor


  protected:
  unsigned int m_speed;

};
