#include <string>
#include "Issue.h"

class Software : public Issue
{
public:
	Software(std::string user, double time);

	void setTime(double time);

	double getTime();
		

private:
	double debugTime;
};
