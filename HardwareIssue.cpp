#include "HardwareIssue.h"

Hardware::Hardware(std::string u, double price) : Issue(u, 3)
{
	setHardware(price);
}

void Hardware::setHardware(double price)
{
	fixedCost = price;
	return;
}

double Hardware::getHardware()
{
	return fixedCost;
}

