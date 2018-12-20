#include "End.hpp"

namespace motor_game{
    
    void End::collide(Hero &hero){
        std::cout << "Fin du niveau atteinte" << std::endl;
    }
    
    void End::printElement() const{
        std::cout << "\nEND INFORMATION :" << std::endl;
        PrintableElement::printElement();
        
    }
    
}
