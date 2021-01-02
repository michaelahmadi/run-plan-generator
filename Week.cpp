#include "runPlanGenerator.h"

Week::Week()
{
    mileage = 0;
}

Week::Week(int mileage)
{
    this->mileage = mileage;
}

int Week::getMileage()
{
    return mileage;
}