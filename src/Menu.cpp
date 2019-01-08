#include "Menu.hpp"

void Menu::displayMenu() const
{

  glBindVertexArray(m_vao);
    glDrawArrays(GL_TRIANGLES,0,m_nVertexCount);
  glBindVertexArray(0);
}
void Menu::build()
{

  ShapeVertex vertex;

// BUTTON

  vertex.texCoords = glm::vec2(0,0);
  vertex.normal = glm::vec3(-4,3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vertex.texCoords = glm::vec2(1,0);
  vertex.normal = glm::vec3(4,3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vertex.texCoords = glm::vec2(1,1);
  vertex.normal = glm::vec3(4,-3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vertex.texCoords = glm::vec2(0,0);
  vertex.normal = glm::vec3(-4,3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vertex.texCoords = glm::vec2(0,1);
  vertex.normal = glm::vec3(-4,-3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vertex.texCoords = glm::vec2(1,1);
  vertex.normal = glm::vec3(4,-3,1);
  vertex.position = vertex.normal;
  m_Vertices.push_back(vertex);

  vboManager(m_vbo);
  vaoManager(m_vao,m_vbo);

}

void Menu::vboManager(GLuint &vbo)
{
  glGenBuffers(1,&vbo);
  glBindBuffer(GL_ARRAY_BUFFER,vbo);
  glBufferData(GL_ARRAY_BUFFER,this->getVertexCount()*sizeof(ShapeVertex),this->getDataPointer(), GL_STATIC_DRAW);
  glBindBuffer(GL_ARRAY_BUFFER,0);
}

void Menu::vaoManager(GLuint &vao,GLuint &vbo)
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

int Menu::onMouseEvent(glm::ivec2 position)
{
  if ((position.x>185 && position.x<610) && (position.y>200 && position.y<400))
  {
      isVisible = false;
      return 1;
  }
  return 0;
}
