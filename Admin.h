#pragma once
#include <string>
#include <vector>
#include "Client.h"
#include "Issue.h"

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
	void updateStatus(Issue* currentIssue);

private:
	std::string password;
};
