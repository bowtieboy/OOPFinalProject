#pragma once
#include <string>
#include "client.h"

class User : Client
{
public:
	// Constructor
	User(std::string u);

	// Create an issue to be resolved by admin
	void setIssue();

	// Get the status of a given issue
	void getStatus(std::string issueName);

	virtual bool login(std::string nameInput);

private:
};