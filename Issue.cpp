#include "Issue.h"
#include <iostream>

// Constructor defined in header
Issue::Issue(std::string u, int c)
{
	userName = u;
	setCategory(c); // This is using the function in order to make sure that the user input for selection is within the bounds
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
	if (newCat <= 4 && newCat > 0)
		category = newCat;
	else
		std::cout << "Incorrect Entery" << std::endl;
	return;
}
void Issue::setStatus(int newStat)
{
	status = newStat;
	return;
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

void Issue::issueList()
{
	std::cout << "Select your issue from the list below:" << std::endl;
	std::cout << "1. Facility" << std::endl;
	std::cout << "2. Software" << std::endl;
	std::cout << "3. Hardware" << std::endl;
	std::cout << "4. Other" << std::endl;
	std::string issueCatStr;
	int issueCat;
	std::getline(std::cin, issueCatStr);
	issueCat = std::stoi(issueCatStr);
	setCategory(issueCat);
}

// Print issue function defined in header
void Issue::printIssue()
{
	std::cout << "User name of issue creator: " << getUserName();
	std::cout << "	Issue category: " << getCategory();
	std::cout << "	Issue status: " << getStatus() << std::endl;
}