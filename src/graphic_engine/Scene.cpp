#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>
#include <cmath>
#include <memory>

#include "Scene.hpp"
#include "camera.hpp"
#include "perspectiveShader.hpp"
#include "lightShader.hpp"
#include "Hero.hpp"


Scene::Scene()
{}

Scene::Scene(
            std::vector<std::unique_ptr<glimac::Object>> inDataObject,
            std::shared_ptr<Camera> inCamera):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera)
{}

Scene::Scene(
       std::vector<std::unique_ptr<glimac::Object>> inDataObject,
       std::shared_ptr<Camera> inCamera,
       std::vector<GLuint*> inTexture,
       std::vector<PerspectiveShader*> inShader):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera) ,
  m_texture(inTexture),
  m_shader(inShader)
{}




void Scene::loadScene(motor_game::Map &inMap,float speed)
{

  LightShader shaderlight("./shaders/directionallight.fs.glsl");


  negative_vector<Element*> vector = inMap.getVector();
  for (int i = vector.lower_limit(); i< vector.upper_limit(); i++)
  {
    glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
    projection *= glm::translate(glm::mat4(1),glm::vec3(inMap.projectionX(),inMap.projectionY(),inMap.projectionZ()));
    if (vector[i]!=nullptr)
    {
        if (vector[i]->getType() == "Wall")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          m_shader[0]->use();
          m_shader[0]->setViewMatrix(m_camera->getViewMatrix(),projection);
          m_shader[0]->setUniformMatrix2();

          m_dataObject[0]->draw();
        }
        if (vector[i]->getType()=="Floor")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          m_shader[1]->use();
          m_shader[1]->setViewMatrix(m_camera->getViewMatrix(),projection);
          m_shader[1]->setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="right" || vector[i]->getType()=="left")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          m_shader[1]->use();
          m_shader[1]->setViewMatrix(m_camera->getViewMatrix(),projection);
          m_shader[1]->setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="Obstacle")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          m_shader[0]->use();
          m_shader[0]->setViewMatrix(m_camera->getViewMatrix(),projection);
          m_shader[0]->setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="End")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX(),vector[i]->getY(),vector[i]->getZ()+speed));

          m_shader[1]->use();
          m_shader[1]->setViewMatrix(m_camera->getViewMatrix(),projection);
          m_shader[1]->setUniformMatrix2();

          m_dataObject[0]->draw();
        }

        if (vector[i]->getType()=="Coin")
        {
          projection *=glm::translate(glm::mat4(1),glm::vec3(vector[i]->getX()+0.5,vector[i]->getY()+0.5,vector[i]->getZ()+speed));
          projection *=glm::scale(glm::mat4(1),glm::vec3(0.5,0.5,0.5));
          shaderlight.use();
          shaderlight.setViewMatrix(m_camera->getViewMatrix(),projection);
          shaderlight.setUniformMatrix2();

          m_dataObject[1]->draw();
        }

    }

  }
}


Scene::~Scene()
{}
