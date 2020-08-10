#include <iostream>
#include "Admin.h"
#include "User.h"
#include "Issue.h"
#include <vector>

using namespace std;

// Function prototypes used by main
bool loginAsClient();
int getClientType();
void createAdmin(string newUsername, string newPassword);
void createUser(string newUsername);
int checkAdmin(string userCheck, string passCheck);
bool checkUser(string userCheck);
void adminMenu();
void userMenu();

// Global variables used by the main class
bool loggedIn, running;
Admin* activeAdmin;
User* activeUser;
int currentActiveClient;

// Vectors for the database
vector<Admin> admins;
vector<User> users;
vector<Issue*> issues;

int main()
{
	// Initialize the program as running
	running = true;
	// Initialize as logged out
	loggedIn = false;
	// Set current active client to invalid
	currentActiveClient = -1;

	while (running)
	{
		// Wait for user to log in
		while (!loggedIn)
		{
			loggedIn = loginAsClient();
		}

		// If client is logged in as admin
		if (currentActiveClient == 1)
		{
			adminMenu();
		}
		// If client is logged in as user
		else if (currentActiveClient == 2)
		{
			userMenu();
		}
		// If any other value exists (in which case a bug has occurred)
		else
		{
			cout << "This is not a valid state for the database. Please restart the system and report to an admin." << endl;
			break;
		}

	}
	

	return 0;
}

// Logs the client in as either a user or an admin
bool loginAsClient()
{
	// Determine which type of user to access and get the basic info
	string userAttempt;
	int user = getClientType();
	cout << "Enter the username for the account: ";
	getline(cin, userAttempt);

	// If the client is an admin
	if (user == 1)
	{
		cout << "Enter the password for the admin account: ";
		string passwordAttempt;
		getline(cin, passwordAttempt);
		int adminCheck = checkAdmin(userAttempt, passwordAttempt);

		// If the admin exists, set them as the activeAdmin
		if (adminCheck == 1)
		{
			cout << "You are now logged in as " << userAttempt << endl;
			currentActiveClient = 1;
			return true;
		}
		// If the username exists but the password was wrong, state that
		else if (adminCheck == 2)
		{
			cout << "The password you entered for " << userAttempt << " was incorrect. Try again." << endl;
			cout << endl << endl;
			return false;
		}
		// If no username was found, ask the user if they would like to create an admin account
		else
		{
			cout << "No admin account was found that had the username " << userAttempt << ". Would you like to create one (y/n)?: ";
			string createAdminInput;
			getline(cin, createAdminInput);

			// If they would like to create a user, call the function
			if (createAdminInput == "y")
			{
				string creatingPassword;
				cout << "Enter the password for the new admin: ";
				getline(cin, creatingPassword);
				createAdmin(userAttempt, creatingPassword);
				activeAdmin = &admins.back();
				return true;
			}
			// Otherwise indent the menu and start again
			else
			{
				cout << endl << endl;
				return false;
			}
		}
	}
	// Otherwise if the client is a user
	else if (user == 2)
	{
		// If a user exists with the given username, log them in
		if (checkUser(userAttempt))
		{
			cout << "You are now logged in as " << userAttempt << endl;
			currentActiveClient = 2;
			return true;
		}
		// Otherwise ask if they would like to create a new user
		else
		{
			cout << "No user account was found that had the username " << userAttempt << ". Would you like to create one (y/n)?: ";
			string createUserInput;
			getline(cin, createUserInput);

			// If they would like to create a new user
			if (createUserInput == "y")
			{
				createUser(userAttempt);
				activeUser = &users.back();
				return true;
			}
			else
			{
				return false;
			}
		}
	}
	// Otherwise restart the loop
	else
	{
		return false;
	}
}

int getClientType()
{
	string userInStr;
	int userIn = -1;
	cout << "Enter the client type trying to login" << endl;
	cout << "(1) Admin" << endl;
	cout << "(2) User" << endl;

	getline(cin, userInStr);
	userIn = stoi(userInStr);
	return userIn;
}

// Creates an admin and pushes them onto the database
void createAdmin(string newUsername, string newPassword)
{
	Admin newAdmin = Admin(newUsername, newPassword);
	admins.push_back(newAdmin);
	return;
}

void createUser(string newUsername)
{
	User newUser = User(newUsername);
	users.push_back(newUser);
	return;
}

// Checks to see if an admin with the username and password exists in the database
int checkAdmin(string userCheck, string passCheck)
{
	// Determines what type of return condition to send
	int returnVal = -1;

	// Iterate through the vector
	for (int i = 0; i < admins.size(); i++)
	{
		if (userCheck == admins[i].getUsername())
		{
			// Indicates that the username was found but not the password
			returnVal = 2;

			if (passCheck == admins[i].getPassword())
			{
				// Indicates that the username and password matched
				returnVal = 1;
				// Set the active admin as the one that matched
				activeAdmin = &admins[i];
				// Return the status
				return returnVal;
			}

			// Return that a username was found but the password did not match
			return returnVal;
		}
	}

	// Return that no username was found that matched the given
	return returnVal;
}

bool checkUser(string userCheck)
{
	// Iterate through the vector
	for (int i = 0; i < users.size(); i++)
	{
		// If a mathing username is found
		if (userCheck == users[i].getUsername())
		{
			// Set the active user
			activeUser = &users[i];
			// Return that a match was found
			return true;
		}
	}

	// Return that no match was found
	return false;
}

void adminMenu()
{
	// Get input from admin
	cout << endl;
	cout << "Hello admin. Please select an option: " << endl;
	cout << "(1) Update password" << endl;
	cout << "(2) View all known issues" << endl;
	cout << "(3) Change the status of an issue" << endl;
	cout << "(4) Sign out of the database" << endl;
	cout << "(5) Close the database" << endl;
	cout << "What is your selection?: ";
	string adminInputStr;
	int adminInput = -1;
	getline(cin, adminInputStr);
	adminInput = stoi(adminInputStr);

	// Do the action that the admin requested
	switch (adminInput)
	{
		// Change the admins password
	case 1:	{
		cout << "What would you like your new password to be?: ";
		string newPassword;
		getline(cin, newPassword);
		activeAdmin->setPassword(newPassword);
		cout << "Your password has been updated!" << endl;
		break;
		};

		  // Print all the issues that are in the database
	case 2:
		activeAdmin->printList(issues);
		break;
	case 3: {

		// Get the relevant information
		string issueUsername, issueCatStr;
		int issueCat;
		bool issueFound = false;
		cout << "Enter the username of the person who created the issue: ";
		getline(cin, issueUsername);
		cout << "Enter the category type of the issue: ";
		getline(cin, issueCatStr);
		issueCat = stoi(issueCatStr);

		// Loop through the database
		for (int i = 0; i < issues.size(); i++)
		{
			if (issueUsername == issues[i]->getUserName() && issueCat == issues[i]->getCategory())
			{
				// If the issue was found, update it
				activeAdmin->updateStatus(issues[i]);
				issueFound = true;
			}
		}

		// If issue wasnt found, display error message
		if (!issueFound)
		{
			cout << "No issue was found that matched the username and category given." << endl;
		}

		break;
	}

		// Log out of the database
	case 4:
		loggedIn = false;
		cout << "You have signed out of the database!" << endl;
		break;

		// Close the program
	case 5:
		running = false;
		cout << "Closing the database!" << endl;
		break;

		// If none of the other options were selected
	default:
		cout << "That is not a valid option!" << endl;
		break;
	}
}

void userMenu()
{
	// Get input from user
	cout << endl;
	cout << "Hello user. Please select an option:" << endl;
	cout << "(1) Create a new issue" << endl;
	cout << "(2) List all my issues" << endl;
	cout << "(3) Sign out of the database" << endl;
	cout << "(4) Close the database" << endl;
	string userInputStr;
	int userInput = -1;
	getline(cin, userInputStr);
	userInput = stoi(userInputStr);

	// Do the action that the user requested
	switch (userInput)
	{
		// Create a new issue and push it onto the vector
	case 1: {
		Issue* newIssue = activeUser->setIssue();
		issues.push_back(newIssue);
		break;
	}

		// List the users issues
	case 2:
		activeUser->listMyIssues(issues);
		break;

		// Log out of the database
	case 3:
		loggedIn = false;
		cout << "You have signed out of the database!" << endl;
		break;

		// Quit the program
	case 4:
		running = false;
		cout << "Closing the database!" << endl;
		break;

		// If none of the other options were selected
	default:
		cout << "That is not a valid option!" << endl;
		break;
	}
}