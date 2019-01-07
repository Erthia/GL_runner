#include "checkRotation.hpp"

float setRotationZ(motor_game::Map map, float inX, float inZ)
{
  float z = 0;

  if (map.element(inX,0,inZ+ 1) != nullptr)
  {

    if (map.element(inX,0,inZ+ 1)->getType() == "right")
    {
      std::cout<<"inZ + 1 existe"<<std::endl;
      if (map.element(inX,0,inZ- 1) != nullptr)
      {

        if (map.element(inX,0,inZ- 1)->getType() == "right")
        {

          std::cout<<"inZ - 1 existe"<<std::endl;
          z = 0; 
        }
      }
      else
      {
        std::cout<<"CAS 1 - 2"<<std::endl;
        z = - 1;
      }
    }
  }

  if (map.element(inX,0,inZ+ 2) != nullptr)
  {

    if (map.element(inX,0,inZ+ 2)->getType() == "right")
    {

       std::cout<<"inZ + 2 existe"<<std::endl;
       z = + 1;
    }
  }

  if (map.element(inX,0,inZ- 2) != nullptr)
  {

    if (map.element(inX,0,inZ- 2)->getType() == "right")
    {

      std::cout<<"inZ - 1 existe"<<std::endl;
       z = - 1;
    }
  }

  return z;
}
