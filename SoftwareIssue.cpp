#include "SoftwareIssue.h"

Software::Software(std::string user, double time) : Issue(user, 2)
{
	setTime(time);
}

void Software::setTime(double t)
{
	debugTime = t;
	return;
}

double Software::getTime()
{
	return debugTime;
}