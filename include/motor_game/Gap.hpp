#pragma once

#include "Element.hpp"
#include "Hero.hpp"

namespace motor_game{
    
    class Gap : public Element
    {
      public:
        Gap(); 
        /// \brief constructor
        /// \param position, and type
        /*Gap(const glm::vec3 &position = glm::vec3(0), const std::string &type = "Gap")
            : m_position(position), m_type(type) {}*/
        Gap(const glm::vec3 &position, const std::string &type);

        /// \brief default destructor
        ~Gap() = default;
        
        /// \brief fonction to call when a character collide the gap
        void collide(Hero *hero);

        /// \test print the gap info
        void printElement() const;
    };
}
