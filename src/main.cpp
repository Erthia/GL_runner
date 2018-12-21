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
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
//#include <GLFW/glfw3.h>
#include <fstream>
#include <SDL/SDL_ttf.h>
#include "AppManager.hpp"
#include "ExceptIMAC.hpp"
#include "Hero.hpp"
#include "PrintableElement.hpp"
#include "Character.hpp"
#include "End.hpp"
#include "Gap.hpp"
#include "PPM.hpp"
#include "PPMreader.hpp"
#include "Map.hpp"
#include "Wall.hpp"
#include "Coin.hpp"
#include "Element.hpp"
#include "Texture.hpp"

//#include <utils.cpp>


using namespace glimac;

std::string readFile(const char *filePath) {
    std::string content;
    std::ifstream fileStream(filePath, std::ios::in);

    if(!fileStream.is_open()) {
        std::cerr << "Could not read file " << filePath << ". File does not exist." << std::endl;
        return "";
    }

    std::string line = "";
    while(!fileStream.eof()) {
        std::getline(fileStream, line);
        content.append(line + "\n");
    }

    fileStream.close();
    return content;
}

GLuint LoadShader(const char *vertex_path, const char *fragment_path) {
    GLuint vertShader = glCreateShader(GL_VERTEX_SHADER);
    GLuint fragShader = glCreateShader(GL_FRAGMENT_SHADER);

    // Read shaders
    std::string vertShaderStr = readFile(vertex_path);
    std::string fragShaderStr = readFile(fragment_path);
    const char *vertShaderSrc = vertShaderStr.c_str();
    const char *fragShaderSrc = fragShaderStr.c_str();

    GLint result = GL_FALSE;
    int logLength;


    // Compile vertex shader
    std::cout << "Compiling vertex shader." << std::endl;
    glShaderSource(vertShader, 1, &vertShaderSrc, NULL);
    glCompileShader(vertShader);

    // Check vertex shader
    glGetShaderiv(vertShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(vertShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> vertShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(vertShader, logLength, NULL, &vertShaderError[0]);
    std::cout << &vertShaderError[0] << std::endl;

    // Compile fragment shader
    std::cout << "Compiling fragment shader." << std::endl;
    glShaderSource(fragShader, 1, &fragShaderSrc, NULL);
    glCompileShader(fragShader);

    // Check fragment shader
    glGetShaderiv(fragShader, GL_COMPILE_STATUS, &result);
    glGetShaderiv(fragShader, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> fragShaderError((logLength > 1) ? logLength : 1);
    glGetShaderInfoLog(fragShader, logLength, NULL, &fragShaderError[0]);
    std::cout << &fragShaderError[0] << std::endl;

    std::cout << "Linking program" << std::endl;
    GLuint program = glCreateProgram();
    glAttachShader(program, vertShader);
    glAttachShader(program, fragShader);

    glBindAttribLocation(program, 3, "aVertexPosition");
    glBindAttribLocation(program, 8, "aVertexColor");

    glLinkProgram(program);

    glGetProgramiv(program, GL_LINK_STATUS, &result);
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &logLength);
    std::vector<char> programError( (logLength > 1) ? logLength : 1 );
    glGetProgramInfoLog(program, logLength, NULL, &programError[0]);
    std::cout << &programError[0] << std::endl;

    glDeleteShader(vertShader);
    glDeleteShader(fragShader);

    return program;
}
/********************************
END - IF YOU'RE USING GLSL VERSION 130
********************************/

int main(int argc, char** argv) {

 // AppManager App;
 // App.start(argv);
    SDL_Surface *ecran = NULL, *texte = NULL;

    SDL_Rect position;

    SDL_Event event;

    TTF_Font *police = NULL;

    SDL_Color couleurNoire = {0, 0, 0};

    int continuer = 1;


    SDL_Init(SDL_INIT_VIDEO);

    TTF_Init();


    ecran = SDL_SetVideoMode(640, 480, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);


    /* Chargement de la police */

    police = TTF_OpenFont("elt/ttf/starjedi.ttf", 65);

    /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */

    texte = TTF_RenderText_Blended(police, "Salut Emilie !", couleurNoire);


    while (continuer)

    {

        SDL_WaitEvent(&event);

        switch(event.type)

        {

            case SDL_QUIT:

                continuer = 0;

                break;

        }


        SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));



        position.x = 60;

        position.y = 370;

        SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */

        SDL_Flip(ecran);

    }


    TTF_CloseFont(police);

    TTF_Quit();


    SDL_FreeSurface(texte);

    SDL_Quit();

 /* TTF_Init();

  if(TTF_Init() == -1)
{
    fprintf(stderr, "Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());
    exit(EXIT_FAILURE);
}
  font = TTF_OpenFont("elt/ttf/starjedi.ttf", 65);
  SDL_Color white = {1, 1, 0};
  text = TTF_RenderText_Blended(font, "Salut les Zér0s !", white);
  TTF_CloseFont(font);
  TTF_Quit();*/

  return EXIT_SUCCESS;
}
