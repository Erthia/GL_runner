#include "Gap.hpp"

namespace motor_game{
    
    void Gap::collide(Hero &hero) {
        std::cout << "Game over : vous etes tombé dans un TROU :o" << std::endl;
    }
    
    void End::printElement() const{
        std::cout << "\nGAP INFORMATION :" << std::endl;
        PrintableElement::printElement();
    }
    
}
