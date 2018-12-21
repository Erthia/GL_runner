#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
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
#include "Font.hpp"
#include "Obstacle.hpp"
#include "Gap.hpp"
#include "Map.hpp"
#include "PPM.hpp"
#include "PPMreader.hpp"
#include "eyeCamera.hpp"
#include "Character.hpp"

#include <memory>

AppManager::AppManager()
{}

int AppManager::start(char** argv)
{

/** PLUS PROPRE A TROUVER **/

  bool GAME = false;

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

  motor_game::PPMreader theReader("level_01_ASCII.ppm");
  motor_game::PPM ppmCool=theReader.readFile();

  Hero hero = ppmCool.hero();
  hero.setSpeed(0.1);


/*** A changer ***/
  std::unique_ptr<Cube> cube(new Cube);
  std::vector<std::unique_ptr<Object>> vectorObject;
  vectorObject.emplace_back(std::move(cube));
  // Menu
  Menu menu;
  Cube player;
  Landmark landmark;
  Grid grid;


  motor_game::Map map(5,4,4);
  // Function PPM
  map.element(0,1,0,new Wall(glm::vec3(0,1,0)));
  for (unsigned int i= 0; i<map.x();i++)
  {
    for (unsigned int j=0;j<map.y();j++)
    {
      for (unsigned int k=0;k<map.z();k++)
      {
        map.element(i,0,k,new Floor(glm::vec3(i,j,k)));
      }
    }
  }

  Scene game(std::move(vectorObject),camera);
  float speed = 0.1;
  float begin = -hero.getZ();

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

                if (ppmCool.map().element(hero.getX()-1,hero.getY(),hero.getZ()) != nullptr)
                {
                  if ((ppmCool.map().element(hero.getX()-1,hero.getY(),hero.getZ())->getType()== "Obstacle"))
                  {
                    break;
                  }
                }
                else
                {
                  hero.moveLeft();
                }

              }
              if (e.key.keysym.sym  == SDLK_d)
              {
                if (ppmCool.map().element(hero.getX()+1,hero.getY(),hero.getZ()) != nullptr)
                {
                  if ((ppmCool.map().element(hero.getX()+1,hero.getY(),hero.getZ())->getType()== "Obstacle"))
                  {
                    break;
                  }
                }
                else
                {
                  hero.moveRight();
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

          if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+1) == nullptr)
          {

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            game.loadScene(ppmCool.map(),begin);
            begin -=speed;
            hero.run();
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
            projection *=glm::translate(glm::mat4(1),glm::vec3(hero.getX(),hero.getY(),0));
            shader3D.use();
            shader3D.setViewMatrix(camera->getViewMatrix(),projection);
            shader3D.setUniformMatrix2();
            player.draw();

          }

          if (ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+1)!= nullptr)
          {
            if ((ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+1)->getType()== "Wall"))
            {
              begin+=0;
            }
            if ((ppmCool.map().element(hero.getX(),hero.getY(),hero.getZ()+1)->getType()== "Obstacle"))
            {
              std::cout<<"Collision w/ Obstacle // GAME OVER"<<std::endl;
            }
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            game.loadScene(ppmCool.map(),begin);
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
            projection *=glm::translate(glm::mat4(1),glm::vec3(hero.getX(),hero.getY(),0));
            shader3D.use();
            shader3D.setViewMatrix(camera->getViewMatrix(),projection);
            shader3D.setUniformMatrix2();
            player.draw();

          }

        }
        //Update the display
        windowManager.swapBuffers();

      }
  return EXIT_SUCCESS;
}
