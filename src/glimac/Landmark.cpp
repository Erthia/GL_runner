#include <iostream>
#include "common.hpp"
#include "Landmark.hpp"

namespace glimac {
  void Landmark::draw()
  {
    glBindVertexArray(m_vao);
        glDrawArrays(GL_LINES,0,m_nVertexCount);
    glBindVertexArray(0);
  }
  void Landmark::build()
  {
    ShapeVertex vertex;

    //Axe Z
    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(0,0,0);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(0,0,1);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    //Axe Y
    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(0,0,0);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(0,1,0);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    //Axe X
    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(0,0,0);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    vertex.texCoords = glm::vec2(0,0);
    vertex.normal = glm::vec3(1,0,0);
    vertex.position = vertex.normal;
    m_Vertices.push_back(vertex);

    vboManager(m_vbo);
    vaoManager(m_vao,m_vbo);

  }

  void Landmark::vboManager(GLuint &vbo)
	{
		glGenBuffers(1,&vbo);
	  glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,this->getVertexCount()*sizeof(ShapeVertex),this->getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
	}

	void Landmark::vaoManager(GLuint &vao,GLuint &vbo)
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
