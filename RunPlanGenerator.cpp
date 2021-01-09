#include "RunPlanGenerator.h"

int main(int argc, char **argv)
{
    int startingMileage; // starting weekly mileage
    int goalMileage; // weekly mileage wanting to be achieved

    // a bit of command line input handling
    if(argc < 3) // not enough command line inputs
    {
        std::cout << "Correct Usage: ./runPlanGenerator [startingMileage] [goalMileage]\n";
        return 1;
    }
    startingMileage = std::stoi(argv[1]);
    goalMileage = std::stoi(argv[2]);
    if(startingMileage < 10 || goalMileage < 10)
    {
        std::cout << "Please input a starting mileage and goal mileage that are each at least 10 miles\n";
        return 1;
    }
    
    std::vector<Week> weeks; // Vector to hold each week generated
    int currentMileage = startingMileage; // Mileage of the week currently being generated
    int stepCounter = 0; // Tracks the number of increasing weeks in a row

    do
    {
        if(currentMileage < goalMileage)            // Push currentMileage, then increase or decrease currentMileage
            weeks.push_back(Week(currentMileage));
        else                                        // curr >= goal. Push goal mileage, then end.
        {
            weeks.push_back(Week(goalMileage));
            break;
        }

        // Increase or decrease mileage for the following week?
        if(stepCounter < 3) // Less than 3 increasing weeks in a row
        {
            currentMileage = currentMileage + (int) (0.1 * currentMileage); // increase next week's mileage by 10%
            stepCounter++;                                                  // increasing week, increment counter
        }
        else // 3 Steps up, now it's time for 1 step down
        {
            currentMileage = weeks[weeks.size() - 2].getMileage();  // Change mileage back to last week (before the one we just added)
            stepCounter = 0;                                        // decreasing week, reset counter
        }
    }
    while(true);

    // next, print out contents of the weeks vector a .txt file
    std::ofstream myFile;
    myFile.open("Running Plan.txt");
    int n = weeks.size();
    for(int i = 0; i < n; i++)
    {
        Week w = weeks[i];
        myFile << "Week: " << i << " | Mileage: " << w.getMileage() << std::endl;
        myFile << w.print() << std::endl;       
    }
    myFile.close();
    return 0;
}
