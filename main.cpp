#include <iostream>
#include <cstdio>
#include <SDL/SDL.h>
#include <GL/glew.h>
#include "include/motor_game/PrintableElement.hpp"
#include "glimac/include/glimac/glm.hpp"
#include <glm/glm.hpp>


//using namespace GL_runner;
// CECI NE FONCTIONNE PAS A CAUSE DE GLM

int main(void) 
{

   PrintableElement p1(glm::vec3(5), "Mur");


// test
    p1.printElement();


    return 0;
}


//g++ -Wall -O2 main.cpp src/motor_game/PrintableElement.cpp -o main
