
#include <iostream>
#include "Font.hpp"

Font::Font()
{}

Font::Font(const std::string &fontPath)
  :m_fontPath(fontPath)
{}


void Font::setFontPath(const std::string &fontPath) {
  m_fontPath = fontPath;
}

Font::~Font(){}


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
/*
void Font::drawText(const std::string text, TTF_Font* tmpfont) {
    SDL_Rect area;
    SDL_Color clrFg = {0,0,255,0};
    SDL_Surface *sText = TTF_RenderUTF8_Blended(tmpfont, text.c_str(), clrFg );
    //SDL_DisplayFormatAlpha(TTF_RenderUTF8_Blended(tmpfont, text, clrFg ));
    std::cout << sText->h;
    //area.x = 0;area.y = 0;area.w = sText->w;area.h = sText->h;
    SDL_Surface* temp = SDL_CreateRGBSurface(SDL_HWSURFACE|SDL_SRCALPHA,sText->w,sText->h,32,0x000000ff,0x0000ff00,0x00ff0000,0x000000ff);
    SDL_BlitSurface(sText, &area, temp, NULL);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, sText->w, sText->h, 0, GL_RGBA, GL_UNSIGNED_BYTE, temp->pixels);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
    glEnable(GL_TEXTURE_2D);
    glBegin(GL_QUADS); {
        glTexCoord2d(0, 0); glVertex3f(0, 0, 0);
        glTexCoord2d(1, 0); glVertex3f(0 + sText->w, 0, 0);
        glTexCoord2d(1, 1); glVertex3f(0 + sText->w, 0 + sText->h, 0);
        glTexCoord2d(0, 1); glVertex3f(0, 0 + sText->h, 0); 
    } glEnd();
    glDisable(GL_TEXTURE_2D);
    SDL_FreeSurface( sText );
    SDL_FreeSurface( temp );
} 
*/


bool Font::loadFont(AppManager &app){

   SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {1, 1, 1};
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    //ecran = SDL_SetVideoMode(app.getAppWidth(), app.getAppHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    ecran = SDL_SetVideoMode(app.getAppWidth(), app.getAppHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(app.getWindowName().c_str(), NULL);

    // Chargement de la police 
    police = TTF_OpenFont(this->getFontPath().c_str(), 65);
    std::cout << "Path : " << std::endl;

    // Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) 
    // segfault
    texte = TTF_RenderText_Blended(police, "Test scores !", couleurNoire);

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
        SDL_BlitSurface(texte, NULL, ecran, &position); //Blit du texte
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
 
  return true;
}

// see https://stackoverflow.com/questions/22852226/c-sdl2-how-to-regularly-update-a-renderered-text-ttf