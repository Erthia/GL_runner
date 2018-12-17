#pragma once

#include <glimac/common.hpp>

class Camera
{
public:
  virtual glm::mat4 getViewMatrix() const = 0;
};
