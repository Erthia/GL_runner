#include <iostream>
#include "common.hpp"
#include "Grid.hpp"

namespace glimac {
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




  }

}
