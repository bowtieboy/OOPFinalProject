#include "FacilitiesIssue.h"

Facilities::Facilities(std::string user, int number) : Issue(user, 1)
{
	setWorkers(number);
}

void Facilities::setWorkers(int num)
{
	workers = num;
	return;
}

int Facilities::getWorkers()
{
	return workers;
}