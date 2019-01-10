#include "Map.hpp"

namespace motor_game{

    Map::Map(const int &x, const int &y, const int &z)
        : m_elements(negative_vector<Element*>(-(x*y*z),x*y*z)), m_x(x), m_y(y), m_z(z)
    {}




    Element *Map::element(const int &x, const int &y, const int &z) const{
        return m_elements[x + m_x*y + (m_x*m_y)*z];
    }

    void Map::printElement()
    {
      for (int i = m_elements.lower_limit(); i<m_elements.upper_limit();i++)
      {
        if (m_elements[i] != nullptr)
        {
          std::cout<<m_elements[i]->getPosition()<<" "<<m_elements[i]->getType()<<std::endl;
        }
      }
    }

    Element* Map::getElementi(const int i) const
    {
      return m_elements[i];
    }

    void Map::translateMap(const float &x, const float &z)
    {
      negative_vector<Element*> vectorTemp(-(m_x*m_y*m_z),(m_x*m_y*m_z));
      glm::mat4 translationMatrix = glm::translate(glm::mat4(1),glm::vec3(-x,0,-z));

      for (int i = m_elements.lower_limit(); i<m_elements.upper_limit();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = translationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));


           vectorTemp[m_elements[i]->getX() + m_x*m_elements[i]->getY() + (m_x*m_y)*m_elements[i]->getZ()] = m_elements[i];

         m_elements[i] = nullptr;
        }
      }
      for (int i = m_elements.lower_limit(); i<m_elements.upper_limit();i++)
      {
        m_elements[i] = vectorTemp[i];
      }
    }

    void Map::rotateRight()
    {

      float m_angle = -90;
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1),glm::radians(m_angle),glm::vec3(0,1,0));
      for (int i = m_elements.lower_limit(); i<m_elements.upper_limit();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = rotationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));
        }
      }

      int i = 0;
      while(m_elements[i] == nullptr)
      {
        i++;
      }

      std::cout<<m_elements[i]->getPosition()<<std::endl;

      if (fabs(fabs(m_elements[i]->getPosition().x) - fabs((round( m_elements[i]->getPosition().x))))>0.0005)
      {
        if (m_elements[i]->getPosition().x > 0)
        {
          translateMap((fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))),0);
        }
        else
        {
          std::cout<<fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))<<std::endl;
          translateMap(-(fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))),0);
        }
      }


    }

    void Map::rotateLeft()
    {

      float m_angle = 90;
      glm::mat4 rotationMatrix = glm::rotate(glm::mat4(1),glm::radians(m_angle),glm::vec3(0,1,0));
      for (int i = m_elements.lower_limit(); i<m_elements.upper_limit();i++)
      {
        if (m_elements[i] != nullptr)
        {
         glm::vec4 newPosition = rotationMatrix*glm::vec4(m_elements[i]->getPosition(), 1);
         m_elements[i]->setPosition(glm::vec3(newPosition));

        }
      }

      int i = 0;
      while(m_elements[i] == nullptr)
      {
        i++;
      }

      std::cout<<m_elements[i]->getPosition()<<std::endl;

      if (fabs(fabs(m_elements[i]->getPosition().x) - fabs((round( m_elements[i]->getPosition().x))))>0.0005)
      {
        if (m_elements[i]->getPosition().x > 0)
        {
          translateMap((fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))),0);
        }
        else
        {
          std::cout<<fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))<<std::endl;
          translateMap(-(fabs(m_elements[i]->getPosition().x) - fabs((round(m_elements[i]->getPosition().x)))),0);
        }
      }
    }

    void Map::element(
        const int &x, const int &y, const int &z,
        Element *element
    ){
        m_elements[x + m_x*y + (m_x*m_y)*z] = element;
    }
}
