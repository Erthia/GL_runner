#pragma once

#include <vector>
#include "common.hpp"
#include "Object.hpp"


namespace glimac{

class Landmark :public Object
{

	void build();

public:

	Landmark():
		m_nVertexCount(6)
    {
        build(); // Construction (voir le .cpp)
    }

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

	void vboManager(GLuint &vbo);
	void vaoManager(GLuint &vao,GLuint &vbo);

	inline
	GLuint getVao() const
	{
		return m_vao;
	}

private:
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount; // Nombre de sommets

};

}
