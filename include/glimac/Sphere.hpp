#pragma once

#include <vector>

#include "common.hpp"
#include "Object.hpp"

namespace glimac {

// Représente une sphère discrétisée centrée en (0, 0, 0) (dans son repère local)
// Son axe vertical est (0, 1, 0) et ses axes transversaux sont (1, 0, 0) et (0, 0, 1)
class Sphere :public Object{
    // Alloue et construit les données (implantation dans le .cpp)
    void build(GLfloat radius, GLsizei discLat, GLsizei discLong);

public:
    // Constructeur: alloue le tableau de données et construit les attributs des vertex
    Sphere(GLfloat radius=1, GLsizei discLat=100, GLsizei discLong=100):
        m_nVertexCount(0) {
        build(radius, discLat, discLong); // Construction (voir le .cpp)
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

    void draw();

    void description()
    {
      std::cout<<"Je suis une Sphere"<<std::endl;
    }


private:
    GLuint m_vbo,m_vao;
    std::vector<ShapeVertex> m_Vertices;
    GLsizei m_nVertexCount; // Nombre de sommets
};

}
