#include <cmath>

#include <iostream>
#include "common.hpp"
#include "cube.hpp"

namespace glimac {

	void Cube::build()
	{

		ShapeVertex vertex;

		// face 1
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		// face 2
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		// face 3
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face4

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);


		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face5

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face5

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,0);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(0,0,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);


	}

	void Cube::vboManager(GLuint &vbo)
	{
		glGenBuffers(1,&vbo);
	  glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,this->getVertexCount()*sizeof(ShapeVertex),this->getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
	}

	void Cube::vaoManager(GLuint &vao,GLuint &vbo)
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
