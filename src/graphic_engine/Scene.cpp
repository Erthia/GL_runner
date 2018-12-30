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
  negative_vector<Element*> vector = inMap.getVector();
  for (int i = vector.lower_limit(); i< vector.upper_limit(); i++)
  {
    glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
    projection *= glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
    if (vector[i]!=nullptr)
    {
        if (vector[i]->getType() == "Wall")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          shader3D.use();
          shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
          shader3D.setUniformMatrix2();

          m_dataObject[0]->draw();
        }
        if (vector[i]->getType()=="Floor")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          shader3D.use();
          shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
          shader3D.setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="right" || vector[i]->getType()=="left")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          shaderRed.use();
          shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
          shaderRed.setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="Obstacle")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          shaderRed.use();
          shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
          shaderRed.setUniformMatrix2();

          m_dataObject[0]->draw();
        }

    }

  }
}


Scene::~Scene()
{}
