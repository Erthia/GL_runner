#pragma once

#include <glimac/common.hpp>

/// Mother Class Camera
class Camera
{
public:
  virtual glm::mat4 getViewMatrix() const = 0;
};
