#include <runPlanGenerator.h>

int main(int argc, char *argv[])
{
    int goalMileage;

    // a bit of command line input handling
    if (argc < 2) // goal mileage was not given in the command line
    {
        std::cout << "Correct Usage: ./runPlanGenerator [goalMileage]";
        return 0;
    }
    goalMileage = *argv[1];
    if(goalMileage < 10)
    {
        std::cout << "Please input a weekly mileage that is at least 10";
        return 0;
    }
    
    std::vector<Week> weeks; // Vector to hold each week generated
    int currentMileage = 10; // Mileage of the week currently being generated
    int stepCounter = 0; // Tracks the number of increasing weeks in a row

    do
    {
        if(currentMileage < goalMileage)
            weeks.push_back(Week(currentMileage));
        else
            weeks.push_back(Week(goalMileage));
        
        if(stepCounter < 4)
        {
            currentMileage = currentMileage + (0.1 * currentMileage); // increase next week's mileage by 10%
            stepCounter++; // increasing week, increment counter
        }
        else // 3 Steps up, now it's time for 1 step down
        {
            currentMileage = weeks[weeks.size() - 2].getMileage(); // Go back to last week (before the one we just added)
            stepCounter = 0;
        }
    }
    while(currentMileage <= goalMileage);

    // next, print out contents of the weeks vector a .txt file
}