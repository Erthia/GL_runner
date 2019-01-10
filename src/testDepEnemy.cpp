#include "Hero.hpp"

int main(){
    Hero hero(glm::vec3(0,0,5), 1);
    Enemy enemy(glm::vec3(0,0,0), 1);
    
    hero.setEnemy(&enemy);
    
    for(size_t i=0; i<30; i++){
        if(i==5) hero.moveLeft();
        if(i==15) hero.moveRight();
        if(i==17) hero.moveRight();
        if(i==18) hero.moveLeft();
        
        hero.run();
        
        std::cout << "Hero coord : " << hero.getPosition() << std::endl;
        std::cout << "Enemy coord : " << enemy.getPosition() << std::endl;
    }
    
    
    return 0;
}
