#pragma once
#include <string>

// TODO: Nothing(?)

class Client
{
public:
	// Constructor
	Client(std::string u);

	// Setters
	void setUsername(std::string newUser);

	// Getters
	std::string getUsername();

	// Polymorphic
	virtual bool login() = 0;

protected:
	std::string username;
};