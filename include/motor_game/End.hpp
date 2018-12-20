#pragma once

#include "Element.hpp"
#include "Hero.hpp"

namespace motor_game{
    /// class End
    /// end of the level
    class End final : public Element
    {
        public :
            /// default constructor of class End
            End() = default;

            /// brief constructor with parameters
            /// param position, and type of the PrintableElement
            inline End(const glm::vec3 &position, const std::string &type = "End")
                : Element(position, type) {}

            /// method to determine the behavior of an End when the player is colliding with it
            void collide(Hero *hero);
            
            /// brief method to display the value of End's attributes
            void printElement() const;

            /// default destructor of our End
            ~End() = default;
        
    };
}
