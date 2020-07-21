#include "Admin.h"
#include <iostream>
// The options for the user to select from to update the progress on the problem
void Admin::status()
{ // The defalt would be pending when it starts.
	std::cout << "Select status: " << std::endl;
	std::cout << "1. Resolved" << std::endl;
	std::cout << "2. Unresolved" << std::endl;
	std::cout << "3. Opened" << std::endl;
}