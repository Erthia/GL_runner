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
#include <list>
#include <vector>
#include <map>



int main()
{
  
      /*
    Enemy singe(glm::vec3(0, 3, 5), "Enemy", 5);
    singe.printElement();
      User player1;
    player1.printPlayer();

    Wall p1(glm::vec3(5), "Mur");
    p1.printElement();

    Element e1(glm::vec3(5, 5, 5), "Element");
    e1.printElement();


    Floor floor1(glm::vec3(5), "Floor");
    floor1.printElement();

    Obstacle obs(glm::vec3(10), "Obstacle");
    obs.printElement();*/


  	Character emilie(glm::vec3(1, 0, 0), 0.000001, "emilie");
  	//emilie.printElement();
   // emilie.moveLeft();
    //emilie.printElement();


  	Wall wall1(glm::vec3(0,3,1));
   // wall1.printElement();

  	Coin coin1(glm::vec3(2, 0, 1), 100);
  	//coin1.printElement();


  	/*if(emilie.checkCollision(coin1) == 1)
 		std::cout << "récupération coin" << std::endl;
 	else 
 		std::cout << "pas de coin récupéré" << std::endl;

	if(emilie.checkCollision(coin1) == 1)
    
 		std::cout << "collision coin YYYYYYYYYYYES" << std::endl;
 	else 
 		std::cout << "pas collision" << std::endl;
*/
 /* Enemy test;
  test.printElement();

 	std::list<Element> myList;
 	myList.push_back(coin1);
 	myList.push_back(wall1);*/
  /*glm::tmat3x3<Element> listTest;
  listTest[0][0][1] = coin1;*/

  //std::vector<std::vector<std::vector<Element>>> listVec(1);
  //listVec[0][1][2] = wall1;
 //listVec[0][0][0] = coin1;


/*
std::vector< std::vector<std::vector<Element>>> vec(4, 4, std::vector<Element>(4));
vec[2][3][0] = coin1;
 emilie.scanVec(listVec, 'd');
*/////
 Element list5[10][10][10];
 //list5[0][0][1] = coin1;

  Element* listElement2[50][50][50];
  Coin *coin2= new Coin(glm::vec3(2, 0,5), 100);
  Wall *wall3 = new Wall(glm::vec3(0, 2, 1));
  Wall *wall5 = new Wall(glm::vec3(1, 0, 1));
   Wall *wall4 = new Wall(glm::vec3(1, 0, 1));
  listElement2[0][0][1] = wall5;
  listElement2[1][2][1] = wall3;
  listElement2[1][0][1] = wall4;

  //listElement2[2][0][1] = coin1;
  listElement2[2][0][1] = coin2;
  //wall3->description();
  Hero laurine(glm::vec3(0, 0, 0), 0, "laurine");

  laurine.scanArray(listElement2, 'd');
  laurine.moveRight();
      laurine.description();
  //wall3->description();

  //listElement2[0][0][1]->collision(laurine);

  //std::cout << wall5->getY()+1 << std::endl;


    /*coin2->collision(laurine);
  listElement2[2][0][1]->collision(laurine);*/


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
