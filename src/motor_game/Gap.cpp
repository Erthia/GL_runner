#include "../../include/motor_game/Gap.hpp"

namespace motor_game{

	Gap::Gap()
		:Element(glm::vec3(0), "Gap")
	{}
	Gap::Gap(const glm::vec3 &position = glm::vec3(0), const std::string &type)
            :Element(position, type)
     {}
    
    void Gap::collide(Hero *hero) {
        std::cout << "Game over : vous etes tombé dans un TROU :o" << std::endl;
    }
    
    void Gap::printElement() const{
        std::cout << "\nGAP INFORMATION :" << std::endl;
        PrintableElement::printElement();
    }
    
}
