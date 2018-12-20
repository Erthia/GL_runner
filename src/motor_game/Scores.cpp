#include "Scores.hpp"

namespace motor_game{
    Scores::Scores(std::string &filename){
        //open the file
        m_inStream = std::ifstream("elt/" + filename, std::ios::in);
        if(m_inStream.is_open()){
            while(m_inStream.eof()==false){
                m_inStream >> m_currentName >> m_currentValue;
                m_scores.insert(pair<long, std::string>(m_currentValue, m_currentName)); // add values
                
            }
        }
    }
    
    
    Scores::~Scores = default;
    void Scores::add(const long &value, const &std::string);
    void Scores::clear();
}
