
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
bool Font::loadFont(AppManager &app){

   SDL_Surface *ecran = NULL, *texte = NULL;
    SDL_Rect position;
    SDL_Event event;
    TTF_Font *police = NULL;
    SDL_Color couleurNoire = {1, 1, 1};
    int continuer = 1;
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    ecran = SDL_SetVideoMode(app.getAppWidth(), app.getAppHeight(), 32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption(app.getWindowName().c_str(), NULL);

    // Chargement de la police 
    police = TTF_OpenFont(this->getFontPath().c_str(), 65);
    std::cout << "Path : " << std::endl;

    // Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) 
    // segfault
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
        SDL_BlitSurface(texte, NULL, ecran, &position); //Blit du texte
        SDL_Flip(ecran);
    }

    TTF_CloseFont(police);
    TTF_Quit();
    SDL_FreeSurface(texte);
    SDL_Quit();
 
  return true;
}*/

// see https://stackoverflow.com/questions/22852226/c-sdl2-how-to-regularly-update-a-renderered-text-ttf