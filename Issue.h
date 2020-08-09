#pragma once
#include <string>

class Issue
{
public:
	// Constructor
	Issue(std::string u, int c);

	// Setter prototypes
	void setUserName(std::string newName);
	void setCategory(int newCat);
	void setStatus(int newStat);
	 
	// Getter prototypes
	std::string getUserName();
	int getCategory();
	int getStatus();

	// Print issue prototype
	void printIssue();

	// Prints the issues for the user to choose from
	void issueList();

private:
	// Data members
	std::string userName;
	int category;
	int status;
};