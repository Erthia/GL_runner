#pragma once

#include <vector>
#include <memory>
#include <GL/glew.h>
/*
-L/include/SDL2_image-2.0.4
*/
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"

class Texture
{
public:
  /// \brief default constructor
  Texture();


  /// constructor with parameters
  /// param filePath to know which texture and where to load it
  Texture(const std::string &filePath);

  /// brief getter for the texture id
  inline GLuint getID() const {
    return m_id;
  }

  /// setter for filePath
  void setImagePath(const std::string &filePath);

  /// \brief default destructor
  ~Texture();

  //Methods
  /// \ method to load the texture
  /// \handles filePath errors
  bool loadTexture(); 

  SDL_Surface* reversePixels(SDL_Surface *sourceImg) const;
  

private:
  GLuint m_id;  /*!< id of our texture */
  std::string m_filePath; /*!< path and name of texture to load */
};
