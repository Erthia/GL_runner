#pragma once

#include <fstream>
#include <string>
#include <vector>
#include <iostream>

#include "Element.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Map.hpp"
#include "End.hpp"
#include "Floor.hpp"
#include "Coin.hpp"
#include "Wall.hpp"
#include "Gap.hpp"
#include "Obstacle.hpp"

namespace motor_game{
    
      
    class PPM{
        public :
            PPM() = delete;
            
            ///\brief constructor
            /// \param dimensions of the map
            inline PPM(unsigned int x, unsigned int y, unsigned int z)
                : m_map(Map(x, y, z)) {}
            
            ///\brief destructor
            ~PPM();
            
            /// \brief getter : Element vector of the level
            inline const Map map() const{
                return m_map;
            }
            
            /// \brief setter : Element vector of the level
            inline Map map(){
                return m_map;
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
            inline const glm::vec3 dimensions() const{
                return glm::vec3(m_map.x(), m_map.y(), m_map.z());
            }
            
            /// \brief setter : the x-dimension of the map
            inline unsigned int x(){
                return m_map.x();
            }
            
            /// \brief setter : y-dimension of the map
            inline unsigned int y(){
                return m_map.y();
            }
            
            /// \brief setter : the z-dimension of the map
            inline unsigned int z(){
                return m_map.z();
            }
        

        private:
            Map m_map;
            Hero m_hero;
            Enemy m_enemy;
    };
    
    class PPMreader{
        public:
            /// \brief constructor
            /// \param string of the file name
            PPMreader(const std::string &filename);
            
            PPMreader() = delete;
            
            ///\brief destructor
            ~PPMreader();
            
            /// \brief read the file and set the ppm - can throw an exception
            const PPM readFile();
        
        private :
            // return the next valid string in the file (ie not a comment)
            // don't manage end of file
            const std::string nextString();
            std::string m_currentStr;
            std::ifstream m_ppm_1;
            unsigned int m_x=0;
            unsigned int m_y=2;
            unsigned int m_z=0;
    };
    
}

