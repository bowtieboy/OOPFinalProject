#include <string>
#include "Issue.h"

class Software : Issue
{
public:
	Software(std::string user, double time);

	void setTime(double time);

	double getTime();
		

private:
	double debugTime;
};
