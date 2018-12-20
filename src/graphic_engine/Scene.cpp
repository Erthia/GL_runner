#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>
#include <cmath>
#include <memory>

#include "Scene.hpp"
#include "camera.hpp"
#include "perspectiveShader.hpp"

Scene::Scene()
{}

Scene::Scene(
            std::vector<std::unique_ptr<glimac::Object>> inDataObject,
            std::shared_ptr<Camera> inCamera):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera)
{}

void Scene::loadScene(motor_game::Map &inMap)
{
  PerspectiveShader shader3D;
  PerspectiveShader shaderRed("./shaders/red.fs.glsl");

  for (unsigned int i= 0; i<inMap.x();i++)
  {
    for (unsigned int j=0;j<inMap.y();j++)
    {
      for (unsigned int k=0;k<inMap.z();k++)
      {
        if (inMap.element(i,j,k)!=nullptr)
        {
          if (inMap.element(i,j,k)->getType() == "Wall")
          {
            // Initialize Landmark

            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-4,-3,0));
            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k));
          //  std::cout<<glm::vec3(i,j,k)<<std::endl;

            shaderRed.use();
            shaderRed.setViewMatrix(glm::mat4(1),projection);
            shaderRed.setUniformMatrix();

            (m_dataObject[0])->draw();

          }
          if (inMap.element(i,j,k)->getType()=="Floor")
          {
            //Initialize Landmark
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-4,-3,0));

            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k));

            shader3D.use();
            shader3D.setViewMatrix(glm::mat4(1),projection);
            shader3D.setUniformMatrix();

            (m_dataObject[0])->draw();
          }
        }
      }
    }
  }
};


Scene::~Scene()
{}
