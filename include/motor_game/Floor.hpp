#ifndef FLOOR_HPP
#define FLOOR_HPP

#pragma once

#include <iostream>
#include <string>
#include "Element.hpp"

namespace motor_game{
    class Floor : public Element
    {
      public:
        /// \brief default constructor of class Floor
        Floor(); 


        Floor(const glm::vec3 &position, const std::string &type = "Floor");

        /// \brief method to display the value of Floor's attributes
        void printElement() const;

         /// \brief default destructor of our Floor
        ~Floor(); 

    };
}

#endif
