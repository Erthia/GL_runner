#include "motor_game/PPM.hpp"
#include "exception/ExceptIMAC.hpp"
#include "motor_game/Floor.hpp"

namespace motor_game{
    
    const std::string PPM::nextString() const{
        std::string readElt << m_ppm_1;
        bool loop=1;
        while(loop){
            readElt << m_ppm_1;
            if(readElt.c_str[0] == '#') ppm_1.ignore('\n');
            else loop=0;
        }
    }
    
    PPM::PPM(const std::string &filename)
    {
        //open the file
        std::ifstream m_ppm_1(filename.c_str(), ios::in);
        std::abort(m_ppm_1.is_open());
    }
    
    void readFile(){
        if(m_ppm_1.nextString() != "P3") THROW_EXCEPTION("The ppm file is not valid");
        
        // map's dimensions
        if(m_ppm_1.eof() == true) THROW_EXCEPTION("The ppm file is not valid");
        else m_x=m_currentStr;
        
        if(m_ppm_1.eof() == true) THROW_EXCEPTION("The ppm file is not valid");
        else m_z=m_currentStr;
        
        // the ppm file is supposed valid
        
        // read colors, and create elements
        for(size_t x=0; x<m_x; x++){
            for(size_t z=0; z<m_z; z++){
                m_ppm_1.nextString();
                if( // beginning
                    (m_ppm_1.nextString()==100) &&
                    (m_ppm_1.nextString()==100) &&
                    (m_ppm_1.nextString()==100)
                ){
                    m_elements[x][0][z]=Floor(glm::vec3(x,0,z));
                    m_hero.setPosition(glm::vec3(x, 0, z));
                }
                else if( // end
                    (m_ppm_1.nextString()==0) &&
                    (m_ppm_1.nextString()==0) &&
                    (m_ppm_1.nextString()==0)
                ){
                    m_elements[x][0][z]=End(glm::vec3(x,0,z));
                }
                else if( // gap
                    (m_ppm_1.nextString()==255) &&
                    (m_ppm_1.nextString()==255) &&
                    (m_ppm_1.nextString()==255)
                ){
                    m_elements[x][0][z]=Gap();
                }
                else if( // floor
                    (m_ppm_1.nextString()==235) &&
                    (m_ppm_1.nextString()==150) &&
                    (m_ppm_1.nextString()==235)
                )
                else if( // wall
                    (m_ppm_1.nextString()==125) &&
                    (m_ppm_1.nextString()==65) &&
                    (m_ppm_1.nextString()==35)
                )
                else if( // high obstacle
                    (m_ppm_1.nextString()==95) &&
                    (m_ppm_1.nextString()==95) &&
                    (m_ppm_1.nextString()==225)
                )
                else if( // low obstacle
                    (m_ppm_1.nextString()==35) &&
                    (m_ppm_1.nextString()==185) &&
                    (m_ppm_1.nextString()==70)
                )
                else THROW_EXCEPTION("Unrecognize color in ppm, at coord ??");
            }
        }
    
    }
        
        
    }
    
    PPM::~PPM(){
        // close the file
        m_ppm_1.close();
    }
}

