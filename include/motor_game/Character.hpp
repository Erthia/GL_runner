#pragma once

#include <iostream>
#include <string>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <list>


// héritage de class printableElement
// besoin d'inclure element.hpp ? à vérifier
#include "PrintableElement.hpp"
#include "Element.hpp"

class Character : public PrintableElement
{
  public:
    /// \default constructor of class character
    /// \our class character is only abstract
    /// \contrary to other elements, a character isn't a cube of 1*1*1: it's a pavement with an height of 2
    Character(); 

    /// \constructor with parameters
    /// \param type : a string which will allow us to know what kind of character we're dealing with
    /// \param speed : the speed in which our character will run, can be changed with bonus elements
    Character(const glm::vec3 &position, const std::string &type, const unsigned int &speed);

    /// \method allowing the character to move forward on the z axis
    void run();

  /// \method allowing the character to jump up the y axis
    void up();

  /// \method allowing the character to crawl under obstacles: their height is then 1 instead of 2
    void down();

    /// \method allowing the character to move left along the x axis
    void moveLeft();

    /// \method allowing the character to move right along the x axis
    void moveRight();



    /// \method checking the collision between a character instance and a printableElement instance which is passed as a parameter
    bool checkCollision(const PrintableElement &b);


    /// \method checking the collision between a character instance and a printableElement instance which is passed as a parameter
    /// \this method is activated when the player wants to move and checks if the position is available. the direction of the movement (determined by the pressed touch) is passed as a second parameter.
    bool checkCollisionMovement(const PrintableElement &b, const char &movement);

    /// \method scanning a list of Element objects until a collision is detected (using our checkCollision methods)
    /// \this method is activated when the player wants to move and checks if the position is available. the direction of the movement (determined by the pressed touch) is passed as a second parameter.
    void scanList(std::list<Element> &list, const char &movement);

    //const Element* scanList(const std::list<Element> &list, const char &movement);

    /// \brief method to test the value of our Element's attributes: TO ERASE ????
    virtual void printElement() const;

    //////////////////////////// TO ADD : speed changer with bonus !!!! VOIR SI ON PEUT FAIRE UNE SCANLIST SANS PARAMETRE DE MOUVEMENT

    /// \default destructor of class character
    ~Character(); 


  protected:
  unsigned int m_speed;

};
