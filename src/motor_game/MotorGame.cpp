#include "include/motor_game/MotorGame.hpp"
#include "include/glimac/SDLWindowManager.hpp"
#include <SDL/SDL.h>

namespace motor_game{
    MotorGame::initGame(const PPM &ppm, SDLWindowManager window){
        // on remplit m_elements grace à une méthode de ppm
        // on demande le nom au joueur
        User player(name);
    }
    
    MotorGame::playGame(){
        int loop = 1;
        while(loop){
            unsigned int startTime = SDL_GetTicks();
            
            // Events
            
            SDL_Event e;
            windowManager.isKeyPressed(
        }
        //verify inputs and act
        //delete passed elements
        // move all elements to be moved
        
        windowManager.swapBuffers();
        
        
        /* spent time */
		unsigned int elapsedTime = SDL_GetTicks() - startTime;
		/* if not enough time spent, program paused */
		if(elapsedTime < FRAMERATE_MILLISECONDS)
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        
    }
}
