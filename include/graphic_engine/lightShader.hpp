#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

class LightShader
{
public:

  /// constructor with parameters

  LightShader(
      const char* filepathFragmentShader = "./shaders/directionallight.fs.glsl");

  LightShader(
          const char* filepathVertexShader,
          const char* filepathFragmentShader
  );

  /// destructor
  ~LightShader() {};

  /// method which set uniform Matrix for the shaders
  void setUniformMatrix() const;
  void setUniformMatrix2() const;

  /// method which set projection and view matrix
  void setViewMatrix(const glm::mat4 &sceneModel,const glm::mat4 &projection);

  /// method which launch the shader programm
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
