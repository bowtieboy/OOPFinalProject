#pragma once
#include <string>
#include "Client.h"
#include "Issue.h"

class User : public Client
{
public:
	// Constructor
	User(std::string u);

	// Create an issue to be resolved by admin
	Issue setIssue();

	// Get the status of a given issue
	void getStatus(std::string issueName);

	// List the issues created by this user
	void listMyIssues();

	// Polymorphic function
	bool login(std::string nameInput);

};