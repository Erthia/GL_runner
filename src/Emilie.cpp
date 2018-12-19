 #include <iostream>
 #include "../include/exception/ExceptIMAC.hpp"
 #include "Hero.hpp"
 #include "PrintableElement.hpp"
 #include "Character.hpp"
 #include "End.hpp"
 #include <GL/glew.h>
 #include <glm/glm.hpp>
 #include "Gap.hpp"
 #include "PPM.hpp"
 #include "Map.hpp"
 #include "Wall.hpp"
 #include "Coin.hpp"
 
 int main(){
     //tests
     /*
     try{
         if(true) THROW_EXCEPTION("Exception lancée !");
     }
     catch(const std::exception &e){
         std::cerr << e.what() << std::endl;
     }
 
     Hero milie;
     milie.setPosition(glm::vec3(1,1,1));
 
     milie.printElement();
 
     motor_game::End fiiin;
     motor_game::End fin(glm::vec3(1,1,2));
     fin.collide(milie);
     fin.printElement();
 
     std::cout << "\nTest GAP" << std::endl;
     motor_game::Gap gap(glm::vec3(1,2,3), "gap");
     gap.collide(&milie);
     gap.printElement();
     
     */
     //test PPM and PPM reader class
     /*
     PPMreader readerDeLaMort("level_01_ASCII.ppm");
     PPM amazingPPM = readerDeLaMort.readFile();
     
     Hero milie=amazingPPM.hero();
     milie.printElement();
     
     Enemy laurine=amazingPPM.enemy();
     enemy.printElement();
     
     Element[][][] listKK=amazingPPM.elements();
     for(unsigned int i=0; i<amazingPPM.x(); i++){
        for(unsigned int j=0; j<amazingPPM.y(); j++){
            for(unsigned int k=0; k<amazingPPM.z(); k++){
                listKK[i][j][k].printElement;
            }
        }
    }
    */
    //test Map class
    motor_game::Map map_1;
    motor_game::Map map_2(50, 2, 50);
    motor_game::Map map_3(map_2);
    motor_game::Map map_4 = map_2;
    map_1.x()=10;
    map_1.y()=20;
    map_1.z()=12;
    
    std::cout << "map_1.x() : " << map_1.x() << std::endl;
    std::cout << "map_1.y() : " << map_1.y() << std::endl;
    std::cout << "map_1.z() : " << map_1.z() << std::endl;
    
    Wall milie(glm::vec3(0,1,2));
    Coin laurine(glm::vec3(9,19,11), 100);
    map_1.element(0,1,2)=milie;
    map_1.element(9, 19, 11)=laurine;
    
    map_1.element(0,1,2).printElement;
    map_1.element(9, 19, 11).printElement;
 
     return 0;
 }
