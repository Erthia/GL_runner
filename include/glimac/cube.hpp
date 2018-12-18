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

		

private:


	std::vector<ShapeVertex> m_Vertices;
  GLsizei m_nVertexCount; // Nombre de sommets

};

}
