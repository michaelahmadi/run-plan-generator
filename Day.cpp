#include "RunPlanGenerator.h"

Day::Day()
{
    
}

Day::Day(std::string runType, int miles)
{
    this->runType = runType;
    this->miles = miles;
}

void Day::addMile()
{
    miles++;
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

int Day::getMiles()
{
    return miles;
}