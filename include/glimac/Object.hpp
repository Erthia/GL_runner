#pragma once

#include <vector>
#include "common.hpp"

namespace glimac{

  class Object
  {
    virtual void build() = 0;

  public:

    // Renvoit le pointeur vers les données
      const ShapeVertex* getDataPointer() const {
          return &m_Vertices[0];
      }

      // Renvoit le nombre de vertex
      GLsizei getVertexCount() const {
          return m_nVertexCount;
      }

      virtual void vboManager(GLuint &vbo);
      virtual void vaoManager(GLuint &vao,GLuint &vbo);


  private:
    std::vector<ShapeVertex> m_Vertices;
    GLsizei m_nVertexCount; // Nombre de sommets
  };
}
