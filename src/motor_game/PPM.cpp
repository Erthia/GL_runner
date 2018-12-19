#include "motor_game/PPM.hpp"
#include "exception/ExceptIMAC.hpp"
#include "motor_game/Floor.hpp"
#include "PPM.hpp"

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
    
    const std::string PPMreader::nextString(){
        bool loop=1;
        std::string currentString;
        while(loop){
            m_ppm_1 >> currentString;
            if(currentString[0] == '#') m_ppm_1.ignore('\n');
            else loop=0;
        }
        return currentString;
    }
    
    const PPM PPMreader::readFile(){
        if(nextString() != "P3"){
            THROW_EXCEPTION("The ppm file is not valid");
            return PPM(0,0,0);
        }
        
        // map's dimensions
        if(m_ppm_1.eof() == true){
            THROW_EXCEPTION("The ppm file is not valid");
            return PPM(0,0,0);
        }
        else m_x=std::stoul(m_currentStr);
        
        if(m_ppm_1.eof() == true){
            THROW_EXCEPTION("The ppm file is not valid");
            return PPM(0,0,0);
        }
        else m_z=std::stoul(m_currentStr);
        
        // the ppm file is supposed valid
        
        PPM ppm(m_x, m_y, m_z);
        
        // read colors, and create elements
        for(unsigned int x=0; x<ppm.x(); x++){
            for(unsigned int z=0; z<ppm.z(); z++){
                if( // beginning
                    (nextString()=="100") &&
                    (nextString()=="100") &&
                    (nextString()=="100")
                ){
                    ppm.map().element(x, 0, z, new Floor(glm::vec3(x,0,z)));
                    ppm.hero().setPosition(glm::vec3(x+2, 0, z));
                    ppm.enemy().setPosition(glm::vec3(x, 0, z));
                }
                else if( // end
                    (nextString()=="0") &&
                    (nextString()=="0") &&
                    (nextString()=="0")
                )
                    ppm.map().element(x, 0, z, new End(glm::vec3(x,0,z)));
                
                else if( // gap
                    (nextString()=="255") &&
                    (nextString()=="255") &&
                    (nextString()=="255")
                )
                    ppm.map().element(x, 0, z, new Gap(glm::vec3(x,0,z)));
                
                else if( // floor
                    (nextString()=="235") &&
                    (nextString()=="150") &&
                    (nextString()=="235")
                )
                    ppm.map().element(x, 0, z, new Floor(glm::vec3(x,0,z)));
                else if( // wall
                    (nextString()=="125") &&
                    (nextString()=="65") &&
                    (nextString()=="35")
                )
                    ppm.map().element(x, 0, z, new Wall(glm::vec3(x,0,z)));
                else if( // high obstacle
                    (nextString()=="95") &&
                    (nextString()=="95") &&
                    (nextString()=="225")
                )
                    ppm.map().element(x, 1, z, new Obstacle(glm::vec3(x,1,z)));
                else if( // low obstacle
                    (nextString()=="35") &&
                    (nextString()=="185") &&
                    (nextString()=="70")
                )
                    ppm.map().element(x, 0, z, new Obstacle(glm::vec3(x,0,z)));
                else THROW_EXCEPTION("Unrecognize color in ppm, at coord ("+ std::to_string(x) + ", " + std::to_string(z) + ")");
            }
        }
        return ppm;
    }
    
    PPMreader::~PPMreader(){
        // close the file
        m_ppm_1.close();
    }
        
}
