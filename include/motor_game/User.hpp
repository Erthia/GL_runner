#pragma once

#include <iostream>
#include <string>


class User
{
  public:
    //methode
    User();

    /// \default constructor of class User
    User(std::string &inName);

  /// \brief method to retrieve the value of User's attributes
  inline std::string getName() const {
      return m_name;
  }

  /// \brief method to set the value of User's name
  inline void setName(std::string const &inName) {
      m_name = inName;
  }
  /// \brief method to test the value of User's attributes
  inline void printPlayer() const {
      std::cout<<"Name :"<<m_name<<std::endl;
     // std::cout<<"Score :"<<m_score<<std::endl;
  }

    /// \default destructor of our Element
    ~User();

  private:
    std::string m_name; /*!< name of User */


};
