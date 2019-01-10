#pragma once

#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>

#include <vector>
#include <memory>

#include "camera.hpp"
#include "Element.hpp"
#include "Map.hpp"
#include "Hero.hpp"
#include "perspectiveShader.hpp"

class Scene
{

public:
  //Constructor
  Scene();
  Scene(
         std::vector<std::unique_ptr<glimac::Object>> inDataObject,
         std::shared_ptr<Camera> inCamera);

   Scene(
          std::vector<std::unique_ptr<glimac::Object>> inDataObject,
          std::shared_ptr<Camera> inCamera,
          std::vector<GLuint*> inTexture,
          std::vector<PerspectiveShader*> inShader);
  //Destructor
  ~Scene();

  //Methods
  void loadScene(motor_game::Map &inMap,float speed);

private:


    std::vector<std::unique_ptr<glimac::Object>> m_dataObject;
    std::shared_ptr<Camera> m_camera;
    std::vector<GLuint*> m_texture;
    std::vector<PerspectiveShader*> m_shader;

};
