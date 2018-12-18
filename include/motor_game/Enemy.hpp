#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>

#pragma once

#include "Character.hpp"

class Enemy : public Character
{
  public:

    Enemy(); /// default constructor
    Enemy(const glm::vec3 &position, const unsigned int &speed, const std::string &type="Enemy"); /// constructor with parameters
    void killHero();
   

    void printElement() const;
    ~Enemy(); /// default destructor


  protected:


};
