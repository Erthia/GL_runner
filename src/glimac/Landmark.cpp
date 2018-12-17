#include <iostream>
#include "common.hpp"
#include "Landmark.hpp"

namespace glimac {
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

  }

}
