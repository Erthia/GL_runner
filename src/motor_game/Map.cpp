#include "Map.hpp"

namespace motor_game{

    Map::Map(const unsigned int &x, const unsigned int &y, const unsigned int &z)
        : m_elements(std::vector<Element*>(x*y*z)), m_x(x), m_y(y), m_z(z)
    {}




    Element *Map::element(const unsigned int &x, const unsigned int &y, const unsigned int &z) const{
        return m_elements[x + m_x*y + (m_x*m_y)*z];
    }

    void Map::printElement()
    {
      for (unsigned int i = 0; i<m_elements.size(); i++)
      {
        if (m_elements[i] != nullptr)
        {
          std::cout<<m_elements[i]->getPosition()<<std::endl;
        }
      }
    }

    Element* Map::getElementi(const int i) const
    {
      return m_elements[i];
    }

    void Map::translateMap(const float &x, const float &z)
    {
      glm::mat4 translationMatrix = glm::translate(glm::mat4(1),glm::vec3(-x,0,-z));
      for (unsigned int i = 0; i<m_elements.size();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = translationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));
        }
      }
    }

    void Map::rotateRight()
    {
      float m_angle = -90;
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1),glm::radians(m_angle),glm::vec3(0,1,0));
      for (unsigned int i = 0; i<m_elements.size();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = rotationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));
        }
      }
    }

    void Map::rotateLeft()
    {
      float m_angle = 90;
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1),glm::radians(m_angle),glm::vec3(0,1,0));
      for (unsigned int i = 0; i<m_elements.size();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = rotationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));
        }
      }
    }

    void Map::element(
        const unsigned int &x, const unsigned int &y, const unsigned int &z,
        Element *element
    ){
        m_elements[x + m_x*y + (m_x*m_y)*z] = element;
    }
}
