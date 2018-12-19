#pragma once

#include <fstream>
#include <string>
#include <vector>
class Element;
class Hero;
class Enemy;

namespace motor_game{
    class PPM{
        public :
            ///\brief constructor
            inline PPM(size_t x, size_t y, size_t z)
                : m_elements(Element[x][y][z]), m_x(x), m_y(y), m_z(z) {}
            
            PPM() = delete;
            
            /// \brief getter : Element list of the level
            inline Element[][][] elements() const{
                return m_elements;
            }
            
            /// \brief getter : returns the hero
            inline Hero hero() const{
                return m_hero;
            }
            
            /// \brief getter : returns the enemy
            inline Enemy enemy() const{
                return m_enemy;
            }
            
            /// \brief getter : returns the dimensions of the map
            inline glm::vec3 dimensions() const{
                return glm::vec3(m_x, m_y, m_z);
            }
            
        private:
            Element m_elements[][][]; /*!< elements of the setting */
            Hero m_hero; /*!< hero, at his beginning position */
            Enemy m_enemy; /*!< ennemy, at his beginning position */
            size_t m_x;
            size_t m_y=2;
            size_t m_z;
            
            
            
    };
    
    class PPMreader{
        public:
            /// \brief constructor
            /// \param string of the file name
            PPMreader(const std::string &filename);
            
            PPM() = delete;
            
            ///\brief destructor
            ~PPMreader();
            
            /// \brief read the file and set the ppm
            PPM readFile();
        
        private :
            // return the next valid string in the file (ie not a comment)
            // don't manage end of file
            const std::string nextString() const;
        
            std::ifstream m_ppm_1;
            std::string m_currentStr;
            size_t m_x;
            size_t m_y=2;
            size_t m_z;
    };
}

