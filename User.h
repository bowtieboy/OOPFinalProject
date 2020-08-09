#pragma once
#include <string>
#include "client.h"

// TODO: The entire thing

class User : Client
{
public:
	User(std::string u);

	void setIssue();

	void getStatus();

private:
};