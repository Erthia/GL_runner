#pragma once

#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

/// Shader program class
class PerspectiveShader
{
public:

  /// constructor
  PerspectiveShader(
      const char* filepathFragmentShader = "./shaders/normals.fs.glsl");

/// constructor with parameters
  PerspectiveShader(
          const char* filepathVertexShader,
          const char* filepathFragmentShader
  );

  /// destructor by default
  ~PerspectiveShader() {};

/// method which set uniform matrix for the shader
  void setUniformMatrix() const;
  void setUniformMatrix2() const;

  /// method which set projection and view matrix
  void setViewMatrix(const glm::mat4 &sceneModel,const glm::mat4 &projection);


/// method which launch the shader program
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
