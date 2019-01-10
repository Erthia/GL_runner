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
#include <glimac/ShaderL.hpp>
#include <vector>
#include <cstdlib>

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
#include "Scores.hpp"
#include "TextureLoader.hpp"
#include "Skybox.hpp"
#include "Coin.hpp"
#include "Font.hpp"
#include "SDL/SDL_mixer.h"
#include "lightShader.hpp"



#include <memory>

static const char *NYAN = "elt/sound/nyancat.wav";

AppManager::AppManager()
{}

int AppManager::start(char** argv)
{

  bool MENU = true;
  bool SCORE = false;
  bool GAME = false;
  bool TEST = false;

// Initialize and Open Window
  SDLWindowManager windowManager(m_width,m_height,"SpacIMAC RUN");
  Mix_OpenAudio(22050, AUDIO_S16SYS, 2, 640);
    Mix_Music *nyancat = Mix_LoadMUS(NYAN);
  Mix_PlayMusic(nyancat, 1);

// test debug audio
int flags = MIX_INIT_OGG;
int result = 0;
if (flags != (result = Mix_Init(flags))) {
        printf("Could not initialize mixer (result: %d).\n", result);
        printf("Mix_Init: %s\n", Mix_GetError());
        exit(1);
}


// Initialize glew for OpenGL3+ support
  GLenum glewInitError = glewInit();
  if(GLEW_OK != glewInitError) {
      std::cerr << glewGetErrorString(glewInitError) << std::endl;
      return EXIT_FAILURE;
  }

// SHADER
  PerspectiveShader shader3D;
  PerspectiveShader shaderBlue("./shaders/blue.fs.glsl");
  PerspectiveShader shader3DTex("./shaders/Tex3D.fs.glsl");
  PerspectiveShader shaderSkybox("./shaders/skybox.vs.glsl","./shaders/skybox.fs.glsl");

  std::vector<PerspectiveShader*> shaderVector;
  shaderVector.push_back(&shader3D);
  shaderVector.push_back(&shaderBlue);
  shaderVector.push_back(&shader3DTex);


// CAMERA
  std::shared_ptr<TrackballCamera> camera(new TrackballCamera);

// MOTOR GAME
  glEnable(GL_DEPTH_TEST);

  motor_game::PPMreader theReader("test_01.ppm");
  motor_game::PPM ppmCool=theReader.readFile();


  motor_game::Map map = ppmCool.map();
  motor_game::Scores scoreTable;
  Hero hero = ppmCool.hero();
  hero.setSpeed(0.05);

  float begin = 0;

  int startTicksRight=0;
  int startTicksLeft=0;

  bool has_jump = false;
  int jump = 0;
  int zTranslation = 0;
  int has_turned = 0;


  std::unique_ptr<Cube> cube(new Cube);
  std::unique_ptr<Sphere> sphere(new Sphere);
  std::vector<std::unique_ptr<Object>> vectorObject;
  vectorObject.emplace_back(std::move(cube));
  vectorObject.emplace_back(std::move(sphere));

// TEXTURE

  GLuint textureMenu;
  GLuint textureMenu1 = TextureLoader::LoadTexture("./elt/texture/ecran_debut_RUNNER_2.png");
  GLuint textureMenu2 = TextureLoader::LoadTexture("./elt/texture/ecran_pause_RUNNER_2.png");
  GLuint texturePlayer = TextureLoader::LoadTexture("./elt/texture/spaceplayer.jpg");
  GLuint textureScore = TextureLoader::LoadTexture("./elt/texture/ecran_score_RUNNER.png");
  GLuint textureGameOver = TextureLoader::LoadTexture("./elt/texture/ecran_GAME_OVER.png");
  std::vector<GLuint*> textureVector;
  textureVector.push_back(&texturePlayer);


  Skybox skybox;
  Menu menu;
  menu.setVisibility(MENU);
  Menu score;
  score.setVisibility(SCORE);
  Cube player;
  Scene game(std::move(vectorObject),camera,textureVector,shaderVector);


  // font
  Font font("elt/ttf/starjedi.ttf");


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


      if (menu.visibility() == true)
      {
        // Event loop:


        if (menu.type() == 2)
        {
          textureMenu = textureMenu2;

        }
        else if(menu.type() == 3)
        {
          textureMenu = textureGameOver;

        }

        else
        {
          textureMenu = textureMenu1;
        }

        SDL_Event e;
        while(windowManager.pollEvent(e)) {
            if (menu.type() == 2)
            {
              if (e.type == SDL_KEYDOWN){

                if (e.key.keysym.sym  == SDLK_ESCAPE)
                {

                    menu.setVisibility(false);
                    GAME = true;
                    glUseProgram(0);

                }
              }

              if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
              {
                if (menu.onMouseEvent(windowManager.getMousePosition()) == 1)
                {
                  motor_game::PPMreader theReader2("test_01.ppm");
                  motor_game::PPM ppm = theReader2.readFile();
                  map = ppm.map();
                  hero = ppm.hero();
                  hero.setSpeed(0.05);

                  begin = 0;

                  startTicksRight=0;
                  startTicksLeft=0;

                  has_jump = false;
                  jump = 0;
                  zTranslation = 0;
                  has_turned = 0;
                  GAME = 1;
                  glUseProgram(0);

                }

              }


              if(e.type == SDL_QUIT) {
                  done = true; // Leave the loop after this iteration
              }


            }


            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT)
            {
              if (menu.onMouseEvent(windowManager.getMousePosition()) == 1)
              {
                GAME = 1;
                glUseProgram(0);
              }
              if (menu.onMouseEvent(windowManager.getMousePosition()) == 2)
              {
                SCORE = 1;
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
        glBindTexture(GL_TEXTURE_2D,textureMenu);
        shader3DTex.setViewMatrix(glm::mat4(1.0),glm::mat4(1.0));
        shader3DTex.setUniformMatrix();
        menu.displayMenu();
        glBindTexture(GL_TEXTURE_2D,0);


      }

      if (SCORE)
      {
        // Event loop:
        SDL_Event e;
        // test score
       std::multimap<long,std::string>::const_iterator it;
          for(it=scoreTable.multimap().begin(); it!=scoreTable.multimap().end(); it++)
            std::cout << it->second << " : " << it->first << std::endl;
        while(windowManager.pollEvent(e)) {

            if(e.type == SDL_MOUSEBUTTONDOWN && e.button.button == SDL_BUTTON_LEFT){

              if (score.onMouseEvent(windowManager.getMousePosition()) == 1)
              {
                SCORE = 0;
                menu.setVisibility(true);
                std::cout << "test menu " << std::endl;
                GAME = 1;
                glUseProgram(0);
              }
              if (score.onMouseEvent(windowManager.getMousePosition()) == 2)
              {

                SCORE = 0;
                menu.setVisibility(true);
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
        glBindTexture(GL_TEXTURE_2D,textureScore);
        shader3DTex.setViewMatrix(glm::mat4(1.0),glm::mat4(1.0));
        shader3DTex.setUniformMatrix();
        score.displayMenu();
        glBindTexture(GL_TEXTURE_2D,0);


      }
      if (menu.type() == 3)
      {
        //save score
        //print the scores
         scoreTable.add(std::pair<long,std::string>(m_score, "Anonyme"));
         scoreTable.save("Score.ttf");
        // Event loop:
        SDL_Event e;
        while(windowManager.pollEvent(e)) {

            if(e.type == SDL_QUIT) {
                done = true; // Leave the loop after this iteration
                 Mix_FreeMusic(nyancat);
                 Mix_Quit();

                return 0;
            }
        }

        //Render loop:

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        shader3DTex.use();
        glActiveTexture(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,textureGameOver);
        shader3DTex.setViewMatrix(camera->getViewMatrix(),glm::mat4(1.0));
        shader3DTex.setUniformMatrix();
        menu.displayMenu();
        glBindTexture(GL_TEXTURE_2D,0);


      }


      if (GAME)
      {
        //font.loadFont();
        // Event loop:
        SDL_Event e;

        while(windowManager.pollEvent(e)) {

            if (e.type == SDL_KEYDOWN){
              camera->onKeyboardEvent(e);
              if (e.key.keysym.sym  == SDLK_ESCAPE)
              {

                menu.setVisibility(true);
                menu.type(2);
                GAME = false;
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

                  if (map.element(hero.getX(),0,hero.getZ())!=nullptr)
                  {
                    if (map.element(hero.getX(),0,hero.getZ())->getType() == "left")
                    {

                      if (zTranslation == 1)
                      {
                        zTranslation = 0;
                      }

                      map.translateMap(hero.getX(),hero.getZ());
                      hero.translate(hero.getX(),hero.getZ());
                      map.rotateLeft();
                      map.translateMap(-3,-1);
                      hero.translate(-3,-1);

                      startTicksRight = 0;
                      begin = 0;

                    }
                  }

                }
                else
                {
                  startTicksLeft = SDL_GetTicks();
                  if(map.element(hero.getX()-1,hero.getY(),hero.getZ())!=nullptr)
                  {
                    if (map.element(hero.getX()-1,hero.getY(),hero.getZ())->getType()=="Gap")
                    {
                      std::cout<<"GAP !"<<std::endl;
                      menu.type(3);
                    GAME = 0;
                      //return 0;
                      std::cout<< " GAME OVER "<<std::endl;
                      std::cout<< "VOTRE SCORE EST DE : "<<m_score<<std::endl;

                     /* GAME = false;
                      menu.type(2);
                      menu.setVisibility(true);*/

                    }
                    if (map.element(hero.getX()-1,hero.getY(),hero.getZ())->getType()=="Coin")
                    {
                      hero.moveLeft();
                      map.eraseElement(hero.getX(),hero.getY(),hero.getZ()+0.05);
                      m_score ++;
                    }

                  }
                  if(map.element(hero.getX()-1,hero.getY(),hero.getZ())==nullptr)
                  {
                    hero.moveLeft();
                  }


                }





              }
              if (e.key.keysym.sym  == SDLK_d)
              {

                if (startTicksRight != 0 && (SDL_GetTicks()-startTicksRight)<300)
                {

                  if (map.element(hero.getX(),0,hero.getZ())!=nullptr)
                  {
                    if (map.element(hero.getX(),0,hero.getZ())->getType() == "right")
                    {
                      has_turned ++;
                      if (has_turned > 1)
                      {
                        zTranslation = 1;
                      }

                      map.translateMap(hero.getX(),hero.getZ());
                      hero.translate(hero.getX(),hero.getZ());
                      map.rotateRight();
                      map.translateMap(-1,-1);
                      hero.translate(-1,-1);

                      startTicksRight = 0;
                      begin = 0;

                    }
                  }


                }
                else
                {
                  startTicksRight = SDL_GetTicks();
                  if(map.element(hero.getX()+1,hero.getY(),hero.getZ())!=nullptr)
                  {
                    if (map.element(hero.getX()+1,hero.getY(),hero.getZ())->getType()=="Gap")
                    {
                      std::cout<<"GAP !"<<std::endl;
                      menu.type(3);
                      GAME = 0;
                      //return 0;
                      std::cout<< " GAME OVER "<<std::endl;
                      std::cout<< "VOTRE SCORE EST DE : "<<m_score<<std::endl;
/*
                      GAME = false;
                      menu.type(2);
                      menu.setVisibility(true);*/

                    }
                    if (map.element(hero.getX()+1,hero.getY(),hero.getZ())->getType()=="Coin")
                    {
                      hero.moveRight();
                      m_score += 1;
                      map.eraseElement(hero.getX(),hero.getY(),hero.getZ()+0.05);

                    }
                  }
                  if(map.element(hero.getX()+1,hero.getY(),hero.getZ()+0.05)==nullptr)
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

          // Render loop:
          if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)==nullptr)
          {
            begin -=hero.getSpeed();
            hero.run();

            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
            game.loadScene(map,begin);

            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));

            projection *=glm::translate(glm::mat4(1),glm::vec3(map.projectionX(),map.projectionY(),map.projectionZ()));
            projection *=glm::translate(glm::mat4(1),glm::vec3(hero.getX()+zTranslation,hero.getY(),0));

            shader3DTex.use();
            glActiveTexture(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D,texturePlayer);
            shader3DTex.setViewMatrix(camera->getViewMatrix(),projection);
            shader3DTex.setUniformMatrix2();
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
          if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)!=nullptr)
          {

            if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Coin")
            {
              map.eraseElement(hero.getX(),hero.getY(),hero.getZ()+0.05);
              m_score ++;
            }

            else if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Obstacle")
            {
              std::cout<< " GAME OVER "<<std::endl;
              std::cout<< "VOTRE SCORE EST DE : "<<m_score<<std::endl;

              GAME = false;
              menu.type(3);
              GAME = 0;
             // menu.setVisibility(true);
            }

            else if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "Gap")
            {
              std::cout<< " GAME OVER "<<std::endl;
              std::cout<< "VOTRE SCORE EST DE : "<<m_score<<std::endl;

              GAME = false;
              menu.type(3);
              GAME = 0;
            }


            else if (map.element(hero.getX(),hero.getY(),hero.getZ()+0.05)->getType() == "End")
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
