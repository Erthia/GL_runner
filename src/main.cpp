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
  Coin *coin2= new Coin(glm::vec3(0, 0,1), 100);
  Wall *wall3 = new Wall(glm::vec3(0, 1, 1));
  Wall *wall5 = new Wall(glm::vec3(1, 2, 1));
   Wall *wall4 = new Wall(glm::vec3(1, 1, 1));
  /*listElement2[1][2][1] = wall5;
  listElement2[0][1][1] = wall3;
  listElement2[1][1][1] = wall4;
  listElement2[0][0][1] = coin2;*/

  //wall3->description();
  Hero laurine(glm::vec3(2, 0, 0), 0, "laurine");

 //laurine.scanArray(listElement2, 'q');
  laurine.moveLeft();
  laurine.description();



  motor_game::Map map_1(50, 50, 50);
  map_1.element(0,0,1, coin2);
  map_1.element(0, 1, 1, wall3);
  map_1.element(1, 1, 1, wall4);
  map_1.element(1, 2, 1, wall5);

  laurine.checkCollide(map_1, 'q');

//std::map<int, std::map< int> , std::map<int> std::map<Element>>> my_map ;
 // std::map< std::string, std::map< int, double > > my_map ;
/*std::map< int, std::map<int, Element*>> my_map ;
Wall *wall = new Wall(glm::vec3(0,3,1));

  my_map[1][2] = wall ;
  my_map[1][2]->description();
  wall->description();
  wall->collide(laurine);
  my_map[1][2]->collision(laurine);*/

  /*std::vector<Element*> hello;

  hello.push_back(wall);
  for(size_t i=0; i<hello.size(); ++i)
  {
    hello[i]->description();
  }*/

  //laurine.moveRight();
  //coin1.collide(laurine);

 	//const Element* resultTest = emilie.scanList(myList, 'q');

/// cannot use switch case with string types so here's some ugly ifs
 	/*if( resultTest !=NULL)
 	{
 		if(resultTest->getType() == "Coin")
 		{
 				std::cout << "Olala emilie a attrapé une pièce" << std::endl;
 				//collide(player1, resultTest);
 		}
 				
 		
 			std::cout << "Olala emilie a touché quelque chose" << std::endl;
 		
 		
 	}*/
 	// à faire en fonction de l'objet renvoyé


  	return 0;
}
