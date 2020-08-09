#include "User.h"

// TODO: The entire thing

User::User(std::string u) : Client(u)
{

}

// Create an issue to be resolved by admin
void User::setIssue()
{

}

// Get the status of a given issue
void User::getStatus(std::string issueName)
{

}

// Function to allow user to login if given the correct username
bool User::login(std::string nameInput)
{
	return (nameInput == username) ? true : false;
}

