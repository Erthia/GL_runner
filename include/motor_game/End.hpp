#pragma once

#include "Element.hpp"
#include "Hero.hpp"

namespace motor_game{
    /// \class End
    /// \brief represent the end of the level
    class End : public Element{
        public :
            /// \brief constructor with no parameter
            End() = default;
            /// \brief constructor with parameters
            /// \param position, and type of the PrintableElement
            inline End(const glm::vec3 &position, const std::string &type = "End")
                : Element(position, type) {}
            
            ~End() = default;
            
            void collide(Hero &hero);
            
            void printElement() const;
        
    };
}
