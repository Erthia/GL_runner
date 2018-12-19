#include <glimac/SDLWindowManager.hpp>
#include <GL/glew.h>
#include <iostream>
#include <glimac/common.hpp>
#include <glimac/Sphere.hpp>
#include <glimac/cube.hpp>
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
  //TrackballCamera camera(0,0,0);
  std::shared_ptr<TrackballCamera> camera(new TrackballCamera);

// MOTOR GAME
  glEnable(GL_DEPTH_TEST);

  //  Cube
  std::unique_ptr<Cube> cube(new Cube);
  cube->x = 5;
  cube->y = 0;
  // Menu
  Menu menu;

  std::vector<std::unique_ptr<Object>> vectorObject;

  vectorObject.emplace_back(std::move(cube));
  vectorObject.emplace_back(new Grid);
  vectorObject.emplace_back(new Landmark);

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



        shaderRed.use();
        shaderRed.setViewMatrix(glm::mat4(1.0),glm::mat4(1.0));
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



          game.loadScene();



/***** UTILITAIRE **********************************************************/
/*
          shader3D.setViewMatrix(camera.getViewMatrix(),glm::mat4(1.0));
          shader3D.setUniformMatrix();

          landmark.draw();
          grid.draw();
*/
/**************************************************************************/



        }
        //Update the display
        windowManager.swapBuffers();

      }
  return EXIT_SUCCESS;
}
