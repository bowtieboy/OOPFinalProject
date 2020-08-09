#pragma once
#include <string>
#include <vector>
#include "Client.h"
#include "Issue.h"

// TODO: Nothing(?)

class Admin : public Client
{
public:

	// Constructor
	Admin(std::string u, std::string p);

	// Setters
	void setPassword(std::string newPassword);

	// Getters
	std::string getPassword();

	// Print a list of the issues
	void printList(std::vector<Issue*> issues);

	// Change the status for a selected issue
	int updateStatus();

private:
	std::string password;
};
