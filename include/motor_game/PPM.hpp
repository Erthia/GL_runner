#pragma once

#include <fstream>
#include <string>
#include <vector>

#include "Element.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Map.hpp"

namespace motor_game{
    /*
    class PPMreader{
        public:
            /// \brief constructor
            /// \param string of the file name
            PPMreader(const std::string &filename);
            
            PPMreader() = delete;
            
            ///\brief destructor
            ~PPMreader();
            
            /// \brief read the file and set the ppm
            PPM &readFile();
        
        private :
            // return the next valid string in the file (ie not a comment)
            // don't manage end of file
            const std::string nextString() const;
        
            std::ifstream m_ppm_1;
            std::string m_currentStr;
    };
    
    class PPM{
        public :
            ///\brief constructor
            /// \param dimensions of the map
            PPM() = default;
            
            /// \brief getter : Element vector of the level
            inline const glm::vector<Element> elements() const{
                return m_elements;
            }
            
            /// \brief setter : Element vector of the level
            inline glm::vector<Element> elements(){
                return m_elements;
            }
            
            /// \brief getter : returns the hero
            inline const Hero &hero() const{
                return m_hero;
            }
            
            /// \brief setter : the hero
            inline Hero &hero(){
                return m_hero;
            }
            
            /// \brief getter : returns the enemy
            inline const Enemy &enemy() const{
                return m_enemy;
            }
            
            /// \brief setter : the enemy
            inline Enemy &enemy(){
                return m_enemy;
            }
            
            /// \brief getter : returns the dimensions of the map
            inline const glm::vec3 &dimensions() const{
                return glm::vec3(m_x, m_y, m_z);
            }
            
            /// \brief setter : the x-dimension of the map
            inline unsigned int &x(){
                return m_x;
            }
            
            /// \brief setter : y-dimension of the map
            inline unsigned int &y(){
                return m_y;
            }
            
            /// \brief setter : the z-dimension of the map
            inline unsigned int &z(){
                return m_z;
            }
        

        private:
            Map m_map;
            Hero m_hero;
            Enemy m_enemy;
    };
    */
}

