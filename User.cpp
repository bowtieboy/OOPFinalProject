#include "User.h"

// Constructor defined in header
User::User(std::string u, int c)
{
	userName = u;
	category = c;
	status = 0; // Status starts as unresolved
}

// Setter functions defined in header
void User::setUserName(std::string newName)
{
	userName = newName;
	return;
}
void User::setCategory(int newCat)
{
	category = newCat;
}
void User::setStatus(int newStat)
{
	status = newStat;
}
// Getter functions defined in header
std::string User::getUserName()
{
	return userName;
}
int User::getCategory()
{
	return category;
}
int User::getStatus()
{
	return status;
}