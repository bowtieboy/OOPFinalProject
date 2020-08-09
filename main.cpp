#include <iostream>
#include "Admin.h"
#include "User.h"
#include "Issue.h"
#include <vector>

/*
	TODO Matt: Finish implementing the user functionality
	TODO Dylan: Implement the issue functionality
	TODO Andrew: Debugging (for now)
*/


using namespace std;

// Function prototypes used by main
bool loginAsClient();
int getClientType();
void createAdmin(string newUsername, string newPassword);
void createUser(string newUsername);
int checkAdmin(string userCheck, string passCheck);
bool checkUser(string userCheck);

// Global variables used by the main class
bool loggedIn;
Admin* activeAdmin;
User* activeUser;

// Vectors for the database
vector<Admin> admins;
vector<User> users;
vector<Issue*> issues;


int main()
{
	// Initialize as logged out
	loggedIn = false;

	// Wait for user to log in
	while (!loggedIn)
	{
		loggedIn = loginAsClient();
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
			return true;
		}
		// If the username exists but the password was wrong, state that
		else if (adminCheck == 2)
		{
			cout << "The password you entered for " << userAttempt << "was incorrect. Try again." << endl;
			cout << endl << endl;
			return false;
		}
		// If no username was found, ask the user if they would like to create an admin account
		else
		{
			cout << "No admin account was found that had the username " << userAttempt << ". Would you like to create one (y/n): ";
			string createAdminInput;
			getline(cin, createAdminInput);

			// If they would like to create a user, call the function
			if (createAdminInput == "y")
			{
				string creatingUsername, creatingPassword;
				cout << "Enter the username for the new admin: ";
				getline(cin, creatingUsername);
				cout << "Enter the password for the new admin: ";
				getline(cin, creatingPassword);
				createAdmin(creatingUsername, creatingPassword);
				return false;
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