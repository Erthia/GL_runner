#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

class LightShader
{
public:

  /// constructor
  LightShader(
      const char* filepathFragmentShader = "./shaders/normals.fs.glsl");

  LightShader(
          const char* filepathVertexShader,
          const char* filepathFragmentShader
  );

  // destructor
  ~LightShader() {};

  void setUniformMatrix() const;
  void setViewMatrix(const glm::mat4 &sceneModel,const glm::mat4 &projection);
  void setUniformMatrix2() const;

  void use();

private:

  glimac::Program m_program;

  const char* m_filepathVertexShader;
  const char* m_filepathFragmentShader;
  
  glm::mat4 m_modelviewMatrix;
  glm::mat4 m_modelprojMatrix;

  const char* uniformMVPName = "uMVPMatrix";
  const char* uniformMVName = "uMVMatrix";
  const char* uniformNormName = "uNormalMatrix";

  GLuint m_uniformModelViewMatrix;
  GLuint m_uniformNormalMatrix;
  GLuint m_uniformModelViewProjectionMatrix;

  GLuint m_uniformColor;
  GLuint m_uniformKd;
  GLuint m_uniformKs;
  GLuint m_uniformShininess;
  GLuint m_uniformLightDir_vs;
  GLuint m_uniformLightIntensity;

};
