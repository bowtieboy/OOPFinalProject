#pragma once
#include <string>

class Client
{
public:
	// Constructor
	Client(std::string u);

	// Setters
	void setUsername(std::string newUser);

	// Getters
	std::string getUsername();

protected:
	std::string username;
};