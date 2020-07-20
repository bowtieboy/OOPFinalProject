#pragma once
#include <string>

class User
{
public:
	// Constructor
	User(std::string u, int c);

	// Setter prototypes
	void setUserName(std::string newName);
	void setCategory(int newCat);
	void setStatus(int newStat);
	
	// Getter prototypes
	std::string getUserName();
	int getCategory();
	int getStatus();

private:
	// Data members
	std::string userName;
	int category;
	int status;
};