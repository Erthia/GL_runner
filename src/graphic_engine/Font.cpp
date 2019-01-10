
#include <iostream>
#include "Font.hpp"
#include <cmath>

Font::Font()
{}

Font::Font(const std::string &fontPath)
  :m_fontPath(fontPath)
{}


void Font::setFontPath(const std::string &fontPath) {
  m_fontPath = fontPath;
}

Font::~Font(){}

int Font::puissance2sup(const int i)
{
    double logbase2 = log(i) / log(2);
    return (int)round(pow(2.0, ceil(logbase2)));
}


//bool Font::loadFont(AppManager *app) {
void Font::loadFont() {  
    glMatrixMode(GL_MODELVIEW); 
    glPushMatrix(); 
    glLoadIdentity(); 

    //gluOrtho2D(0, app->getAppWidth(), 0, app->getAppHeight());
    gluOrtho2D(0, 800, 0, 800);
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

    //to add as font attribute
    std::string message = "hello";
    SDL_Color color = {255, 0, 0, 1}; 
    int x = 100;
    int y = 200;
    TTF_Init();


    if(TTF_Init()==-1) {
        std::cout << "TTF_Init: " << TTF_GetError() << std::endl;
        return;
    }

    TTF_Font * font = nullptr;
   font = TTF_OpenFont(this->getFontPath().c_str(), 200); 
    //font = TTF_OpenFont("elt/ttf/starjedi.ttf", 20); 
    SDL_Surface * sFont = TTF_RenderText_Blended(font, "message.c_str()", color); 

    if(!font) {
        std::cout << "TTF_OpenFont:" << TTF_GetError() << std::endl;
       return;
    }

    GLenum codagePixel;
    if (sFont->format->Rmask == 0x000000ff)
    {
        codagePixel = GL_RGBA;
    }
    else
    {
        #ifndef GL_BGRA
            #define GL_BGRA 0x80E1
        #endif
        codagePixel = GL_BGRA;
    }

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR); 
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); 
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sFont->w, sFont->h, 0, GL_BGRA, GL_UNSIGNED_BYTE, sFont->pixels); 

    glTexImage2D(GL_TEXTURE_2D, 0, 4, puissance2sup(sFont->w), puissance2sup(sFont->h), 0, codagePixel, GL_UNSIGNED_BYTE, NULL);
    glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, sFont->w, sFont->h, codagePixel, GL_UNSIGNED_BYTE, sFont->pixels);


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
     std::cout << "TEST FONT" << std::endl;


    glDeleteTextures(1, &texture); 
    TTF_CloseFont(font); 
    TTF_Quit();
    SDL_FreeSurface(sFont); 
    return;
} 
