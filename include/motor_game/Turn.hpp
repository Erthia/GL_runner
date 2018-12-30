#ifndef TURN_HPP
#define TURN_HPP

#pragma once

#include "Floor.hpp"

namespace motor_game{

    /// \class floor in which the player can turn
    class Turn final : public Floor{
        public :
            Turn() = delete; 

            /// \class constructor
            /// \param position of the Turn, and type (left or right)
            Turn(const glm::vec3 &position, const std::string &type);

            /// \brief method to display the value of Turn's attributes
            void printElement() const;
            
            /// \brief method to call when the Character is on the Turn
            void collide(Hero *hero) const;

             /// \brief destructor
            ~Turn() = default;
    };
}
#endif
