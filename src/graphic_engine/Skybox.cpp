
#include <iostream>
#include <vector>

#include "Skybox.hpp"
#include "common.hpp"
#include "TextureLoader.hpp"


using namespace glimac;

void Skybox::voManager()
{
  glGenVertexArrays( 1, &m_vao );
  glGenBuffers( 1, &m_vbo );
  glBindVertexArray( m_vao );
  glBindBuffer( GL_ARRAY_BUFFER, m_vbo );
  glBufferData( GL_ARRAY_BUFFER, sizeof( m_skyboxVertices ), &m_skyboxVertices, GL_STATIC_DRAW );
  glEnableVertexAttribArray( 0 );
  glVertexAttribPointer( 0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof( GLfloat ), ( GLvoid * ) 0 );
  glBindVertexArray(0);
}

void Skybox::createTexture()
{
  std::vector <const char*> faces;
  faces.push_back( "./elt/texture/skybox/right.tga" );
  faces.push_back( "./elt/texture/skybox/left.tga" );
  faces.push_back( "./elt/texture/skybox/top.tga" );
  faces.push_back( "./elt/texture/skybox/bottom.tga" );
  faces.push_back( "./elt/texture/skybox/back.tga" );
  faces.push_back( "./elt/texture/skybox/front.tga" );
  m_cubemapTexture = TextureLoader::LoadCubeMap( faces );
}

void Skybox::displaySkybox()
{
  // skybox cube
  glBindVertexArray( m_vao);
  glBindTexture( GL_TEXTURE_CUBE_MAP, m_cubemapTexture );
  glDrawArrays( GL_TRIANGLES, 0, 36 );
  glBindVertexArray( 0 );
  glDepthFunc( GL_LESS ); // Set depth function back to default
}
