#include "Issue.h"

// Constructor defined in header
Issue::Issue(std::string u, int c)
{
	userName = u;
	category = c;
	status = 0; // Status starts as unresolved
}

// Setter functions defined in header
void Issue::setUserName(std::string newName)
{
	userName = newName;
	return;
}
void Issue::setCategory(int newCat)
{
	category = newCat;
}
void Issue::setStatus(int newStat)
{
	status = newStat;
}
// Getter functions defined in header
std::string Issue::getUserName()
{
	return userName;
}
int Issue::getCategory()
{
	return category;
}
int Issue::getStatus()
{
	return status;
}