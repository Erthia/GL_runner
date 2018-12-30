#include "Turn.hpp"

namespace motor_game{
    
    Turn::Turn(const glm::vec3 &position, const std::string &type)
        : Floor(position, type) {}

    void Turn::printElement() const{
        std::cout << "\nFLOOR INFORMATION : it's a " << m_type << " turn" << std::endl;
        PrintableElement::printElement();
    }

    void Turn::collide(Hero *hero) const{
        // modifie la caméra
        // modifie l'axe d'avancée du personnage
        if(m_type=="left")
            std::cout << "The Hero turns left !" << std::endl;
        else if(m_type=="right")
            std::cout << "The Hero turns right !" << std::endl;
        else assert(false);
    }
}
