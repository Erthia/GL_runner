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
#include <GLFW/glfw3.h>
#include <fstream>

#pragma once


class Menu
{

  void build();

public:
  Menu()
  {
    build();
  }

  inline
  bool visibility() const
  {
    return isVisible;
  }

  inline
  void setVisibility(bool inBool)
  {
    isVisible = inBool;
  }

  void initMenu(GLuint &vbo,GLuint &vao);
  void displayMenu(const GLuint &vao);

  // Renvoit le pointeur vers les données
  const ShapeVertex* getDataPointer() const {
      return &m_Vertices[0];
  }

  // Renvoit le nombre de vertex
  GLsizei getVertexCount() const {
      return m_nVertexCount;
  }

	void vboManager(GLuint &vbo);
	void vaoManager(GLuint &vao,GLuint &vbo);

  int onMouseEvent(glm::ivec2 position);

private:
  bool isVisible = true;
  int m_type = 0;
  std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount = 6;


};
