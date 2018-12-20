#pragma once

#include <iostream>
#include <vector>
#include "common.hpp"

namespace glimac{

  class Object
  {
    //virtual void build() = 0;

  public:

    Object()
    {}

    // Renvoit le pointeur vers les données
      inline
      const ShapeVertex* getDataPointer() const {
          return &m_Vertices[0];
      }

      // Renvoit le nombre de vertex
      inline
      GLsizei getVertexCount() const {
          return m_nVertexCount;
      }

      virtual void vboManager(GLuint &vbo);
      virtual void vaoManager(GLuint &vao,GLuint &vbo);

      inline
      GLuint getVao() const
      {
        return m_vao;
      }

      virtual void draw()
      {}




/********************************************TEST********/
    int x = 0;
    int y = 0;
/********************************************************/
  private:

    GLuint m_vbo,m_vao;
    std::vector<ShapeVertex> m_Vertices;
    GLsizei m_nVertexCount; // Nombre de sommets



  };
}
