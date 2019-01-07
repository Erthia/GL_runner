#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <cmath>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/cube.hpp>
#include <glimac/Cone.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/Object.hpp>
#include <glimac/Program.hpp>
#include "TrackballCamera.hpp"
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/Grid.hpp>
#include <vector>
#include <cstdlib>
//#include <GLFW/glfw3.h>
#include <fstream>
#include "AppManager.hpp"
#include "Menu.hpp"
#include "perspectiveShader.hpp"
#include "Grid.hpp"
#include "Scene.hpp"
#include "TrackballCamera.hpp"
#include "Map.hpp"
#include "Element.hpp"
#include "User.hpp"
#include "PrintableElement.hpp"
#include "Element.hpp"
#include "Character.hpp"
//#include "Coin.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Obstacle.hpp"
#include "Gap.hpp"
#include "Map.hpp"
#include "PPM.hpp"
#include "PPMreader.hpp"
#include "eyeCamera.hpp"
#include "Character.hpp"
#include "checkRotation.hpp"


#include <memory>

AppManager::AppManager()
{}

int AppManager::start(char** argv)
{

/** PLUS PROPRE A TROUVER **/

  bool GAME = true;

/********************************/

// Initialize and Open Window
  SDLWindowManager windowManager(m_width,m_height, "GLImac");


// Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }

// SHADER
  PerspectiveShader shader3D;
  PerspectiveShader shaderRed("./shaders/red.fs.glsl");

// CAMERA
  std::shared_ptr<TrackballCamera> camera(new TrackballCamera);
// MOTOR GAME
  glEnable(GL_DEPTH_TEST);

  motor_game::PPMreader theReader("test_01.ppm");
  motor_game::PPM ppmCool=theReader.readFile();

  Hero hero = ppmCool.hero();
  hero.setSpeed(0.05);


/*** A changer ***/
  std::unique_ptr<Cube> cube(new Cube);
  std::vector<std::unique_ptr<Object>> vectorObject;
  vectorObject.emplace_back(std::move(cube));
  // Menu
  Menu menu;
  menu.setVisibility(false);
  Cube player;
  Landmark landmark;
  Grid grid;

  Scene game(std::move(vectorObject),camera);
  float speed = 0.05;
  float begin = 0;

  int startTicksRight=0;
  int startTicksLeft=0;

  // PROJECTION INTEGER







  // Application loop:

  bool done = false;
  while(!done) {
      if (menu.visibility() == true)
      {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {

            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
              if (menu.onMouseEvent(windowManager.getMousePosition()) == 1)
              {
                GAME = 1;
                glUseProgram(0);
              }
            }

            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        //Render loop:

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);



        shaderRed.use();
        shaderRed.setViewMatrix(camera->getViewMatrix(),glm::mat4(1.0));
        shaderRed.setUniformMatrix();

        menu.displayMenu();


      }


      if (GAME)
      {

        // Event loop:
        SDL_Event e;
        float z;
        while(windowManager.pollEvent(e)) {

            if (e.type == SDL_KEYDOWN){
              camera->onKeyboardEvent(e);
              if (e.key.keysym.sym  == SDLK_ESCAPE)
              {
                menu.setVisibility(true);
                GAME = false; //A changer pour faie un mode popUp
                glUseProgram(0);
              }
              if (e.key.keysym.sym  == SDLK_q)
              {

                if (startTicksLeft != 0 && (SDL_GetTicks()-startTicksLeft)<300)
                {

                  if (ppmCool.map().element(hero.getX(),0,hero.getZ())!=nullptr)
                  {
                    if (ppmCool.map().element(hero.getX(),0,hero.getZ())->getType() == "left")
                    {

                      z = 0;
                      z = setRotationZ(ppmCool.map(),hero.getX(),hero.getZ());
                      std::cout << " z = " << z << " Hero Z = " << hero.getZ() <<std::endl;
                      if (hero.getX() == 1)
                      {

                        ppmCool.map().translateMap(hero.getX()+1,hero.getZ());
                        hero.translate(hero.getX()+1,hero.getZ());
                        ppmCool.map().rotateLeft();
                        ppmCool.map().translateMap(-(hero.getX()+1),-(hero.getZ()));

                      }
                      if (hero.getX() == 2)
                      {

                        ppmCool.map().translateMap(hero.getX()-1,hero.getZ());
                        hero.translate(hero.getX()+1,hero.getZ());
                        ppmCool.map().rotateLeft();
                        ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()));

                      }
                      else
                      {

                        ppmCool.map().translateMap(hero.getX(),hero.getZ()+z);
                        hero.translate(hero.getX()+1,hero.getZ());
                        ppmCool.map().rotateLeft();
                        ppmCool.map().translateMap(-(hero.getX()),-(hero.getZ()));

                      }




                      std::cout<< "AJUSTEMENT DES COORD" <<std::endl;
                      if (fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round( ppmCool.map().getElementi(5)->getPosition().x)))<0)
                      {
                        if (ppmCool.map().getElementi(5)->getPosition().x > 0)
                        {

                        ppmCool.map().translateMap((fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round( ppmCool.map().getElementi(5)->getPosition().x)))),hero.getZ());
                        }
                        else
                        {

                          ppmCool.map().translateMap(-(fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round(ppmCool.map().getElementi(5)->getPosition().x)))),hero.getZ());
                        }
                      }
                      if (fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round( ppmCool.map().getElementi(5)->getPosition().x)))>0)
                      {
                        if (ppmCool.map().getElementi(5)->getPosition().x > 0)
                        {

                        ppmCool.map().translateMap((fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round( ppmCool.map().getElementi(5)->getPosition().x)))),hero.getZ());
                        }
                        else
                        {

                          ppmCool.map().translateMap(-(fabs(ppmCool.map().getElementi(5)->getPosition().x) - fabs((round( ppmCool.map().getElementi(5)->getPosition().x)))),hero.getZ());
                        }
                      }

                      startTicksRight = 0;
                      begin = 0;
                      std::cout<<"FIN DE LA ROTATION"<<std::endl;

                    }
                  }

                }
                else
                {
                  startTicksLeft = SDL_GetTicks();
                  if(ppmCool.map().element(hero.getX()-1,hero.getY(),hero.getZ())==nullptr)
                  {
                    hero.moveLeft();
                  }

                }





              }
              if (e.key.keysym.sym  == SDLK_d)
              {

                if (startTicksRight != 0 && (SDL_GetTicks()-startTicksRight)<300)
                {

                  if (ppmCool.map().element(hero.getX(),0,hero.getZ())!=nullptr)
                  {
                    if (ppmCool.map().element(hero.getX(),0,hero.getZ())->getType() == "right")
                    {

                      z = 0;
                      z = setRotationZ(ppmCool.map(),hero.getX(),hero.getZ());
                      std::cout << " \n \n z = " << z << " Hero Z = " << hero.getZ() << " Hero X = " << hero.getX() <<std::endl;
                      std::cout<< "AVANT TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;

                      if (hero.getX() == 1)
                      {
                        std::cout<<"CAS 1"<<std::endl;

                        if (z == 0)
                        {
                          ppmCool.map().translateMap(hero.getX()+1,hero.getZ()-1);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()+1),-(hero.getZ()-1));

                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }

                        else
                        {
                          ppmCool.map().translateMap(hero.getX()+1,hero.getZ()+z);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()+1),-(hero.getZ()+z));
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }


                        //ppmCool.map().projectionX(ppmCool.map().projectionX()+1);

                      }
                      if (hero.getX() == 2)
                      {
                        std::cout<<"CAS 2 "<<hero.getX()<<std::endl;

                        if (z == 0)
                        {
                          ppmCool.map().translateMap(hero.getX()-1,hero.getZ()-1);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()-1));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+3);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }

                        if ( z == -1)
                        {
                          ppmCool.map().translateMap(hero.getX()-1,hero.getZ()+z);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()+z));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+3);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }

                        if (z == 1)
                        {
                          ppmCool.map().translateMap(hero.getX()-1,hero.getZ()-1);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()-1));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+4);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }




                      }

                      if (hero.getX() == 3)
                      {
                        std::cout<<"CAS DUC "<<hero.getX()<<std::endl;

                        if ( z == -1 )
                        {
                          ppmCool.map().translateMap(hero.getX()-1,hero.getZ()+z);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()+z));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+3);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }

                        if ( z == 0 )
                        {
                          ppmCool.map().translateMap(hero.getX()-1,hero.getZ()-1);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()-1),-(hero.getZ()-1));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+4);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }

                        if ( z == 1)
                        {

                          ppmCool.map().translateMap(hero.getX(),hero.getZ()-1);
                          hero.translate(0,hero.getZ());
                          ppmCool.map().rotateRight();
                          ppmCool.map().translateMap(-(hero.getX()),-(hero.getZ()-1));

                          //ppmCool.map().projectionX(ppmCool.map().projectionX()+3);
                          std::cout<< "APRES TRANSLATION ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
                        }



                      }


                      if (ppmCool.map().getElementi(8) != nullptr)
                      {
                        std::cout<<ppmCool.map().getElementi(8)->getPosition()<<std::endl;


                        std::cout<< "AJUSTEMENT DES COORD" <<std::endl;
                        if (fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round( ppmCool.map().getElementi(8)->getPosition().x)))<0)
                        {
                          if (ppmCool.map().getElementi(8)->getPosition().x > 0)
                          {

                          ppmCool.map().translateMap((fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round( ppmCool.map().getElementi(8)->getPosition().x)))),hero.getZ());
                          }
                          else
                          {

                            ppmCool.map().translateMap(-(fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round(ppmCool.map().getElementi(8)->getPosition().x)))),hero.getZ());
                          }
                        }
                        if (fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round( ppmCool.map().getElementi(8)->getPosition().x)))>0)
                        {
                          if (ppmCool.map().getElementi(8)->getPosition().x > 0)
                          {

                          ppmCool.map().translateMap((fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round( ppmCool.map().getElementi(8)->getPosition().x)))),hero.getZ());
                          }
                          else
                          {

                            ppmCool.map().translateMap(-(fabs(ppmCool.map().getElementi(8)->getPosition().x) - fabs((round( ppmCool.map().getElementi(8)->getPosition().x)))),hero.getZ());
                          }
                        }
                      }


                      startTicksRight = 0;
                      begin = 0;
                      std::cout<<"FIN DE LA ROTATION"<<std::endl;
                    //  std::cout << " \n \n z = " << z << " Hero Z = " << hero.getZ() << " Hero X = " << hero.getX() <<std::endl;
                    }
                  }


                }
                else
                {
                  startTicksRight = SDL_GetTicks();
                  if(ppmCool.map().element(hero.getX()+1,hero.getY(),hero.getZ()+0.05)==nullptr)
                  {
                    hero.moveRight();
                  }

                }
              }
            }


            if (e.button.button == SDL_BUTTON_WHEELUP || e.button.button == SDL_BUTTON_WHEELDOWN )
              camera->onMouseWheelEvent(e);

            if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT))
            {
              camera->onMouseEvent(e);
            }

            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
          }

          // Render loop:
          if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)==nullptr)
          {
            begin -=speed;
            hero.run();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            game.loadScene(ppmCool.map(),begin);

            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));

            projection *=glm::translate(glm::mat4(1),glm::vec3(ppmCool.map().projectionX(),ppmCool.map().projectionY(),ppmCool.map().projectionZ()));
            projection *=glm::translate(glm::mat4(1),glm::vec3(hero.getX(),hero.getY(),0));

            shader3D.use();
            shader3D.setViewMatrix(camera->getViewMatrix(),projection);
            shader3D.setUniformMatrix2();

          //  std::cout<< "player ("<<hero.getX()<<","<<hero.getY()<<","<<hero.getZ()<<") "<<std::endl;
            player.draw();


          }
          if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)!=nullptr)
          {
/*
             std::cout<<"  COLLISION W/ "<<ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType()<<std::endl;
              std::cout<<"  POSITION ELEMENT: "<< ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getPosition()<<std::endl;
              std::cout<<"  POSITION HERO: "<<hero.getPosition()<<std::endl;
*/
          }




          }

        //Update the display
        windowManager.swapBuffers();


    }

  return EXIT_SUCCESS;
}
