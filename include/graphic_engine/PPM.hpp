#include <fstream>

#ifndef PPM_HPP
#define PPM_HPP

#pragma once

namespace graphic_engine{
    class PPM{
        public :
            /// \brief constructor
            PPM(const &std::string filename);
            
            ///\brief destructor
            ~PPM();
            
            PPM() = delete;
            
            /// \brief getter : Element list of the level
            std::list<Element> elements();
            
            /// \brief getter : and returns the hero
            Hero hero();
            
            /// \brief getter : and returns the enemy
            Enemy enemy();
            
        private:
            std::ifstream m_ppm; /*!< ppm file */
            std::list<Element> m_elements;
            Hero m_hero;
            Enemy m_enemy;
        
    };
}
#endif
