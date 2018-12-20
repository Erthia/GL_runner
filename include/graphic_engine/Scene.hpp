#pragma once

#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>

#include <vector>
#include <memory>

#include "camera.hpp"
#include "Element.hpp"
#include "Map.hpp"

class Scene
{

public:
  //Constructor
  Scene();
  Scene(
         std::vector<std::unique_ptr<glimac::Object>> inDataObject,
         std::shared_ptr<Camera> inCamera);
  //Destructor
  ~Scene();

  //Methods
  void loadScene(motor_game::Map &inMap);

private:


    std::vector<std::unique_ptr<glimac::Object>> m_dataObject;
    std::shared_ptr<Camera> m_camera;

};
