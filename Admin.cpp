#include "Admin.h"
#include <iostream>

// TODO: Finish printList and updateStatus functions

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
void Admin::printList()
{

}


// The options for the user to select from to update the progress on the problem
int Admin::updateStatus()
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

	return selection;
}