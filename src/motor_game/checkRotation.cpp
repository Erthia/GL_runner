#include "checkRotation.hpp"

int setRotationZ(motor_game::Map map, int inX, int inZ)
{
  int z = 0;

  if (map.element(inX,0,inZ+ 1) != nullptr)
  {
    std::cout<<"Dans la boucle 1"<<std::endl;
    if (map.element(inX,0,inZ+ 1)->getType() == "right")
    {
      std::cout<<"1/ inZ + 1 existe"<<std::endl;
      if (map.element(inX,0,inZ- 1) != nullptr)
      {

        if (map.element(inX,0,inZ- 1)->getType() == "right")
        {

          std::cout<<"2/ inZ - 1 existe"<<std::endl;
          z = 0;
          return z;
        }
      }
      else
      {
        std::cout<<"CAS 1 - 2"<<std::endl;
        z = 1;
        return z;
      }
    }
  }

  if (map.element(inX,0,inZ+ 2) != nullptr)
  {
    std::cout<<"Dans la boucle 2"<<std::endl;
    if (map.element(inX,0,inZ+ 2)->getType() == "right")
    {

       std::cout<<"3/ inZ + 2 existe"<<std::endl;
       z = + 1;
       return z;
    }
  }

  if (map.element(inX,0,inZ - 2) != nullptr)
  {
    std::cout<<"Dans la boucle 3"<<std::endl;
    if (map.element(inX,0,inZ - 2)->getType() == "right")
    {

       std::cout<<"4/ inZ - 2 existe"<<std::endl;
       z = -1;
       return z;
    }
  }

  return z;
}
