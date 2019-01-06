#ifndef MAP_HPP
#define MAP_HPP
#pragma once

#include <vector>

#include "Element.hpp"
#include "negative_vector.hpp"

namespace motor_game{
    /// \class Map
    /// \brief contains the level elements, and the dimensions' level
    class Map{
        public :
            Map() = delete;
            Map(const int &x, const int &y, const int &z);

            /// \brief getter of an Element
            /// \param coordinates of this Element
            Element *element(const int &x, const int &y, const int &z) const;

            inline const unsigned int size(){
              return m_elements.size();
            }

            inline const negative_vector<Element*> getVector(){
              return m_elements;
            }

            Element* getElementi(const int i) const;
            /// \brief setter of an Element
            /// \param coordinates of this Element, and the Element
           void element(
                const int &x, const int &y, const int &z,
                Element *element
            );


            /// \brief getter of x-coordiconst unsigned int &x, const unsigned int &y, const unsigned int &znate
            inline const int &x() const{
                return m_x;
            }

            /// \brief getter of y-coordinate
            inline const int &y() const{
                return m_y;
            }


            /// \brief getter of z-coordinate
            inline const int &z() const{
                return m_z;
            }

            /// \brief getter of projection on X
            inline int projectionX() const{
              return m_projectionX;
            }

            /// \brief getter of projection on Y
            inline int projectionY() const{
              return m_projectionY;
            }

            /// \brief getter of projection on Z
            inline int projectionZ() const{
              return m_projectionZ;
            }

            /// \brief setter of projection on X
            inline void projectionX(const int x){
              m_projectionX = x;
            }

            /// \brief getter of projection on Y
            inline void projectionY(const int y){
              m_projectionY = y;
            }

            /// \brief getter of projection on Z
            inline void projectionZ(const int z){
              m_projectionZ = z;
            }

            void printElement();
            void translateMap(const float &x, const float &z);
            void rotateRight();
            void rotateLeft();



        private :
            negative_vector<Element*> m_elements;

            int m_x=0;
            int m_y=2;
            int m_z=0;

            int m_projectionX = -2;
            int m_projectionY = -3;
            int m_projectionZ = -3;


    };

}
#endif
