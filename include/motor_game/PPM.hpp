#include <fstream>
#include <string>

#ifndef PPM_HPP
#define PPM_HPP

#pragma once

namespace motor_game{
    class PPM{
        public :
            /// \brief constructor, can throw an exception
            /// \param string of the file name
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
            
            /// \brief read the file and set the ppm
            void readFile();
            
        private:
            std::ifstream m_ppm_1; /*!< ppm file */
            std::vec<std::vec<std::vec<Element>>> m_elements; /*!< elements of the setting */
            Hero m_hero; /*!< hero, at his beginning position */
            Enemy m_enemy; /*!< ennemy, at his beginning position */
            unsigned int m_x;
            unsigned int m_y=2;
            unsigned int m_z;
            std::string m_currentStr;
            
            // return the next valid string in the file (ie not a comment)
            // don't manage end of file
            const std::string nextString() const;
            
    };
}
#endif
