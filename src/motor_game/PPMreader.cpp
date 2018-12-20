#include "motor_game/PPM.hpp"
#include "exception/ExceptIMAC.hpp"
#include "motor_game/Floor.hpp"
#include "PPM.hpp"
#include "PPMreader.hpp"

#include <string>
#include <cassert>
#include <fstream>
#include <string>
#include <iostream>

namespace motor_game{
    
        PPMreader::PPMreader(const std::string &filename)
    {
        //open the file
        m_ppm_1 = std::ifstream("elt/ppm/" + filename, std::ios::in);
        assert(m_ppm_1.is_open());
    }
    
    //testée
    const std::string PPMreader::nextString(){
        bool loop=1;
        while(loop){
            std::getline(m_ppm_1, m_currentStr);
            if(m_currentStr[0] != '#') loop=0;
        }
        return m_currentStr;
    }
    
    const PPM PPMreader::readFile(){
        m_currentStr=nextString();
        assert(m_currentStr == "P3");
        assert(m_ppm_1.eof() == false);
        
        m_x=std::stoul(nextString().c_str());
        m_z=std::stoul(m_currentStr.substr(std::to_string(m_x).size()).c_str());
        
        assert(m_ppm_1.eof() == false);
        
        m_currentStr=nextString();
        assert(m_currentStr=="255");
        
        assert(m_ppm_1.eof() == false);
        
        // the ppm file is supposed valid
        
        PPM ppm(m_x, m_y, m_z);
        
        // read colors, and create elements
        for(unsigned int x=0; x<ppm.x(); x++){
            for(unsigned int z=0; z<ppm.z(); z++){
                m_r=nextString();
                m_g=nextString();
                m_b=nextString();

                if( // beginning
                    (m_r=="100") &&
                    (m_g=="100") &&
                    (m_b=="100")
                ){
                    ppm.map().element(x, 0, z, new Floor(glm::vec3(x,0,z)));
                    ppm.hero().setPosition(glm::vec3(x+2, 0, z));
                    ppm.enemy().setPosition(glm::vec3(x, 0, z));
                }
                else if( // end
                    (m_r=="0") &&
                    (m_g=="0") &&
                    (m_b=="0")
                )
                    ppm.map().element(x, 0, z, new End(glm::vec3(x,1,z)));
                
                else if( // gap
                    (m_r=="255") &&
                    (m_g=="255") &&
                    (m_b=="255")
                ){
                    ppm.map().element(x, 0, z, new Gap(glm::vec3(x,1,z)));
                }
                else if( // floor
                    (m_r=="235") &&
                    (m_g=="150") &&
                    (m_b=="235")
                )
                    ppm.map().element(x, 0, z, new Floor(glm::vec3(x,0,z)));
                else if( // wall
                    (m_r=="125") &&
                    (m_g=="65") &&
                    (m_b=="35")
                )
                    ppm.map().element(x, 0, z, new Wall(glm::vec3(x,1,z)));
                else if( // high obstacle
                    (m_r=="95") &&
                    (m_g=="95") &&
                    (m_b=="225")
                )
                    ppm.map().element(x, 1, z, new Obstacle(glm::vec3(x,2,z)));
                else if( // low obstacle
                    (m_r=="35") &&
                    (m_g=="185") &&
                    (m_b=="70")
                )
                    ppm.map().element(x, 0, z, new Obstacle(glm::vec3(x,1,z)));
                else assert(false);
            }
        }
        return ppm;
    }
    
    PPMreader::~PPMreader(){
        // close the file
        m_ppm_1.close();
    }
}
