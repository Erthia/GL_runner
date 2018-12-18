#include <iostream>
#include "../include/exception/ExceptIMAC.hpp"
#include "Hero.hpp"
#include "PrintableElement.hpp"
#include "Character.hpp"
#include "End.hpp"
#include <GL/glew.h>
#include <glm/glm.hpp>
#include "Gap.hpp"

int main(){
    //test ExceptIMAC class
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
    motor_game::Gap gap(glm::vec3(1,2,3));
    gap.collide(milie);
    gap.printElement;
    
    return 0;
}