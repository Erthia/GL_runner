#pragma once

#include <GL/glew.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_ttf.h"
//#include "AppManager.hpp"

class Font
{
public:
  /// \brief default constructor
  Font();


  /// constructor with parameters
  /// param filePath to know which font and where to load it
  Font(const std::string &fontPath);

  int puissance2sup(const int i);


  /// setter for filePath
  void setFontPath(const std::string &fontPath);

  inline std::string getFontPath() const{
    return m_fontPath;
  }

  /// \brief default destructor
  ~Font();


 // bool loadFont(AppManager *app); 
  void loadFont(); 

  
private:
  std::string m_fontPath; /*!< path and name of font to load */
};
