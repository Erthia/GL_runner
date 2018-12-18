#include "User.hpp"

User::User()
	:m_name("Unknown")
{}

User::User(std::string &inName)
     :m_name(inName)
{}

User::~User()
{}

