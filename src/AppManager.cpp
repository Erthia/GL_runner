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
#include "TextureLoader.hpp"
#include "Skybox.hpp"

#include <memory>

AppManager::AppManager()
{}

int AppManager::start(char** argv)
{

/** PLUS PROPRE A TROUVER **/

  bool MENU = true;
  bool GAME = false;
  bool TEST = false;

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
  PerspectiveShader shader3DTex("./shaders/Tex3D.fs.glsl");
  PerspectiveShader shaderSkybox("./shaders/skybox.vs.glsl","./shaders/skybox.fs.glsl");

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
  std::unique_ptr<Sphere> sphere(new Sphere);
  std::vector<std::unique_ptr<Object>> vectorObject;
  vectorObject.emplace_back(std::move(cube));
  vectorObject.emplace_back(std::move(sphere));


  // Menu
  Menu menu;
  menu.setVisibility(MENU);
  Cube player;

  Scene game(std::move(vectorObject),camera);
  float speed = 0.05;
  float begin = 0;

  int startTicksRight=0;
  int startTicksLeft=0;

  bool has_jump = false;
  int jump = 0;

  GLuint texture = TextureLoader::LoadTexture("./elt/texture/ecran_debut_RUNNER_2.png");
  Skybox skybox;

  int z = 0;
  int zTranslation = 0;
  int has_turned = 0;



  // Application loop:

  bool done = false;
  while(!done) {


      if (TEST)
      {
        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      }

      if ( has_jump == true )
      {
        jump ++;
        if (jump == 40)
        {
          has_jump = false;
          jump = 0;
          hero.down();
        }
      }


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

        shader3DTex.use();
        glActiveTexture(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,texture);
        shader3DTex.setViewMatrix(camera->getViewMatrix(),glm::mat4(1.0));
        shader3DTex.setUniformMatrix();
        menu.displayMenu();
        glBindTexture(GL_TEXTURE_2D,0);

      }


      if (GAME)
      {

        // Event loop:
        SDL_Event e;

        while(windowManager.pollEvent(e)) {

            if (e.type == SDL_KEYDOWN){
              camera->onKeyboardEvent(e);
              if (e.key.keysym.sym  == SDLK_ESCAPE)
              {
                menu.setVisibility(true);
                GAME = false; //A changer pour faie un mode popUp
                glUseProgram(0);
              }


              if (e.key.keysym.sym  == SDLK_z)
              {
                if (has_jump == false)
                {
                  hero.up();
                  has_jump = true;
                }
              }
              if (e.key.keysym.sym  == SDLK_q)
              {

                if (startTicksLeft != 0 && (SDL_GetTicks()-startTicksLeft)<300)
                {

                  if (ppmCool.map().element(hero.getX(),0,hero.getZ())!=nullptr)
                  {
                    if (ppmCool.map().element(hero.getX(),0,hero.getZ())->getType() == "left")
                    {

                      if (zTranslation == 1)
                      {
                        zTranslation = 0;
                      }

                      ppmCool.map().translateMap(hero.getX(),hero.getZ());
                      hero.translate(hero.getX(),hero.getZ());
                      ppmCool.map().rotateLeft();
                      ppmCool.map().translateMap(-3,-1);
                      hero.translate(-3,-1);

                      startTicksRight = 0;
                      begin = 0;

                    }
                  }

                }
                else
                {
                  startTicksLeft = SDL_GetTicks();
                  if(ppmCool.map().element(hero.getX()-1,hero.getY(),hero.getZ())!=nullptr)
                  {
                    if (ppmCool.map().element(hero.getX()-1,hero.getY(),hero.getZ())->getType()=="Gap")
                    {
                      std::cout<<"GAP !"<<std::endl;
                      return 0;
                    }
                  }
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
                      has_turned ++;
                      if (has_turned > 1)
                      {
                        zTranslation = 1;
                      }

                      ppmCool.map().translateMap(hero.getX(),hero.getZ());
                      hero.translate(hero.getX(),hero.getZ());
                      std::cout<<" ( "<<hero.getX()<<" , "<<hero.getZ()<<" ) "<<std::endl;
                      ppmCool.map().rotateRight();
                      ppmCool.map().translateMap(-1,-1);
                      hero.translate(-1,-1);
                      std::cout<<" ( "<<hero.getX()<<" , "<<hero.getZ()<<" ) "<<std::endl;

                      startTicksRight = 0;
                      begin = 0;

                    }
                  }


                }
                else
                {
                  startTicksRight = SDL_GetTicks();
                  if(ppmCool.map().element(hero.getX()+1,hero.getY(),hero.getZ())!=nullptr)
                  {
                    if (ppmCool.map().element(hero.getX()+1,hero.getY(),hero.getZ())->getType()=="Gap")
                    {
                      std::cout<<"GAP !"<<std::endl;
                      return 0;
                    }
                  }
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
            projection *=glm::translate(glm::mat4(1),glm::vec3(hero.getX()+zTranslation,hero.getY(),0));

            shader3DTex.use();
            glActiveTexture(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,texture);
            shader3DTex.setViewMatrix(camera->getViewMatrix(),projection);
            shader3DTex.setUniformMatrix2();
            std::cout<<" ( "<<hero.getX()<<" , "<<hero.getZ()<<" ) "<<std::endl;
            player.draw();
            glBindTexture(GL_TEXTURE_2D,0);

            // Draw skybox as last
            projection = glm::perspective( (float) - 50, ( float )800/( float )600, 0.1f, 1000.0f );
            glDepthFunc( GL_LEQUAL );  // Change depth function so depth test passes when values are equal to depth buffer's content
            shaderSkybox.use( );
            shaderSkybox.setViewMatrix(camera->getViewMatrix(),projection);
            shaderSkybox.setUniformMatrix2();

            skybox.displaySkybox();


          }
          if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)!=nullptr)
          {

            if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Coin")
            {
              std::cout<< " COIN !  "<<std::endl;
              ppmCool.map().eraseElement(hero.getX(),hero.getY(),hero.getZ()+0.05);
              m_score ++;
            }

            else if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Obstacle")
            {
              std::cout<< " GAME OVER "<<std::endl;
              std::cout<< "VOTRE SCORE EST DE : "<<m_score<<std::endl;
              return 0;
            }

            else if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Gap")
            {
              std::cout<< " GAP ! "<<std::endl;
            }

            else if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Wall")
            {
              std::cout<< " Wall ! "<<std::endl;
            }

            else if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "End")
            {
              std::cout<< " YOU WIN ! "<<std::endl;
              return 1;
            }

          }




          }

        //Update the display
        glBindTexture(GL_TEXTURE_2D,0);
        windowManager.swapBuffers();


    }

  return EXIT_SUCCESS;
}
