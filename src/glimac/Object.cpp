#include <iostream>
#include "Object.hpp"

namespace glimac
{
  void Object::vboManager(GLuint &vbo)
  {
    glGenBuffers(1,&vbo);
	  glBindBuffer(GL_ARRAY_BUFFER,vbo);
		glBufferData(GL_ARRAY_BUFFER,this->getVertexCount()*sizeof(ShapeVertex),this->getDataPointer(), GL_STATIC_DRAW);
    glBindBuffer(GL_ARRAY_BUFFER,0);
  }

  void Object::vaoManager(GLuint &vao,GLuint &vbo)
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
