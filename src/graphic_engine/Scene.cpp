#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>

#include <memory>

#include "Scene.hpp"
#include "camera.hpp"
#include "perspectiveShader.hpp"

Scene::Scene()
{}

Scene::Scene(std::vector<std::unique_ptr<glimac::Object>> inDataObject,
            std::shared_ptr<Camera> inCamera):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera)
{}

void Scene::loadScene()
{
  for (unsigned int i = 0; i<m_dataObject.size();i++)
  {
    PerspectiveShader shader3D;
    glm::mat4 projection = glm::translate(glm::mat4(1),
                                          glm::vec3(m_dataObject[i]->x,
                                          m_dataObject[i]->y,
                                          0)
                                         );

    shader3D.use();
    shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
    shader3D.setUniformMatrix();

    (m_dataObject[i])->draw();
  }
};


Scene::~Scene()
{}
