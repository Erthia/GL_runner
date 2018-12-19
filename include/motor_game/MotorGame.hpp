#pragma once

#include "Map.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"

namespace motor_game
{
    /// \class MotorGame
    /// \brief manages the non-graphic game
    class MotorGame{
        public :
            // CONSTRUCTOR - DESTRUCTOR
            /// \brief constructor
            MotorGame(const PPM &ppm);

            /// \brief destructor
            ~MotorGame = default;
            
            /// no default constructors
            MotorGame() = delete;
            MotorGame(const MotorGame &mGame) = delete;
            MotorGame &operator=(const MotorGame &mGame) = delete;
            
            
            /// \brief game loop
            void playGame();
        
        private :

            // ATTRIBUTE
            Map m_map;
            Hero m_hero; /*!< the hero */
            Enemy m_enemy; /*!< the ennemy */
    };
}

