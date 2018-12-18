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
#include <glm/glm.hpp>
#include <glm/gtc/random.hpp>
#include <vector>
#include <cstdlib>
#include <GLFW/glfw3.h>
#include <fstream>
#include "AppManager.hpp"
#include "Menu.hpp"
#include "drawObject.hpp"

AppManager::AppManager()
{}

int AppManager::start(char** argv)
{

/** PLUS PROPRE A TROUVER **/

  bool GAME = false;

/********************************/

// Initialize and Open Window
  SDLWindowManager windowManager(800,600, "GLImac");


  // Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }

// SHADER
  FilePath applicationPath(argv[0]);
  Program program1 = loadProgram("./shaders/3d.vs.glsl",
                                "./shaders/normals.fs.glsl" );
  program1.use();
  GLint uModelMVMatrix = glGetUniformLocation(program1.getGLId(), "uMVMatrix");
  GLint uModelMVPMatrix = glGetUniformLocation(program1.getGLId(), "uMVPMatrix");
  GLint uNormalMatrix = glGetUniformLocation(program1.getGLId(), "uNormalMatrix");



  TrackballCamera camera(0,0,0);



  glEnable(GL_DEPTH_TEST);

  GLuint vbo[4];
  GLuint vao[5];
  //  Cube
  Cube cube;
  cube.vboManager(vbo[0]);
  cube.vaoManager(vao[0],vbo[0]);
  // Landmark
  Landmark landmark;
  landmark.vboManager(vbo[1]);
  landmark.vaoManager(vao[1],vbo[1]);
  // Grid
  Grid grid;
  grid.vboManager(vbo[2]);
  grid.vaoManager(vao[2],vbo[2]);
  // Menu
  Menu menu;
  menu.vboManager(vbo[3]);
  menu.vaoManager(vao[3],vbo[3]);

  glm::mat4 projMatrix,MVMatrix,NormalMatrix;

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
              int verify = menu.onMouseEvent(windowManager.getMousePosition());
              if (verify == 1)
                GAME = true;
            }

            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
        }

        //Render loop:

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        float a = 800.0/600.0;

        projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f);
        MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0));
        NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

        glm::mat4 mat1 = projMatrix * MVMatrix;
        glUniformMatrix4fv(uModelMVPMatrix,1,GL_FALSE,glm::value_ptr(mat1));
        glUniformMatrix4fv(uModelMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
        glUniformMatrix4fv(uNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));

        menu.displayMenu(vao[3]);
        // Update the display
        windowManager.swapBuffers();




      }

      if (GAME)
      {
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {

            if (e.type == SDL_KEYDOWN){
              camera.onKeyboardEvent(e);
              if (e.key.keysym.sym  == SDLK_ESCAPE)
              {
                GAME = false;
                menu.setVisibility(true);
              }
            }


            if (e.button.button == SDL_BUTTON_WHEELUP || e.button.button == SDL_BUTTON_WHEELDOWN )
              camera.onMouseWheelEvent(e);

            if (windowManager.isMouseButtonPressed(SDL_BUTTON_LEFT))
            {
              camera.onMouseEvent(e);
            }

            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
            }
          }

          // Render loop:

          glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

          float a = 800.0/600.0;

          projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f)*camera.getViewMatrix();
          MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*camera.getViewMatrix();
          NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

          glm::mat4 mat1 = projMatrix * MVMatrix;
          glUniformMatrix4fv(uModelMVPMatrix,1,GL_FALSE,glm::value_ptr(mat1));
          glUniformMatrix4fv(uModelMVMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
          glUniformMatrix4fv(uNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));

          draw3DObject(vao[0],cube.getVertexCount());

          glBindVertexArray(vao[1]);
              glDrawArrays(GL_LINES,0,landmark.getVertexCount());
          glBindVertexArray(0);

          glBindVertexArray(vao[2]);
              glDrawArrays(GL_LINES,0,grid.getVertexCount());
          glBindVertexArray(0);



          // Update the display
          windowManager.swapBuffers();

        }

      }
  return EXIT_SUCCESS;
}
