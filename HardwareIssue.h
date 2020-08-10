#include <string>
#include "Issue.h"

class Hardware : public Issue
{
public:
	Hardware(std::string user, double cost);

	void setHardware(double price);

	double getHardware();

private:
	double fixedCost;
};

