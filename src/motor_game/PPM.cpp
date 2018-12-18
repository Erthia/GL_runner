#include "../../include/graphic_engine/PPM.hpp"
#include "../../include/exception/ExceptIMAC.hpp"

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
        for(size_t i=0; i<m_x; i++){
        m_ppm_1.nextString();
            if(
                (m_ppm_1.nextString()==100) &&
                (m_ppm_1.nextString()==100) &&
                (m_ppm_1.nextString()==100)
            )
            else if
            else if
            else if
            else if
            else if
            else THROW_EXCEPTION("Unrecognize color in ppm, at coord ??");
        }
    
    }
        
        
    }
    
    PPM::~PPM(){
        // close the file
        m_ppm_1.close();
    }
}

