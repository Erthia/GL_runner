#include "include/motor_game/MotorGame.hpp"
#include "include/glimac/SDLWindowManager.hpp"
#include <SDL/SDL.h>

namespace motor_game{
   MotorGame::MotorGame{
       // on remplit m_elements, m_hero et m_ennely grace à une méthode de ppm
   }
    
   MotorGame::initGame(const PPM &ppm, SDLWindowManager window){
        // on demande le nom au joueur
        User player(name);
    }
    
    MotorGame::playGame(){
        int loop = 1;
        while(loop){
            unsigned int startTime = SDL_GetTicks();
            
            // Events
            
            SDL_Event e;
            while(windowManager.pollEvent(e)){
                switch(e.button.button){
                    // keyboard action
                    case SDL_KEYDOWN:
                        switch(e.key.keysym.sym){
                            case SDLK_q:
                                
                            case SDLK_d:
                            
                            case SDLK_z:
                            
                            case SDLK_s:
                        }
                    break;
                    
                    default:
                    break;
                }
            }
        }
        //verify inputs and act
        //delete passed elements
        // move all elements to be moved
        
        windowManager.swapBuffers();
        
        
        // spent time
		unsigned int elapsedTime = SDL_GetTicks() - startTime;
		// if not enough time spent, program paused
		if(elapsedTime < FRAMERATE_MILLISECONDS)
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        
    }
    */
}
