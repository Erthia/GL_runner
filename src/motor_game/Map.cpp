#include "Map.hpp"

namespace motor_game{
    
    Map::Map(const unsigned int &x, const unsigned int &y, const unsigned int &z)
        : m_elements(std::vector<Element*>(x*y*z)), m_x(x), m_y(y), m_z(z)
    {}
    
    Map::~Map(){
        for(unsigned int i=0; i<m_x; i++){
            for(unsigned int j=0; j<m_y; j++){
                for(unsigned int k=0; k<m_z; k++){
                    delete m_elements[i + m_x*j + (m_x*m_y)*k];
                }
            }
        }
    }
    
    Element *Map::element(const unsigned int &x, const unsigned int &y, const unsigned int &z) const{
        return m_elements[x + m_x*y + (m_x*m_y)*z];
    }
    
    
    void Map::element(
        const unsigned int &x, const unsigned int &y, const unsigned int &z,
        Element *element
    ){
        m_elements[x + m_x*y + (m_x*m_y)*z] = element;
    }
}
