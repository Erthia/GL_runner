#include <iostream>
#include "common.hpp"
#include "Grid.hpp"

namespace glimac {

  void Grid::draw()
  {
    glBindVertexArray(m_vao);
        glDrawArrays(GL_LINES,0,m_nVertexCount);
    glBindVertexArray(0);
  }

  void Grid::build()
  {
    ShapeVertex vertex;
    int sizeCube = 1;
    int sizeGrid = 10;
    m_nVertexCount = 0;

    // Horizontal
    for (int i =0; i<=sizeGrid; i = i + sizeCube)
    {
      vertex.texCoords = glm::vec2(0,0);
      vertex.normal = glm::vec3(-sizeGrid/2+i,0,-sizeGrid/2);
      vertex.position = vertex.normal;
      m_Vertices.push_back(vertex);

      vertex.texCoords = glm::vec2(0,0);
      vertex.normal = glm::vec3(-sizeGrid/2+i,0,sizeGrid/2);
      vertex.position = vertex.normal;
      m_Vertices.push_back(vertex);

      m_nVertexCount += 2;
    }

    // Vertical

    for (int i=0; i<=sizeGrid; i=i+sizeCube)
    {
      vertex.texCoords = glm::vec2(0,0);
      vertex.normal = glm::vec3(-sizeGrid/2,0,-sizeGrid/2+i);
      vertex.position = vertex.normal;
      m_Vertices.push_back(vertex);

      vertex.texCoords = glm::vec2(0,0);
      vertex.normal = glm::vec3(sizeGrid/2,0,-sizeGrid/2+i);
      vertex.position = vertex.normal;
      m_Vertices.push_back(vertex);

      m_nVertexCount += 2;
    }

    vboManager(m_vbo);
    vaoManager(m_vao,m_vbo);
  }

  void Grid::vboManager(GLuint &vbo)
	{
		glGenBuffers(1,&vbo);
	  glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,this->getVertexCount()*sizeof(ShapeVertex),this->getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
	}

	void Grid::vaoManager(GLuint &vao,GLuint &vbo)
  {

		glGenVertexArrays(1,&vao);
    glBindVertexArray(vao);
    glEnableVertexAttribArray(0);
    glEnableVertexAttribArray(1);
    glEnableVertexAttribArray(2);

    glBindBuffer(GL_ARRAY_BUFFER,vbo);
    glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,position));
    glVertexAttribPointer(1,3,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,normal));
    glVertexAttribPointer(2,2,GL_FLOAT,GL_FALSE,sizeof(ShapeVertex),(void *) offsetof(ShapeVertex,texCoords));
    glBindBuffer(GL_ARRAY_BUFFER,0);
    glBindVertexArray(0);
  }

}
