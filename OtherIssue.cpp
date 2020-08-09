#include "OtherIssue.h"

Other::Other(std::string u, std::string problem) : Issue(u, 4)
{
	setOther(problem);
}

void Other::setOther(std::string prob)
{
	problem = prob;
	return;
}

std::string Other::getOther()
{
	return problem;
}

