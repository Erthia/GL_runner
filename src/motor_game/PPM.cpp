/*#include "motor_game/PPM.hpp"
#include "exception/ExceptIMAC.hpp"
#include "motor_game/Floor.hpp"
#include <string>

namespace motor_game{
    /*
    PPMreader::PPMreader(const std::string &filename)
    {
        //open the file
        std::ifstream m_ppm_1("elt/ppm/" + filename.c_str(), ios::in);
        std::abort(m_ppm_1.is_open());
    }
    
    const std::string PPM::nextString() const{
        std::string readElt << m_ppm_1;
        bool loop=1;
        while(loop){
            readElt << m_ppm_1;
            if(readElt.c_str[0] == '#') ppm_1.ignore('\n');
            else loop=0;
        }
    }
    
    PPM &PPMreader::readFile(){
        PPM ppm;
        if(m_ppm_1.nextString() != "P3"){
            THROW_EXCEPTION("The ppm file is not valid");
            return ppm;
        }
        
        // map's dimensions
        if(m_ppm_1.eof() == true){
            THROW_EXCEPTION("The ppm file is not valid");
            return ppm;
        }
        else ppm.x()=std::stoul(m_currentStr);
        
        if(m_ppm_1.eof() == true){
            THROW_EXCEPTION("The ppm file is not valid");
            return ppm;
        }
        else ppm.z()=std::stoul(m_currentStr);
        
        // the ppm file is supposed valid
        
        // read colors, and create elements
        for(unsigned int x=0; x<ppm.x(); x++){
            for(unsigned int z=0; z<ppm.z(); z++){
                m_ppm_1.nextString();
                if( // beginning
                    (m_ppm_1.nextString()==100) &&
                    (m_ppm_1.nextString()==100) &&
                    (m_ppm_1.nextString()==100)
                ){
                    m_elements[x+(0*ppm.y)+(m_x*m_y)*z]=Floor(glm::vec3(x,0,z));
                    m_hero.setPosition(glm::vec3(x+2, 0, z));
                    m_enemy.setPosition(glm::vec3(x, 0, z));
                }
                else if( // end
                    (m_ppm_1.nextString()==0) &&
                    (m_ppm_1.nextString()==0) &&
                    (m_ppm_1.nextString()==0)
                )
                    m_elements[x][0][z]=End(glm::vec3(x,0,z));
                
                else if( // gap
                    (m_ppm_1.nextString()==255) &&
                    (m_ppm_1.nextString()==255) &&
                    (m_ppm_1.nextString()==255)
                )
                    m_elements[x][0][z]=Gap(glm::vec3(x,0,z));
                
                else if( // floor
                    (m_ppm_1.nextString()==235) &&
                    (m_ppm_1.nextString()==150) &&
                    (m_ppm_1.nextString()==235)
                )
                    m_elements[x][0][z]=Floor(glm::vec3(x,0,z));
                else if( // wall
                    (m_ppm_1.nextString()==125) &&
                    (m_ppm_1.nextString()==65) &&
                    (m_ppm_1.nextString()==35)
                )
                    m_elements[x][0][z]=Wall(glm::vec3(x,0,z));
                else if( // high obstacle
                    (m_ppm_1.nextString()==95) &&
                    (m_ppm_1.nextString()==95) &&
                    (m_ppm_1.nextString()==225)
                )
                    m_elements[x][1][z]=Obstacle(glm::vec3(x,1,z));
                else if( // low obstacle
                    (m_ppm_1.nextString()==35) &&
                    (m_ppm_1.nextString()==185) &&
                    (m_ppm_1.nextString()==70)
                )
                    m_elements[x][1][z]=Obstacle(glm::vec3(x,0,z));
                else THROW_EXCEPTION("Unrecognize color in ppm, at coord ("+ x + ", " + y + ")");
            }
        }
    
    }
    
    PPMreader::~PPMreader(){
        // close the file
        m_ppm_1.close();
    }
        
    }
    
} */
