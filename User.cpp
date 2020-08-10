#include "User.h"
#include "FacilitiesIssue.h"
#include "HardwareIssue.h"
#include "SoftwareIssue.h"
#include "OtherIssue.h"
#include <iostream>

User::User(std::string u) : Client(u)
{

}

// Create an issue to be resolved by admin
Issue* User::setIssue()
{
	// Create a temp new issue with a place holder category
	Issue* newIssue = new Issue(getUsername(), 1);
	// Set the category of the new issue
	newIssue->issueList();
	
	switch (newIssue->getCategory())
	{
		// Create a new facilities issue
	case 1: {
		std::string workersStr;
		int workers;
		std::cout << "How many workers need to be assigned to this issue?: ";
		std::getline(std::cin, workersStr);
		workers = std::stoi(workersStr);

		Facilities* facIssue = new Facilities(newIssue->getUserName(), workers);
		return facIssue;
	}
		  // Create a new software issue
	case 2: {
		std::string timeStr;
		int time;
		std::cout << "How long will it take to resolve this issue?: ";
		std::getline(std::cin, timeStr);
		time = std::stoi(timeStr);

		Software* softIssue = new Software(newIssue->getUserName(), time);
		return softIssue;
	}
		  // Create a new hardware issue
	case 3: {
		std::string costStr;
		int cost;
		std::cout << "How much money will it cost to resolve this issue?: ";
		std::getline(std::cin, costStr);
		cost = std::stoi(costStr);

		Hardware* hardIssue = new Hardware(newIssue->getUserName(), cost);
		return hardIssue;
	}
		  // Create a new other issue
	case 4: {
		std::string description;
		std::cout << "Please give a brief description of the problem: " << std::endl;
		std::getline(std::cin, description);

		Other* otherIssue = new Other(newIssue->getUserName(), description);
		return otherIssue;
	}
		  // If none of the other options were met. This should never happen because of the check in the "setCategory" function
	default: {
		std::cout << "This screen should never be reached. If you are reading this line there is a bug." << std::endl;
		break;
	}
	}

	// This line should never be reached, but its here just in case
	return newIssue;

}

// List the issues created by this user
void User::listMyIssues(std::vector<Issue*> issues)
{
	// Iterate through the list
	for (int i = 0; i < issues.size(); i++)
	{
		// If the current user created the issue
		if (getUsername() == issues[i]->getUserName())
		{
			// Print the issue
			issues[i]->printIssue();
		}
	}

	return;
}
