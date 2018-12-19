#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

class PerspectiveShader
{
public:

  // constructor
  PerspectiveShader(
      const char* filepathFragmentShader = "./shaders/normals.fs.glsl");

  // destructor
  ~PerspectiveShader() {};

  void setUniformMatrix() const;
  void setViewMatrix(const glm::mat4 &sceneModel);

  void use();

private:

  glimac::Program m_program;

  const char* m_filepathFragmentShader;

  glm::mat4 m_modelviewMatrix;

  const char* uniformMVPName = "uMVPMatrix";
  const char* uniformMVName = "uMVMatrix";
  const char* uniformNormName = "uNormalMatrix";

  GLuint m_uniformModelViewMatrix;
  GLuint m_uniformNormalMatrix;
  GLuint m_uniformModelViewProjectionMatrix;

};
