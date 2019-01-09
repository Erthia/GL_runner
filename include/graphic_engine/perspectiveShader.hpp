#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

class PerspectiveShader
{
public:

  /// constructor
  PerspectiveShader(
      const char* filepathFragmentShader = "./shaders/normals.fs.glsl");

  PerspectiveShader(
          const char* filepathVertexShader,
          const char* filepathFragmentShader
  );

  // destructor
  ~PerspectiveShader() {};

  void setUniformMatrix() const;
  void setViewMatrix(const glm::mat4 &sceneModel,const glm::mat4 &projection);
  void setUniformMatrix2() const;

  void use();

private:

  glimac::Program m_program;

  const char* m_filepathFragmentShader;
  const char* m_filepathVertexShader;

  glm::mat4 m_modelviewMatrix;
  glm::mat4 m_modelprojMatrix;

  const char* uniformMVPName = "uMVPMatrix";
  const char* uniformMVName = "uMVMatrix";
  const char* uniformNormName = "uNormalMatrix";

  GLuint m_uniformModelViewMatrix;
  GLuint m_uniformNormalMatrix;
  GLuint m_uniformModelViewProjectionMatrix;
  GLuint m_uniformModelTexture;

};
