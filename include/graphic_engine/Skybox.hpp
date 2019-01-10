#pragma once

#include <iostream>
#include <vector>

#include "common.hpp"
#include "TextureLoader.hpp"



class Skybox
{

public:

  /// Default Skybox constructor
  Skybox()
  {
    voManager();
    createTexture();
  }

/// method which create the vbo and the vao for the skybox
  void voManager();

///  method which create a texture by default
  void createTexture();
/// method wich create a custom Texture
/// param faces : vector which contains 6 filephaths for the 6 image of the skybox
  void createTexture(std::vector <const char*> faces);

  void displaySkybox();

private:

  GLuint m_vbo,m_vao;
  GLuint m_cubemapTexture;
  GLfloat m_skyboxVertices[108] = {
         // Positions
         -1.0f,  1.0f, -1.0f,
         -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         -1.0f,  1.0f, -1.0f,

         -1.0f, -1.0f,  1.0f,
         -1.0f, -1.0f, -1.0f,
         -1.0f,  1.0f, -1.0f,
         -1.0f,  1.0f, -1.0f,
         -1.0f,  1.0f,  1.0f,
         -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

         -1.0f, -1.0f,  1.0f,
         -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
         -1.0f, -1.0f,  1.0f,

         -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         -1.0f,  1.0f,  1.0f,
         -1.0f,  1.0f, -1.0f,

         -1.0f, -1.0f, -1.0f,
         -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
     };

};
