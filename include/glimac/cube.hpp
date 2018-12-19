#pragma once

#include <vector>
#include "common.hpp"
#include "Object.hpp"


namespace glimac{

class Cube :public Object
{

	void build();

public:

	Cube():
		m_nVertexCount(36)
    {
        build();
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

	void draw();


private:

	GLuint m_vbo,m_vao;
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount; // Nombre de sommets


};

}
