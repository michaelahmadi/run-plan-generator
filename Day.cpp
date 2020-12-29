#include "runPlanGenerator.h"

Day::Day()
{
    
}

// setters and getters
void Day::setRunType(std::string runType)
{
    this->runType = runType;
}

std::string Day::getRunType()
{
    return runType;
}