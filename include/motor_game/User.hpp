#pragma once

#include <iostream>
#include <string>


class User
{
  public:
    //methode
    User()
      :m_name("Unknown"),m_score(0)
    {}

    User(std::string inName)
      :m_name(inName),m_score(0)
    {}

    ~User();

    inline
    std::string getName() const
    {
      return m_name;
    }

    inline
    void setName(std::string const &inName)
    {
      m_name = inName;
    }

    


    inline
    void printPlayer()
    {
      std::cout<<"Name :"<<m_name<<std::endl;
      std::cout<<"Score :"<<m_score<<std::endl;
    }



  private:
    //attributs
    std::string m_name;


};
