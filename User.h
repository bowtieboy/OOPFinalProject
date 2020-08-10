#pragma once
#include <string>
#include "Client.h"
#include "Issue.h"
#include <vector>

class User : public Client
{
public:
	// Constructor
	User(std::string u);

	// Create an issue to be resolved by admin
	Issue* setIssue();

	// List the issues created by this user
	void listMyIssues(std::vector<Issue*> issues);

};