#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <queue>
#include <list>

#include "Character.hpp"
#include "Element.hpp"
#include "Map.hpp"
#include "Enemy.hpp"

class Hero final : public Character
{
 public:
  	/// default constructor of class Hero
    Hero(); 

    /// constructor with parameters
    Hero(const glm::vec3 &position, const unsigned int &speed, const std::string &type = "Hero"); 
   
   	/// brief method to display the value of Hero's attributes
    void printElement() const;

    /// default destructor of our Hero
    ~Hero(); 

	/// brief method to increment the score of Hero
	/// takes a parameter to pass the value to add to the score
	inline void setScore(int const &inScore){
	    m_score += inScore;
	 }

	/// brief method to retrieve the score of Hero
	inline int getScore() const{
		return m_score;
	}

  inline void isAlive(const bool &status)
  {
    m_isAlive = status;
  }
  inline bool getStatus() const {
    return m_isAlive;
  }

  /// method called when the hero tries to move
  /// this method checks if there is an element where the Hero wants to move
  /// then uses the collide methods to do something according to what type of element we're dealing with
    bool scanArray(Element* (*list)[50][50], const char &movement);

    /// method checking the collision between a character instance and a printableElement instance which is passed as a parameter
    bool checkCollision(const Element &b);

    bool checkCollide(motor_game::Map &map, const char &movement);
    
    void setEnemy(Enemy *enemy){
        m_enemy=enemy;
    }
    
    /// method allowing the Hero to move forward on the z axis
    /// manage also the enemy's comportment
    void run() override;

    /// method allowing the Hero to jump up the y axis
    void up() override;

    /// method allowing the Hero to crawl under obstacles: their height is then 1 instead of 2
    void down() override;

    /// method allowing the Hero to move left along the x axis
    void moveLeft() override;

    /// method allowing the Hero to move right along the x axis
    void moveRight() override;

  	private:
  	unsigned int m_score; /*!< score of Hero */
    bool m_isAlive=true; /*!< status of Hero, true by default*/
    
    // POUR GERER LE DEPLACEMENT
    std::queue<char> m_nextMov;
    std::list<int> m_timeNextMov;
    Enemy *m_enemy;

};

