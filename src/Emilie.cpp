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
 
     return 0;
 }
