#include <string>
#include "Issue.h"

class Other : public Issue
{
public:
	Other(std::string user, std::string issue);

	void setOther(std::string prob);

	std::string getOther();
private:
	std::string problem;
};