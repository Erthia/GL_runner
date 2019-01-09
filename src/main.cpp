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
//#include <GLFW/glfw3.h>
#include <fstream>

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
#include "Font.hpp"

#include <SDL/SDL_ttf.h>
//#include <utils.cpp>


using namespace glimac;



/*
GLuint texture[100];
SDL_Rect area[100]; 
void loadString(const char * text, SDL_Color clr, int txtNum, const char* file, int ptsize){
    TTF_Font* tmpfont;
    SDL_Init(SDL_INIT_VIDEO);
    tmpfont = TTF_OpenFont("elt/ttf/starjedi.ttf", ptsize); 
    SDL_Surface *sText = SDL_DisplayFormatAlpha(TTF_RenderUTF8_Solid( tmpfont, text, clr ));
    area[txtNum].x = 0;area[txtNum].y = 0;area[txtNum].w = sText->w;area[txtNum].h = sText->h;
    glGenTextures(1, &texture[txtNum]);
    glBindTexture(GL_TEXTURE_2D, texture[txtNum]);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, sText->w, sText->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sText->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    SDL_FreeSurface(sText);
    TTF_CloseFont(tmpfont);
     SDL_Quit();
 }

 void drawText(float coords[3], int txtNum) {
     glBindTexture(GL_TEXTURE_2D, texture[txtNum]);
     glEnable(GL_TEXTURE_2D);
     glBegin(GL_QUADS); {
     glTexCoord2f(0, 0); glVertex3f(coords[0], coords[1], coords[2]);
     glTexCoord2f(1, 0); glVertex3f(coords[0] + area[txtNum].w, coords[1], coords[2]);
     glTexCoord2f(1, 1); glVertex3f(coords[0] + area[txtNum].w, coords[1] + area[txtNum].h, coords[2]);
     glTexCoord2f(0, 1); glVertex3f(coords[0], coords[1] + area[txtNum].h, coords[2]); 
     } glEnd();
     glDisable(GL_TEXTURE_2D);
}*/

/*
void RenderText(std::string message, SDL_Color color, int x, int y, int size) { 
    glMatrixMode(GL_MODELVIEW); 
    glPushMatrix(); 
    glLoadIdentity(); 

    gluOrtho2D(0, 800, 0, 600); // m_Width and m_Height is the resolution of window 
    glMatrixMode(GL_PROJECTION); 
    glPushMatrix(); 
    glLoadIdentity(); 

    glDisable(GL_DEPTH_TEST); 
    glEnable(GL_TEXTURE_2D); 
    glEnable(GL_BLEND); 
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); 

    GLuint texture; 
    glGenTextures(1, &texture); 
    glBindTexture(GL_TEXTURE_2D, texture); 

    TTF_Font * font = TTF_OpenFont("elt/ttf/starjedi.ttf", size); 
    SDL_Surface * sFont = TTF_RenderText_Blended(font, message.c_str(), color); 

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sFont->pixels); 

    glBegin(GL_QUADS); 
    { 
    glTexCoord2f(0,0); glVertex2f(x, y); 
    glTexCoord2f(1,0); glVertex2f(x + sFont->w, y); 
    glTexCoord2f(1,1); glVertex2f(x + sFont->w, y + sFont->h); 
    glTexCoord2f(0,1); glVertex2f(x, y + sFont->h); 
    } 
    glEnd(); 

    glDisable(GL_BLEND); 
    glDisable(GL_TEXTURE_2D); 
    glEnable(GL_DEPTH_TEST); 

    glMatrixMode(GL_PROJECTION); 
    glPopMatrix(); 
    glMatrixMode(GL_PROJECTION); 
    glPopMatrix(); 

    glDeleteTextures(1, &texture); 
    TTF_CloseFont(font); 
    SDL_FreeSurface(sFont); 
} */

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

  //motor_game::PPMreader theReader("level_01_ASCII.ppm");
  //motor_game::PPM ppmCool=theReader.readFile();

  //ppmCool.map().translateMap(-5,-5);
//  ppmCool.map().rotateRight();

  //ppmCool.map().rotateLeft();
//  ppmCool.map().printElement();
  //std::cout<<ppmCool.map().element(1,1,17)->getType()<<std::endl;


  AppManager App;
  App.start(argv);
  SDL_Color color = {255, 0, 0, 0}; // Red 
  Font font("elt/ttf/starjedi.ttf");
  font.loadFont(App);
  /*
RenderText("Hello World", color, 5, 10, 12); */
    //loadString("bojnjour", color, 1, 20);
 // drawText("bonjour");

  return EXIT_SUCCESS;
}
