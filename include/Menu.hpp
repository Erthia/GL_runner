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
#include <fstream>

#pragma once

/// Class Menu
class Menu
{

  /// mrthod wich fill the vertices vector
  void build();

public:
  Menu()
  {
    build();
  }

  /// Brief Getter Menu visibility
  inline
  bool visibility() const
  {
    return isVisible;
  }

  /// Brief Setter Menu visibility
  inline
  void setVisibility(bool inBool)
  {
    isVisible = inBool;
  }

  /// Brief getter menu type
  inline
  int type() const
  {
    return m_type;
  }

  /// Brief setter of menu type
  inline
  void type(const int inType)
  {
     m_type = inType;
  }


/// method which set vao and vbo parameters
  void initMenu(GLuint &vbo,GLuint &vao);
  /// method which draw the menu
  void displayMenu() const;

  /// method which give a pointer on the data
  const ShapeVertex* getDataPointer() const {
      return &m_Vertices[0];
  }

  /// Getter vertex number
  GLsizei getVertexCount() const {
      return m_nVertexCount;
  }

/// method who create vbo
	void vboManager(GLuint &vbo);
/// method which create the vao from the vbo
	void vaoManager(GLuint &vao,GLuint &vbo);

/// method which handle sdl mouse cllick event
  int onMouseEvent(glm::ivec2 position);

private:
  bool isVisible = true;
  int m_type = 0;

  GLuint m_vbo,m_vao;
  std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount = 6;


};
