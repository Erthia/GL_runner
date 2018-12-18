#ifndef MOTOR_GAME_HPP
#define MOTOR_GAME_HPP

#pragma once

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
            Element[][][] m_elements; /*!< contains all the Elements, except the hero and the ennemy */
            Hero m_hero; /*!< the hero */
            Enemy m_enemy; /*!< the ennemy */
            size_t m_x; /*!< x-size of the map */
            size_t m_y = 2; /*!< y-size of the map */
            size_t m_z; /*!< z-size of the map */
    };
}
#endif
