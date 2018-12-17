#include <cmath>

#include <iostream>
#include "common.hpp"
#include "cube.hpp"

namespace glimac {

	void Cube::build(GLfloat m_edge)
	{

		ShapeVertex vertex;

		// face 1
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		// face 2
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		// face 3
		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face4

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);
#include <vector>
#include "common.hpp"



		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face5

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		//face5

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,-1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);

		vertex.texCoords = glm::vec2(0,0);
		vertex.normal = glm::vec3(-1,-1,1);
		vertex.position = vertex.normal;
		m_Vertices.push_back(vertex);





	}
}
