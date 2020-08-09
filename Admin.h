#pragma once
#include <string>
#include "Client.h"

// TODO: Nothing(?)

class Admin : Client
{
public:

	// Constructor
	Admin(std::string u, std::string p);

	// Setters
	void setPassword(std::string newPassword);

	// Getters
	std::string getPassword();

	// Polymorphic function
	virtual bool login(std::string nameInput, std::string passwordInput);

	// Print a list of the issues
	void printList();

	// Change the status for a selected issue
	int updateStatus();

private:
	std::string password;
};
