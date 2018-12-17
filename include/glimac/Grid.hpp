#pragma once

#include <vector>
#include "common.hpp"


namespace glimac{

class Grid
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

private:
	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount =0; // Nombre de sommets

};

}
