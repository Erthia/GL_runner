#pragma once

#include <GL/glew.h>
#include <glm/glm.hpp>
#include <iostream>
#include <string>
#include "Element.hpp"
class Hero;

namespace motor_game{
    
    class Gap final : public Element
    {
      public:
        Gap(); 
        /// brief constructor
        /// param position, and type
        /*Gap(const glm::vec3 &position = glm::vec3(0), const std::string &type = "Gap")
            : m_position(position), m_type(type) {}*/
        Gap(const glm::vec3 &position, const std::string &type="Gap");

        /// brief default destructor
        ~Gap() = default;
        
        /// method determining the behavior of a Gap when the player is colliding with it
        void collide(Hero *hero);

        /// brief method to display the value of Gap's attributes
        void printElement() const;
    };
}
