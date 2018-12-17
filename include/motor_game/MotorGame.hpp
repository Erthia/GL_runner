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
            MotorGame();
            ~MotorGame = default;
            
            /// \brief initialize the non-graphic game
            void initGame();
            /// \brief game loop
            void playGame();
        
        private :
            // ATTRIBUTE
            std::list<Element> m_elements; /*!< contains all the Element.s */
            Hero m_hero;
            Ennemy m_ennemy;
    };
}
#endif
