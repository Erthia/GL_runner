#ifndef MOTOR_GAME_HPP
#define MOTOR_GAME_HPP

#pragma once

#include "Map.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"

namespace motor_game
{
    /// \class MotorGame
    /// \brief manage the non-graphic game
    class MotorGame{
        public :
            // CONSTRUCTOR - DESTRUCTOR
            /// \brief constructor
            MotorGame(const PPM &ppm);
            /// \brief destructor
            ~MotorGame = default;
            
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
#endif
