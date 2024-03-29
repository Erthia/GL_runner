#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <glimac/Image.hpp>

#include <memory>

using namespace glimac;
class TextureLoader
{
public:

  /// Load Texture method
  /// param FilePath : contain filepath of the texture
  static GLuint LoadTexture( const char* FilePath )
  {

    std::unique_ptr<Image> pImage;
    pImage = loadImage(FilePath);
    GLuint texture;
    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_2D,texture);
  	glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,pImage->getWidth(),
  	             pImage->getHeight(),0,GL_RGBA,GL_FLOAT,pImage->getPixels());
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  	glBindTexture(GL_TEXTURE_2D,0);

    return texture;
  }

  /// Load Texture for the skybox
  /// param faces : vector which contains 6 filephaths for the 6 image of the skybox
  static GLuint LoadCubeMap( std::vector<const char*> faces )
  {
    std::unique_ptr<Image> pImage;
    GLuint texture;

    glGenTextures(1,&texture);
    glBindTexture(GL_TEXTURE_CUBE_MAP,texture);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    for (unsigned int i = 0; i < faces.size(); i++)
    {


      pImage = loadImage(faces[i]);
    	glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i,0,GL_RGBA,pImage->getWidth(),
    	             pImage->getHeight(),0,GL_RGBA,GL_FLOAT,pImage->getPixels());
     pImage.reset(nullptr);
    }

  	glBindTexture(GL_TEXTURE_CUBE_MAP,0);

    return texture;
  }


};
