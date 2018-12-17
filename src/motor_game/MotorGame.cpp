#include "../../include/motor_game/MotorGame.hpp"
#include "include/glimac/SDLWindowManager.hpp"
#include <SDL/SDL.h>

namespace motor_game{
    MotorGame::MotorGame(const PPM &ppm){
       m_elements=ppm.elements();
       m_hero=ppm.hero();
       m_enemy=ppm.enemy();
    }
    
    void MotorGame::deletePassedElts(){
        
    }
    
    MotorGame::playGame(){
        int loop = 1;
        while(loop){
            unsigned int startTime = SDL_GetTicks();
            
            // Events
            SDL_Event e;
            while(windowManager.pollEvent(e)){
                // The user closes the window
                if(e.type == SDL_QUIT)
                    loop = 0;
                
                switch(e.button.button){
                    // keyboard action
                    case SDL_KEYDOWN:
                        switch(e.key.keysym.sym){
                            case SDLK_ESCAPE:
                                loop = 0;
                            case SDLK_q:
                                if(m_hero.checkCollisionMovement('q')==false){
                                    m_hero.moveLeft();
                                    m_enemy.moveLeft();
                                }
                            break;
                            case SDLK_d:
                                if(m_hero.checkCollisionMovement('d')==false){
                                    m_hero.moveRight();
                                    m_enemy.moveRight();
                                }
                            break;
                            case SDLK_z:
                                if(m_hero.checkCollisionMovement('z')==false){
                                    m_hero.up();
                                    m_enemy.up();
                                }
                            break;
                        
                            case SDLK_s:
                                m_hero.down();
                                m_enemy.down();
                            break;
                        }
                    break;
                    
                    default:
                    break;
                }
            }
            m_hero.run();
            m_enemy.run();
        }
        
        windowManager.swapBuffers();
        
        // spent time
		unsigned int elapsedTime = SDL_GetTicks() - startTime;
		// if not enough time spent, program paused
		if(elapsedTime < FRAMERATE_MILLISECONDS)
            SDL_Delay(FRAMERATE_MILLISECONDS - elapsedTime);
        
    }

}

