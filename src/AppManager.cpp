#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/cube.hpp>
#include <glimac/Cone.hpp>
#include <glimac/Object.hpp>
#include <glimac/Program.hpp>
#include "TrackballCamera.hpp"
#include <glimac/FilePath.hpp>
#include <glimac/Image.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/Grid.hpp>
#include <vector>
#include <cstdlib>
#include <GLFW/glfw3.h>
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
#include "Coin.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Obstacle.hpp"
#include "Gap.hpp"
#include "Map.hpp"

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

  //  Cube
  std::unique_ptr<Cube> cube(new Cube);
  //std::unique_ptr<Cone> cone = std::unique_ptr<Cone> (new Cone(1,11,1,1));

  std::vector<std::unique_ptr<Object>> vectorObject;
  vectorObject.emplace_back(std::move(cone));
  // Menu
  Menu menu;


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



        shader3D.use();
        shader3D.setViewMatrix(camera->getViewMatrix(),glm::mat4(1.0));
        shader3D.setUniformMatrix();

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

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          game.loadScene(map);

          shader3D.use();
          shader3D.setViewMatrix(camera->getViewMatrix(),glm::mat4(1.0));
          shader3D.setUniformMatrix();






        }
        //Update the display
        windowManager.swapBuffers();

      }
  return EXIT_SUCCESS;
}
