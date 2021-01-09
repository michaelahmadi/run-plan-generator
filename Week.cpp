#include "RunPlanGenerator.h"

Week::Week()
{
    mileage = 0;
}

Week::Week(int mileage)
{
    this->mileage = mileage;

    // Generate a week that has the given mileage using the following format:
    // Medium run 1 (20%)
    // Medium Run 2 (20%)
    // Easy Run     (10%)
    // Tempo Run    (10%)
    // Easy Run     (10%)
    // Long Run     (30%)
    // Recovery Day  0 miles

    int mileageLeft = mileage;
    int medDist = (int) (0.2 * mileage);  // Medium Distance
    int easyDist = (int) (0.1 * mileage); // Easy/Tempo Distance
    int longDist = (int) (0.3 * mileage); // Long Distance

    // create the days
    Day med1 = Day("Medium", medDist);
    Day med2 = Day("Medium", medDist);
    Day easy1 = Day("Easy", easyDist);
    Day tempo = Day("Tempo", easyDist);
    Day easy2 = Day("Easy", easyDist);
    Day longR = Day("Long", longDist);
    Day recovery = Day("Recovery", 0);

    mileageLeft = mileageLeft - (2 * medDist) - (3 * easyDist) - longDist;
    // deal with the remaining miles that were cut off b/c of integer division
    float easyDistDecimal = (0.1 * mileage) - easyDist; // Easy/Tempo Distance Decimal Portion
    int turn = 0;
    if(easyDistDecimal >= 0.5) // if the easyDistDecimal >= 0.5, add miles to easy days then tempo
    {
        while(mileageLeft > 0)
        {
            if(turn == 0)
            {
                easy1.addMile();
                turn++;
            }
            else if(turn == 1)
            {
                easy2.addMile();
                turn++;
            }
            else
            {
                tempo.addMile();
                turn = 0;
            }
            mileageLeft--;
        }
    }
    else // if easyDistDecimal < 0.5, then add miles to medium days then easy days
    {
        while(mileageLeft > 0)
        {
            if(turn == 0)
            {
                med1.addMile();
                turn++;
            }
            else if(turn == 1)
            {
                med2.addMile();
                turn++;
            }
            else if(turn == 2)
            {
                easy1.addMile();
                turn++;
            }
            else if(turn == 3)
            {
                easy2.addMile();
                turn = 0;
            }
            mileageLeft--;
        }
    }
    // add days to week
    days.push_back(med1);
    days.push_back(med2);
    days.push_back(easy1);
    days.push_back(tempo);
    days.push_back(easy2);
    days.push_back(longR);
    days.push_back(recovery);

    /* // print
    std::cout << "Goal: " << mileage << " Plan: " <<  med1.getMiles() << " " << med2.getMiles() << " " <<
    easy1.getMiles() << " " << tempo.getMiles() << " " << easy2.getMiles() << " " << longR.getMiles() << "\n";
    */
}

int Week::getMileage()
{
    return mileage;
}

std::string Week::print()
{
    std::string daysInfo;
    for(Day d : days)
    {
        daysInfo = daysInfo + d.getRunType() + " " + std::to_string(d.getMiles()) + "\n"; // ex: "Easy 2\n"
    }
    return daysInfo;
}