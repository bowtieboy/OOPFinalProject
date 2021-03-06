#include "Admin.h"
#include <iostream>

// Constructor
Admin::Admin(std::string u, std::string p) : Client(u)
{
	setPassword(p);
}

// Setters
void Admin::setPassword(std::string newPassword)
{
	password = newPassword;
	return;
}

// Getters
std::string Admin::getPassword()
{
	return password;
}

// Print a list of the issues
void Admin::printList(std::vector<Issue*> issues)
{
	std::cout << std::endl;
	std::cout << "There are currently " << issues.size() << " issues in the database." << std::endl;

	// Iterate through the list of issues
	for (int i = 0; i < issues.size(); i++)
	{
		issues[i]->printIssue();
	}

	return;
}


// The options for the user to select from to update the progress on the problem
void Admin::updateStatus(Issue* currentIssue)
{ 
	int selection;
	std::string selectionString;
	// TODO: Have admin select the issue they are going to modify

	// The default would be pending when it starts.
	std::cout << "Select status: " << std::endl;
	std::cout << "1. Resolved" << std::endl;
	std::cout << "2. Unresolved" << std::endl;
	std::cout << "3. Opened" << std::endl;
	std::getline(std::cin, selectionString);
	selection = stoi(selectionString);

	currentIssue->setStatus(selection);
	std::cout << "The issue status has been updated!" << std::endl;

	return;
}