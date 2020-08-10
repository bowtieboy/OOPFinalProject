#include <string>
#include "Issue.h"

class Facilities : public Issue
{
public:
	Facilities(std::string u, int number);

	void setWorkers(int number);

	int getWorkers();
private:
	int workers;
};
