#include "Map.hpp"

namespace motor_game{

    Map::Map(const unsigned int &x, const unsigned int &y, const unsigned int &z)
        : m_elements(std::vector<Element*>(x*y*z)), m_x(x), m_y(y), m_z(z)
    {}




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
