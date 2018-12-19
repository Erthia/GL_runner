#pragma once

class Element;
class Hero;

namespace motor_game{
    /// \class End
    /// \end of the level
    class End : public Element
    {
        public :
            /// \default constructor of class End
            End() = default;

            /// \brief constructor with parameters
            /// \param position, and type of the PrintableElement
            inline End(const glm::vec3 &position, const std::string &type = "End")
                : Element(position, type) {}
            
            /// \default destructor of our End
            ~End() = default;

            /// \method determining the behavior of an End when the player is colliding with it
            void collide(Hero &hero);
            
            /// \brief method to display the value of End's attributes
            void printElement() const;
        
    };
}
