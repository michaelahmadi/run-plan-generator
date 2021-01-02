#include "runPlanGenerator.h"

Week::Week()
{
    mileage = 0;
}

Week::Week(int mileage)
{
    this->mileage = mileage;

    // Generate a week that has the given mileage using the following format:
    // Medium run 1
    // Medium Run 2
    // Easy Run 
    // Tempo or Speed Intervals Run
    // Easy Run
    // Long Run that is .30 * mileage
    // Recovery Day, 0 miles

}

int Week::getMileage()
{
    return mileage;
}