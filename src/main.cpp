#include <iostream>
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

int main()
{
  	User player1;
  	player1.printPlayer();

  	PrintableElement p1(glm::vec3(5), "Mur");
  	p1.printElement();

  	Element e1(glm::vec3(5, 5, 5), "Element");
  	e1.printElement();

  	Character emilie(glm::vec3(0, 0, 0), "Humaine", 0.000001);
  	emilie.printElement();

  	Enemy singe(glm::vec3(0, 3, 5), "Enemy", 5);
  	singe.printElement();

  	Coin coin1(glm::vec3(0, 0, 1), "Coin", 100);
  	coin1.printElement();

  	Wall wall1(glm::vec3(0,1,1), "Wall");
  	wall1.printElement();

  	Floor floor1(glm::vec3(5), "Floor");
  	floor1.printElement();

  	Obstacle obs(glm::vec3(10), "Obstacle");
  	obs.printElement();

  	if(emilie.checkCollision(coin1) == 1)
 		std::cout << "récupération coin" << std::endl;
 	else 
 		std::cout << "pas de coin récupéré" << std::endl;


	if(emilie.checkCollisionMovement(wall1, 's') == 1)
 		std::cout << "collision" << std::endl;
 	else 
 		std::cout << "pas collision" << std::endl;



  	return 0;
}
