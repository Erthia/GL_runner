#ifndef MAP_HPP
#define MAP_HPP
#pragma once

#include <vector>

#include "Element.hpp"

namespace motor_game{
    /// \class Map
    /// \brief contains the level elements, and the dimensions' level
    class Map{
        public :
            Map() = delete;
            
            ///\brief constructor
            /// \param dimensions of the map
            Map(const unsigned int &x, const unsigned int &y, const unsigned int &z);
            
            ///\brief destructor
            ~Map();
            
            /// \brief getter of an Element
            /// \param coordinates of this Element
            Element *element(const unsigned int &x, const unsigned int &y, const unsigned int &z) const;
            
            /// \brief setter of an Element
            /// \param coordinates of this Element, and a pointer to the Element
           void element(
                const unsigned int &x, const unsigned int &y, const unsigned int &z,
                Element *element
            );
            
            /// \brief erase an Element
            /// \param coordinates of the Element
            void erase(const unsigned int &x, const unsigned int &y, const unsigned int &z);
            
            /// \brief getter of x-coordinate
            inline const unsigned int &x() const{
                return m_x;
            }
            
            /// \brief getter of y-coordinate
            inline const unsigned int &y() const{
                return m_y;
            }
            
            
            /// \brief getter of z-coordinate
            inline const unsigned int &z() const{
                return m_z;
            }
            
            
        
        private :
            std::vector<Element*> m_elements; /*!<  vector of element types */
            unsigned int m_x=0;  /*!<  map dimension x */
            unsigned int m_y=3;  /*!< map dimension y : 3 "levels" */
            unsigned int m_z=0;  /*!< map dimension z*/
    };
    
}
#endif
