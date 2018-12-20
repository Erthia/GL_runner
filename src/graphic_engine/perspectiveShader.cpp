#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>
#include "perspectiveShader.hpp"

PerspectiveShader::PerspectiveShader(
  const char* m_filepathFragmentShader):


  m_program(glimac::loadProgram("./shaders/3d.vs.glsl",
                        m_filepathFragmentShader)),
  m_filepathFragmentShader(m_filepathFragmentShader),
  m_modelviewMatrix(glm::mat4(1.0f)),
  m_uniformModelViewMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVName)),
  m_uniformNormalMatrix(glGetUniformLocation(m_program.getGLId(),uniformNormName)),
  m_uniformModelViewProjectionMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVPName))


{}
void PerspectiveShader::use()
{
  m_program.use();
}
void PerspectiveShader::setViewMatrix(const glm::mat4 &sceneModel, const glm::mat4 &projection)
{
//  m_projectionMatrix = projection;
  m_modelviewMatrix = sceneModel;
  m_modelprojMatrix = projection;
}

void PerspectiveShader::setUniformMatrix() const
{

  glm::mat4 projMatrix,MVMatrix,NormalMatrix;
  float a = 800.0/600.0;
  projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f);
  MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*m_modelprojMatrix;
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  glm::mat4 modelViewProjection = projMatrix * MVMatrix* m_modelviewMatrix;
  glUniformMatrix4fv(m_uniformModelViewProjectionMatrix,1,GL_FALSE,glm::value_ptr(modelViewProjection));
  glUniformMatrix4fv(m_uniformModelViewMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
  glUniformMatrix4fv(m_uniformNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));
}

void PerspectiveShader::setUniformMatrix2() const
{

  glm::mat4 projMatrix,MVMatrix,NormalMatrix;
  float a = 800.0/600.0;
  projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f)* m_modelviewMatrix;
  MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*m_modelprojMatrix;
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));

  glm::mat4 modelViewProjection = projMatrix * MVMatrix;
  glUniformMatrix4fv(m_uniformModelViewProjectionMatrix,1,GL_FALSE,glm::value_ptr(modelViewProjection));
  glUniformMatrix4fv(m_uniformModelViewMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
  glUniformMatrix4fv(m_uniformNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));
}
