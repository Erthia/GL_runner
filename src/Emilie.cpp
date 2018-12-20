 #include <iostream>
 #include <GL/glew.h>
 #include <glm/glm.hpp>
 
 #include "ExceptIMAC.hpp"
 #include "Hero.hpp"
 #include "PrintableElement.hpp"
 #include "Character.hpp"
 #include "End.hpp"
 #include "Gap.hpp"
 #include "PPM.hpp"
 #include "PPMreader.hpp"
 #include "Map.hpp"
 #include "Wall.hpp"
 #include "Coin.hpp"
 #include "Element.hpp"
 
 int main(){
    //test Map class
    std::cout << "TEST MAP CLASS" << std::endl;
    
    motor_game::Map map_2(3, 50, 5);
    motor_game::Map map_1 = map_2;
    
    std::cout << "map_1.x() : " << map_1.x() << std::endl;
    std::cout << "map_1.y() : " << map_1.y() << std::endl;
    std::cout << "map_1.z() : " << map_1.z() << std::endl;
    
    Wall *milie = new Wall(glm::vec3(0,1,2));
    Coin *laurine = new Coin(glm::vec3(2,49,4), 100);
    
    map_2.element(0,1,2,milie);
    map_2.element(0,1,2)->description();
   
    map_2.element(2, 49, 4,laurine);
    map_2.element(2, 49, 4)->description();
    
    //test PPM class
    std::cout << "\nTEST PPM CLASS" << std::endl;
    
    
    motor_game::PPMreader theReader("level_01_ASCII.ppm");
    motor_game::PPM ppmCool=theReader.readFile();

    
    for(unsigned int i=0; i<ppmCool.x(); i++){
        std::cout << "i: " << i << std::endl;
        for(unsigned int j=0; j<ppmCool.y(); j++){
            std::cout << "j: " << j << std::endl;
            for(unsigned int k=0; k<ppmCool.z(); k++){
                std::cout << "k: " << k << std::endl;
                if(ppmCool.map().element(i, j, k)==nullptr)
                    std::cout
                        << "Element null aux coordonnées ("
                        << i << ", " << j << ", " << k << " )"
                        << std::endl;
                else
                    ppmCool.map().element(i, j, k)->description();
            }
        }
    }
    
    
    
 
    return 0;
}
