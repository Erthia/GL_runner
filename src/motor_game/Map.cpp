#include "Map.hpp"

namespace motor_game{
    
    const Element Map::element(const unsigned int &x, const unsigned int &y, const unsigned int &z) const{
        return m_elements[x + m_x*y + (m_x*m_y)*z];
    }
    
    Element Map::element(const unsigned int &x, const unsigned int &y, const unsigned int &z){
        return m_elements[x + m_x*y + (m_x*m_y)*z];
    }
}
