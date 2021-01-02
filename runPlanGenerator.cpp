#include <runPlanGenerator.h>

int main(int argc, char *argv[])
{
    int startingMileage; // starting weekly mileage
    int goalMileage; // weekly mileage wanting to be achieved

    // a bit of command line input handling
    if(argc < 3) // goal mileage was not given in the command line
    {
        std::cout << "Correct Usage: ./runPlanGenerator [startingMileage] [goalMileage]";
        return 0;
    }
    startingMileage = *argv[1];
    goalMileage = *argv[2];
    if(startingMileage < 10 || goalMileage < 10)
    {
        std::cout << "Please input a starting mileage and goal mileage that are each at least 10 miles";
        return 0;
    }
    
    std::vector<Week> weeks; // Vector to hold each week generated
    int currentMileage = startingMileage; // Mileage of the week currently being generated
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