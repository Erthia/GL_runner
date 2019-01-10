#include <glimac/common.hpp>
#include <glimac/FilePath.hpp>
#include <glimac/Program.hpp>
#include <memory>

#include "lightShader.hpp"

LightShader::LightShader(
  const char* filepathFragmentShader):


  m_program(glimac::loadProgram("./shaders/3d.vs.glsl",
                        filepathFragmentShader)),
  m_filepathFragmentShader(filepathFragmentShader),
  m_modelviewMatrix(glm::mat4(1.0f)),
  m_uniformModelViewMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVName)),
  m_uniformNormalMatrix(glGetUniformLocation(m_program.getGLId(),uniformNormName)),
  m_uniformModelViewProjectionMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVPName)),
  m_uniformColor(glGetUniformLocation(m_program.getGLId(),"uColor")),
  m_uniformKd(glGetUniformLocation(m_program.getGLId(),"uKd")),
  m_uniformKs(glGetUniformLocation(m_program.getGLId(),"uKs")),
  m_uniformShininess(glGetUniformLocation(m_program.getGLId(),"uShininess")),
  m_uniformLightDir_vs(glGetUniformLocation(m_program.getGLId(),"uLightDir_vs")),
  m_uniformLightIntensity(glGetUniformLocation(m_program.getGLId(),"uLightIntensity"))

{}

LightShader::LightShader(

  const char* filepathVertexShader,
  const char* filepathFragmentShader):


  m_program(glimac::loadProgram(filepathVertexShader,
                        filepathFragmentShader)),
  m_filepathVertexShader(filepathVertexShader),
  m_filepathFragmentShader(filepathFragmentShader),
  m_modelviewMatrix(glm::mat4(1.0f)),
  m_uniformModelViewMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVName)),
  m_uniformNormalMatrix(glGetUniformLocation(m_program.getGLId(),uniformNormName)),
  m_uniformModelViewProjectionMatrix(glGetUniformLocation(m_program.getGLId(),uniformMVPName)),
  m_uniformColor(glGetUniformLocation(m_program.getGLId(),"uColor")),
  m_uniformKd(glGetUniformLocation(m_program.getGLId(),"uKd")),
  m_uniformKs(glGetUniformLocation(m_program.getGLId(),"uKs")),
  m_uniformShininess(glGetUniformLocation(m_program.getGLId(),"uShininess")),
  m_uniformLightDir_vs(glGetUniformLocation(m_program.getGLId(),"uLightDir_vs")),
  m_uniformLightIntensity(glGetUniformLocation(m_program.getGLId(),"uLightIntensity"))


{}

void LightShader::use()
{
  m_program.use();
}

void LightShader::setViewMatrix(const glm::mat4 &sceneModel, const glm::mat4 &projection)
{
//  m_projectionMatrix = projection;
  m_modelviewMatrix = sceneModel;
  m_modelprojMatrix = projection;
}

void LightShader::setUniformMatrix() const
{

  glm::mat4 projMatrix,MVMatrix,NormalMatrix;
  float a = 800.0/600.0;
  projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f);
  MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*m_modelprojMatrix;
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
  glm::mat4 rotation(1.0f);
  //rotation = glm::rotate(rotation,windowManager.getTime(),glm::vec3(0,1,0));
  glm::vec3 K = glm::vec3(0.2,0.2,0.2);
  glm::vec4 _lightDir = rotation*glm::vec4(1,1,1,1)*m_modelprojMatrix;
  glm::vec3 lightDir = glm::vec3(_lightDir[0],_lightDir[1],_lightDir[2]);
  glm::vec3 lightIntensity = glm::vec3(1,1,1);
  //glm::vec4 _lightPos = glm::vec4(1,1,1,1)*camera.getViewMatrix();
  //glm::vec3 LightPos= glm::vec3(_lightPos[0],_lightPos[1],_lightPos[2]);

  glm::mat4 modelViewProjection = projMatrix * MVMatrix* m_modelviewMatrix;
  glUniformMatrix4fv(m_uniformModelViewProjectionMatrix,1,GL_FALSE,glm::value_ptr(modelViewProjection));
  glUniformMatrix4fv(m_uniformModelViewMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
  glUniformMatrix4fv(m_uniformNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));
  glUniform1f(m_uniformShininess,0.5);
  glUniform3fv(m_uniformKs,1,glm::value_ptr(K));
  glUniform3fv(m_uniformKd,1,glm::value_ptr(K));
  glUniform3fv(m_uniformLightDir_vs,1,glm::value_ptr(lightDir));
  glUniform3fv(m_uniformLightIntensity,1,glm::value_ptr(lightIntensity));
  //glUniform3fv(uLightPos_vs,1,glm::value_ptr(LightPos));

}

void LightShader::setUniformMatrix2() const
{

  glm::mat4 projMatrix,MVMatrix,NormalMatrix;
  float a = 800.0/600.0;
  projMatrix = glm::perspective(glm::radians(70.f),a,0.1f,100.f)* m_modelviewMatrix;
  MVMatrix = glm::translate(glm::mat4(1.0),glm::vec3(0.0,0.0,-5.0))*m_modelprojMatrix;
  NormalMatrix = glm::transpose(glm::inverse(MVMatrix));
  glm::mat4 rotation(1.0f);
  //rotation = glm::rotate(rotation,windowManager.getTime(),glm::vec3(0,1,0));
  glm::vec3 K = glm::vec3(0.5,0.5,0.5);
  glm::vec4 _lightDir = rotation*glm::vec4(1,1,1,1)*m_modelprojMatrix;
  glm::vec3 lightDir = glm::vec3(_lightDir[0],_lightDir[1],_lightDir[2]);
  glm::vec3 lightIntensity = glm::vec3(10,10,10);
  //glm::vec4 _lightPos = glm::vec4(1,1,1,1)*camera.getViewMatrix();
  //glm::vec3 LightPos= glm::vec3(_lightPos[0],_lightPos[1],_lightPos[2]);

  glm::mat4 modelViewProjection = projMatrix * MVMatrix* m_modelviewMatrix;
  glUniformMatrix4fv(m_uniformModelViewProjectionMatrix,1,GL_FALSE,glm::value_ptr(modelViewProjection));
  glUniformMatrix4fv(m_uniformModelViewMatrix,1,GL_FALSE,glm::value_ptr(MVMatrix));
  glUniformMatrix4fv(m_uniformNormalMatrix,1,GL_FALSE,glm::value_ptr(NormalMatrix));
  glUniform1f(m_uniformShininess,0.5);
  glUniform3fv(m_uniformKs,1,glm::value_ptr(K));
  glUniform3fv(m_uniformKd,1,glm::value_ptr(K));
  glUniform3fv(m_uniformLightDir_vs,1,glm::value_ptr(lightDir));
  glUniform3fv(m_uniformLightIntensity,1,glm::value_ptr(lightIntensity));
  //glUniform3fv(uLightPos_vs,1,glm::value_ptr(LightPos));

}
