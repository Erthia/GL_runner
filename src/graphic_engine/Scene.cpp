#include <glimac/Object.hpp>
#include <glimac/cube.hpp>
#include <glimac/Landmark.hpp>
#include <glimac/common.hpp>
#include <cmath>
#include <memory>

#include "Scene.hpp"
#include "Texture.hpp"
#include "camera.hpp"
#include "Image.hpp"
#include "perspectiveShader.hpp"

Scene::Scene()
{}

Scene::Scene(
            std::vector<std::unique_ptr<glimac::Object>> inDataObject,
            std::shared_ptr<Camera> inCamera):
  m_dataObject(std::move(inDataObject)),
  m_camera(inCamera)
{}

void Scene::loadScene(motor_game::Map &inMap,float speed)
{
  PerspectiveShader shader3D;
  PerspectiveShader shaderRed("./shaders/red.fs.glsl");
  PerspectiveShader shaderTexture("./shaders/texture.fs.glsl");

  // Textures
  Texture test("elt/texture/brick.jpg");
  test.loadTexture();


  std::unique_ptr<glimac::Image> myText = glimac::loadImage("elt/texture/brick.jpg");
   if(myText == NULL ){
      std::cerr << "Error charging texture." << std::endl;
      exit(0);
}

  GLuint texture;
  glGenTextures(1,&texture);
 // shaderTexture.use();
  glBindTexture(GL_TEXTURE_2D, texture);
  glTexImage2D(GL_TEXTURE_2D,0,GL_RGBA,myText->getWidth(),myText->getHeight(),0,GL_RGBA,GL_FLOAT,myText->getPixels());
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // filtre
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR); // filtre
  glBindTexture(GL_TEXTURE_2D, 0);


  for (unsigned int i= 0; i<inMap.x();i++)
  {
    for (unsigned int j=0;j<inMap.y();j++)
    {
      for (unsigned int k=0;k<inMap.z();k++)
      {
        if (inMap.element(i,j,k)!=nullptr)
        {
          if (inMap.element(i,j,k)->getType() == "Wall")
          {
            // Initialize Landmark

            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));

            shaderRed.use();
            shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
            shaderRed.setUniformMatrix2();

            (m_dataObject[0])->draw();

          }
          if (inMap.element(i,j,k)->getType()=="Floor")
          {
            //Initialize Landmark
            glBindTexture(GL_TEXTURE_2D, texture);
            glUniform1i(shaderTexture.getUniformTexture(), 0);

            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));
            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));
            shaderTexture.use();
            shaderTexture.setViewMatrix(m_camera->getViewMatrix(),projection);
            shaderTexture.setUniformMatrix2();
            /*shader3D.use();
            shader3D.setViewMatrix(m_camera->getViewMatrix(),projection);
            shader3D.setUniformMatrix2();
*/
            (m_dataObject[0])->draw();
          }

          if (inMap.element(i,j,k)->getType()=="Obstacle")
          {
            //Initialize Landmark
            glm::mat4 projection = glm::scale(glm::mat4(1),glm::vec3(1,1,-1));
            projection *=glm::translate(glm::mat4(1),glm::vec3(-2,-3,-3));

            projection *= glm::translate(glm::mat4(1),glm::vec3(i,j,k+speed));

            shaderRed.use();
            shaderRed.setViewMatrix(m_camera->getViewMatrix(),projection);
            shaderRed.setUniformMatrix2();

            (m_dataObject[0])->draw();
          }
        }
      }
    }
  }
};


Scene::~Scene()
{}
