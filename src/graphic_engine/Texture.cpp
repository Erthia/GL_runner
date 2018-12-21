/*#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>
#include <cmath>
#include <memory>
*/
#include <iostream>
#include "Texture.hpp"

Texture::Texture()
{}

Texture::Texture(const std::string &filePath)
  :m_id(0), m_filePath(filePath)
{}

/*
Texture::Texture()
{}*/

void Texture::setImagePath(const std::string &filePath) {
  m_filePath = filePath;
}

Texture::~Texture(){}


SDL_Surface* Texture::reversePixels(SDL_Surface *sourceImg) const{

  // copy of original surface without pixels
  SDL_Surface *reversedImg = SDL_CreateRGBSurface(0, sourceImg->w, sourceImg->h, 
  sourceImg->format->BitsPerPixel, sourceImg->format->Rmask, 
  sourceImg->format->Gmask, sourceImg->format->Bmask, sourceImg->format->Amask);

  // arrays stocking original pixels and reversed pixels
  unsigned char* ogPixels = (unsigned char*) sourceImg->pixels;
  unsigned char* reversedPixels = (unsigned char*) reversedImg->pixels;

  // reverse pixels

  for(int i = 0; i < sourceImg->h; i++)
  {
    for(int j = 0; j < sourceImg->w * sourceImg->format->BytesPerPixel; j++)
        reversedPixels[(sourceImg->w * sourceImg->format->BytesPerPixel * (sourceImg->h - 1 - i)) + j] = ogPixels[(sourceImg->w 
       * sourceImg->format->BytesPerPixel * i) + j];
  }

  return reversedImg;
}

bool Texture::loadTexture(){
  SDL_Surface *imageSDL = IMG_Load(m_filePath.c_str());

  // handles filepath errors 
  if(imageSDL == 0)
    {
      std::cout << "Error : " << SDL_GetError() << std::endl;
      return false;
    }

  SDL_Surface *imageReverse = reversePixels(imageSDL);
  SDL_FreeSurface(imageSDL);

  // generate id texture
  glGenTextures(1, &m_id);

  // bind
  glBindTexture(GL_TEXTURE_2D, m_id);

  GLenum internalFormat(0);
  GLenum format(0);

  // checks if there's an alpha composant or not
  if(imageReverse->format->BytesPerPixel == 3)
  {
    internalFormat = GL_RGB;

    if(imageReverse ->format->Rmask == 0xff)
      format = GL_RGB;

    else
      format = GL_BGR;
  }

  else if(imageReverse->format->BytesPerPixel == 4)
  {
    internalFormat = GL_RGBA;

    if(imageReverse ->format->Rmask == 0xff)
      format = GL_RGBA;

    else
      format = GL_BGRA;
  }
    
      else
      {
        std::cout << "Error, unknown file type" << std::endl;
        SDL_FreeSurface(imageReverse);
        return false;
      }

      // copy the pixels
      glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, imageReverse->w, imageReverse->h, 0, format, GL_UNSIGNED_BYTE, imageReverse->pixels);
      glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);


  // debind
  glBindTexture(GL_TEXTURE_2D, 0);

  SDL_FreeSurface(imageReverse);
  return true;
}



