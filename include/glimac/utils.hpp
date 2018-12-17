#pragma once

#include <vector>
#include "common.hpp"


namespace glimac{

class Landmark
{

	void build();

public:

	Landmark():
		m_nVertexCount(6)
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

private:
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount; // Nombre de sommets

};

}
