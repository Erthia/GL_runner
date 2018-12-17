#pragma once

#include <vector>
#include "common.hpp"


namespace glimac{

class Cube
{

	void build(GLfloat m_edge);

public:

	Cube(GLfloat m_edge):
		m_nVertexCount(36)
    {
        build(m_edge); // Construction (voir le .cpp)
    }

	// Renvoit le pointeur vers les données
    const ShapeVertex* getDataPointer() const {
        return &m_Vertices[0];
    }

    // Renvoit le nombre de vertex
    GLsizei getVertexCount() const {
        return m_nVertexCount;
    }

private:

	GLfloat m_edge;
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount; // Nombre de sommets

};

}
