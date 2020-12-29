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
        std::cout << "Please input a weekly mileage that is greater than 10";
        return 0;
    }




}