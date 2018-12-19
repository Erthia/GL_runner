#pragma once

#include <vector>
#include "common.hpp"
#include "Object.hpp"


namespace glimac{

class Grid :public Object
{

	void build();

public:

	Grid()
    {
        build(); // Construction (voir le .cpp)
    }

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

	inline
	GLuint getVao() const
	{
		return m_vao;
	}

private:

	GLuint m_vbo,m_vao;
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount = 0; // Nombre de sommets

};

}
