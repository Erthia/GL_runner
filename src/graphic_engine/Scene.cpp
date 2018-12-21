#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>
#include <cmath>
#include <memory>

#include "Scene.hpp"
#include "camera.hpp"
#include "perspectiveShader.hpp"
#include "Hero.hpp"

Scene::Scene()
{}

Scene::Scene(
            std::vector<std::unique_ptr<glimac::Object>> inDataObject,
            std::shared_ptr<Camera> inCamera):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera)
{}

void Scene::loadScene(motor_game::Map &inMap,float speed)
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
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));

            shaderRed.use();
            shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
            shaderRed.setUniformMatrix2();

            (m_dataObject[0])->draw();

          }
          if (inMap.element(i,j,k)->getType()=="Floor")
          {
            //Initialize Landmark
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));

            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));

            shader3D.use();
            shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
            shader3D.setUniformMatrix2();

            (m_dataObject[0])->draw();
          }

          if (inMap.element(i,j,k)->getType()=="Obstacle")
          {
            //Initialize Landmark
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));

            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));

            shaderRed.use();
            shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
            shaderRed.setUniformMatrix2();

            (m_dataObject[0])->draw();
          }
        }
      }
    }
  }
}
  void Scene::loadSceneRight(motor_game::Map &inMap,float start,float speed,Hero &hero)
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
              projection *=glm::translate(glm::mat4(1),glm::vec3(start,-3,-2));
              projection *= glm::translate(glm::mat4(1),glm::vec3(k,j,i+speed));

              shaderRed.use();
              shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
              shaderRed.setUniformMatrix2();

              (m_dataObject[0])->draw();

            }
            if (inMap.element(i,j,k)->getType()=="Floor")
            {
              //Initialize Landmark
              glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
              projection *=glm::translate(glm::mat4(1),glm::vec3(start,-3,-2));

              projection *= glm::translate(glm::mat4(1),glm::vec3(k,j,i+speed));

              shader3D.use();
              shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
              shader3D.setUniformMatrix2();

              (m_dataObject[0])->draw();
            }

            if (inMap.element(i,j,k)->getType()=="Obstacle")
            {
              //Initialize Landmark
              glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
              projection *=glm::translate(glm::mat4(1),glm::vec3(start,-3,-2));

              projection *= glm::translate(glm::mat4(1),glm::vec3(k,j,i+speed));

              shaderRed.use();
              shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
              shaderRed.setUniformMatrix2();

              (m_dataObject[0])->draw();
            }
          }
        }
      }
    }
  }





Scene::~Scene()
{}
