#include <iostream>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "User.hpp"
#include "PrintableElement.hpp"
#include "Element.hpp"
#include "Character.hpp"
#include "Coin.hpp"
#include "Hero.hpp"
#include "Enemy.hpp"
#include "Wall.hpp"
#include "Floor.hpp"
#include "Obstacle.hpp"
#include "Gap.hpp"
#include "Map.hpp"
#include <list>
#include <vector>
#include <map>



int main()
{


  //Element* listElement2[50][50][50];
  Coin *coin2= new Coin(glm::vec3(0, 2,1), 100);
  Obstacle *wall4 = new Obstacle(glm::vec3(0, 4, 1));
  Obstacle *wall3 = new Obstacle(glm::vec3(0, 1, 1));
  Obstacle *wall5 = new Obstacle(glm::vec3(1, 2, 1));
  //Obstacle *obs = new Obstacle(glm::vec3(1, 1, 1));
  Coin *coin = new Coin(glm::vec3(1, 1, 1), 200);
  /*listElement2[1][2][1] = wall5;
  listElement2[0][1][1] = wall3;
  listElement2[1][1][1] = wall4;
  listElement2[0][0][1] = coin2;*/

  //wall3->description();
  Hero *laurine = new Hero(glm::vec3(1, 0, 0), 0, "laurine");

 //laurine.scanArray(listElement2, 'q');
  //laurine.moveLeft();
  laurine->description();

  motor_game::Map map_1(50, 50, 50);
  map_1.element(0,4,1, wall4);
  map_1.element(0,2,1, coin2);
  map_1.element(0, 1, 1, wall3);
  map_1.element(1, 1, 1, coin);
  map_1.element(1, 2, 1, wall5);
  //map_1.element(1, 1, 1, obs);

  laurine->checkCollide(map_1, 'z');
  if(laurine->getStatus() == false)
  {
        std::cout << "GAME OVER" << std::endl;
        delete laurine;

  } 

  	return 0;
}
