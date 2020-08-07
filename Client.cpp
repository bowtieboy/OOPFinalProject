#include "Client.h"

// TODO: Nothing(?)

Client::Client(std::string u)
{
	setUsername(u);
}

// Setters
void Client::setUsername(std::string newUser)
{
	username = newUser;
	return;
}

// Getters
std::string Client::getUsername()
{
	return username;
}